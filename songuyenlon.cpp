#include"stdio.h"
void moveDisk(char i, char k){
    printf("%c -> %c\n",i,k);
}
void thapHanoi(int n, char i, char j, char k){
    if(n==1){ 
    moveDisk(i,k);
    return;
    }
    thapHanoi(n-1,i,k,j);
    moveDisk(i,k);
    thapHanoi(n-1,j,i,k);
}
int main(){
    int n;
    scanf("%d",&n);
    thapHanoi(n,'A','B','C');
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <string.h>

typedef double complex cplx;

const double PI = acos(-1);

// Hàm FFT
void fft(cplx *a, int n, int invert) {
    int i, j;
    // Bit-reversal permutation
    for (i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (j & bit) {
            j ^= bit;
            bit >>= 1;
        }
        j |= bit;

        if (i < j) {
            cplx tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }

    // FFT chính
    for (int len = 2; len <= n; len <<= 1) {
        double angle = 2 * PI / len * (invert ? -1 : 1);
        cplx wlen = cos(angle) + sin(angle) * I;
        for (i = 0; i < n; i += len) {
            cplx w = 1 + 0.0 * I;
            for (j = 0; j < len / 2; j++) {
                cplx u = a[i + j];
                cplx v = a[i + j + len/2] * w;
                a[i + j] = u + v;
                a[i + j + len/2] = u - v;
                w *= wlen;
            }
        }
    }

    // N?u là FFT ngu?c thì chia cho n
    if (invert) {
        for (i = 0; i < n; i++) {
            a[i] /= n;
        }
    }
}

// Hàm nhân 2 s? l?n v?i FFT
void multiplyFFT(int *a, int sizeA, int *b, int sizeB, int **res, int *sizeRes) {
    int n = 1;
    while (n < sizeA + sizeB) n <<= 1;

    cplx *fa = (cplx*)calloc(n, sizeof(cplx));
    cplx *fb = (cplx*)calloc(n, sizeof(cplx));

    for (int i = 0; i < sizeA; i++)
        fa[i] = a[i];
    for (int i = 0; i < sizeB; i++)
        fb[i] = b[i];

    fft(fa, n, 0);
    fft(fb, n, 0);

    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];

    fft(fa, n, 1);

    int *result = (int*)calloc(n, sizeof(int));
    long long carry = 0;
    for (int i = 0; i < n; i++) {
        long long val = (long long)(creal(fa[i]) + 0.5) + carry;
        carry = val / 10;
        result[i] = val % 10;
    }

    // Lo?i b? s? 0 ? d?u
    int length = n;
    while (length > 1 && result[length - 1] == 0) length--;

    *res = result;
    *sizeRes = length;

    free(fa);
    free(fb);
}

int main() {
    char s1[50001], s2[50001];
    scanf("%s %s", s1, s2);

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int *a = (int*)malloc(len1 * sizeof(int));
    int *b = (int*)malloc(len2 * sizeof(int));

    for (int i = 0; i < len1; i++)
        a[i] = s1[len1 - 1 - i] - '0';

    for (int i = 0; i < len2; i++)
        b[i] = s2[len2 - 1 - i] - '0';

    int *res;
    int sizeRes;

    multiplyFFT(a, len1, b, len2, &res, &sizeRes);

    for (int i = sizeRes - 1; i >= 0; i--)
        printf("%d", res[i]);
    printf("\n");

    free(a);
    free(b);
    free(res);

    return 0;
}
