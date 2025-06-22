#include <stdio.h>



#define MAXSIZE 100005



typedef struct {

    int elements[MAXSIZE];

    int size;

} PriorityQueue;



void makenull(PriorityQueue *pQ) {

    pQ->size = 0;

}



void swap(int *a, int *b) {

    int tmp = *a;

    *a = *b;

    *b = tmp;

}



int left(int i) {

    return 2 * i + 1;

}



int right(int i) {

    return 2 * i + 2;

}



int parent(int i) {

    return (i - 1) / 2;

}



void max_heapify(PriorityQueue *pQ, int i) {

    int l = left(i);

    int r = right(i);

    int largest;



    if (l < pQ->size && pQ->elements[l] > pQ->elements[i])

        largest = l;

    else

        largest = i;



    if (r < pQ->size && pQ->elements[r] > pQ->elements[largest])

        largest = r;



    if (largest != i) {

        swap(&pQ->elements[i], &pQ->elements[largest]);

        max_heapify(pQ, largest);

    }

}



void insert(PriorityQueue *q, int x) {

    q->size += 1;

    int i = q->size - 1;

    q->elements[i] = x;



    while (i > 0 && q->elements[i] > q->elements[parent(i)]) {

        swap(&q->elements[i], &q->elements[parent(i)]);

        i = parent(i);

    }

}



int get_max(PriorityQueue *q) {

    if (q->size == 0) return -2147483648; // ho?c báo l?i

    return q->elements[0];

}

int extract_max(PriorityQueue *q) {

    if (q->size == 0) return -2147483648; // ho?c x? lý l?i tùy b?n



    int max_val = q->elements[0];  // l?y ph?n t? l?n nh?t ? root

    q->elements[0] = q->elements[q->size - 1];  // dua ph?n t? cu?i lên d?u

    q->size--;  // gi?m size

    max_heapify(q, 0);  // dua heap tr? l?i tr?ng thái h?p l?



    return max_val;

}





int main() {

    PriorityQueue q;

    makenull(&q);



    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        int x;

        scanf("%d", &x);

        insert(&q, x);

    }



    int t;

    scanf("%d", &t);

    while (t--) {

        int type;

        scanf("%d", &type);

        if (type == 1) {

            int x;

            scanf("%d", &x);

            insert(&q, x);

        } else if (type == 2) {

            printf("%d\n", get_max(&q));

        }

    }



    return 0;

}

