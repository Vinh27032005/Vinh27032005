#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key,val;
    struct Node* next;
}Node;
typedef struct Node* Bucket;

typedef struct{
    int cap;
    Bucket* A;
}HashTable;

void makeNull(HashTable* pH, int n){
    pH->cap = n;
    pH->A = (struct Node**)malloc(sizeof(struct Node*)*n);
    for(int i = 0 ;i<n;i++){
        pH->A[i]=NULL;
    }
}

int hash(int key, int cap){
    unsigned int x = (unsigned int)key;
    // Áp d?ng thu?t toán hash nhân (Knuth’s multiplicative method)
    x *= 2654435761u;  // h?ng s? vàng
    return x % cap;
}


void add(HashTable* pH, int key, int val){
    int index = hash(key,pH->cap);
    Bucket a = pH->A[index];
    while(a){
        if(a->key==key){
            a->val = val;
            return;
        }
        a = a->next;
    }
    Bucket b = (struct Node*)malloc(sizeof(struct Node));
    b->key = key;
    b->val = val;
    b->next = pH->A[index];
    pH->A[index]=b;
    
}

int get(HashTable* pH, int key){
    int index = hash(key,pH->cap);
    if(pH->A[index]==NULL){
        return -1;
    }else{
        Bucket a = pH->A[index];
        while(a){
            if(a->key==key){
                return a->val;
            }
            a=a->next;
        }
        return -1;
    }
}

void Hashremove(HashTable* pH, int key){
    int index = hash(key,pH->cap);
    if(pH->A[index]==NULL){
        return;
    }else{
        Bucket prev = pH->A[index];
        if(prev->key==key){
            Bucket holder = pH->A[index];
            pH->A[index]=pH->A[index]->next;
            free(holder);
        }else{
            Bucket curr = pH->A[index];
            while(curr){
                if(curr->key==key){
                    prev->next=curr->next;
                    free(curr);
                    break;
                }else{
                    prev=curr;
                    curr=curr->next;
                }
            }
        }
        
    }
}





void binarySearch(int* arr, int n, int x){
    int left = 0;
    int right = n-1;
    
    while (left<=right){
        int mid = (right+left)/2;
        if(arr[mid]<x){
          left = mid+1;  
        }
        else if(arr[mid]>x){
            right = mid-1;
        }else{
            printf("YES ");
            return;
        }
    }
    printf("NO ");
    return;
}



int main(){
    
    HashTable H;
    makeNull(&H, 2027);
    int a,q;
    scanf("%d %d",&a,&q);
    //int* arr = (int*)malloc(sizeof(int)*a);
    for(int i = 0 ;i<a;i++){
        int val;
        scanf("%d",&val);
        add(&H, val, i);
    }
    
    int* qrr = (int*)malloc(sizeof(int)*q);
    for(int i = 0;i<q;i++){
        scanf("%d",&qrr[i]);
    }
    for(int i=0;i<q;i++){
        if(get(&H, qrr[i])!=-1){
            printf("YES ");
        }else{
            printf("NO ");
        }
    }
}
