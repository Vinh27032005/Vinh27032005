void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int partition(int* A,int start, int end){
    int pivot = A[start];
    int i = start + 1;
    int j = start + 1;
    while(j<=end){
        if(A[j] < pivot){
            swap(&A[i],&A[j]);
            i++;
        }
        j++;
    }
    swap(&A[i-1],&A[start]);
    return i - 1;
}
void quicksort(int* A, int start, int end){
    if(start > end) return;
    int pos = partition(A,start,end);
    quicksort(A,start,pos-1);
    quicksort(A,pos+1,end);
}
void sort(int *A,int n){
    quicksort(A,0,n-1);
}


