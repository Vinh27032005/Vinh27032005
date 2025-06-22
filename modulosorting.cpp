#include <stdio.h>

#include <stdlib.h>



typedef struct {

    int value;

    int index; // v? trí ban d?u

} Element;



void merge(Element arr[], int left, int mid, int right, int k) {

    int n1 = mid - left + 1;

    int n2 = right - mid;



    Element *L = (Element*)malloc(n1 * sizeof(Element));

    Element *R = (Element*)malloc(n2 * sizeof(Element));



    for (int i = 0; i < n1; i++) L[i] = arr[left + i];

    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];



    int i = 0, j = 0, t = left;



    while (i < n1 && j < n2) {

        int modL = L[i].value % k;

        int modR = R[j].value % k;



        if (modL < modR || (modL == modR && L[i].index < R[j].index)) {

            arr[t++] = L[i++];

        } else {

            arr[t++] = R[j++];

        }

    }



    while (i < n1) arr[t++] = L[i++];

    while (j < n2) arr[t++] = R[j++];



    free(L);

    free(R);

}



void mergeSort(Element arr[], int left, int right, int k) {

    if (left < right) {

        int mid = (left + right) / 2;

        mergeSort(arr, left, mid, k);

        mergeSort(arr, mid + 1, right, k);

        merge(arr, left, mid, right, k);

    }

}



int main() {

    int n, k;

    scanf("%d %d", &n, &k);



    Element *arr = (Element*) malloc(n * sizeof(Element));

    for (int i = 0; i < n; i++) {

        scanf("%d", &arr[i].value);

        arr[i].index = i;

    }



    mergeSort(arr, 0, n - 1, k);



    for (int i = 0; i < n; i++) {

        printf("%d ", arr[i].value);

    }

    printf("\n");



    free(arr);

    return 0;

}

/*

void insertionSort(int *a,int n, int k){

 for (int i=0; i<n; i++){

  int tmp = a[i];

  int j = i;

  while (j > 0 && (

    (tmp % k < a[j - 1] % k) ||

    ((tmp % k == a[j - 1] % k) && j - 1 > i) ))

{

   a[j] = a[j-1];

   j--;

  }

  a[j] = tmp;

 }

}

int main(){

 int n, k;

 scanf("%d %d", &n, &k);

 int a[n];

 for (int i=0; i<n; i++)

  scanf("%d", &a[i]);

 insertionSort(a,n,k);

 for(int i=0; i<n; i++)

  printf("%d ", a[i]);

}*/

