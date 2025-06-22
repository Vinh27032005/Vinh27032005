int countSwap(int A[], int n, int x){
    for(int i=0;i<n;i++){
        int tmp = A[i];
        int j=i;
        int count = 0;
        while(j>0 && tmp < A[j-1]){
            A[j] = A[j-1];
            j--;
            count ++;
        }
        A[j] = tmp;
        if(i == x-1) return count + 1;
    }
}
int main(){
    int n,s;
    scanf("%d %d",&n,&s);
    int A[n];
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    printf("%d",countSwap(A,n,s));
    
}
