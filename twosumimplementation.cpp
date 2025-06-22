#include "stdio.h"
int main(){
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;++i){
        scanf("%d",&A[i]);
    }
    int target;
    scanf("%d",&target);
    for(int i=0;i<n;++i){
        for(int j = i + 1;j<n;++j){
            if(A[i] + A[j] == target) {printf("YES\n");
            return 0;}
        }
    }
    printf("NO");
    return 0;
}
