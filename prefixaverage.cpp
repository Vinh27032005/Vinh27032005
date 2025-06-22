#include"stdio.h"
void average(int A[], int n,double X[]){
    double sum = 0;
    for(int i=0; i<n; i++){
        sum += A[i];
        X[i] = sum / (i+1);
        
    }
}
void averagehelper(int *A, int n, double *X, int i, int sum){
    if(i==n) return;
    sum += A[i];
    X[i] = (double)sum / (i+1);
    averagehelper(A,n,X,i+1,sum);
}
void average(int *A, int n, double *X){
    averagehelper(A,n,X,0,0);
}
