#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, K, temp, count;
    int* A;

    count = 0;

    scanf("%d %d", &N, &K);

    A = malloc(sizeof(int)*N);
    temp = K;

    for(int i=0; i<N; i++) scanf("%d", &A[i]);

    for(int i=N-1; i>=0; i--){

        if(A[i] <= K){
            count = count + temp/A[i];
            temp = temp%A[i];
        }

    }

    printf("%d", count);

    free(A);

}
