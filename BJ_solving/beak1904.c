#include <stdio.h>
#include <stdlib.h>

int func(int N, int* A){  // top-down << 재귀호출이 되서 메모리를 많이 먹는다.

    if(N == 1) return A[0] = 1;

    if(N == 2) return A[1] = 2;

    else{

        A[0] = 1;
        A[1] = 2;

        if(A[N-1] != 0) return A[N-1];

        else return A[N-1] = (func(N-1, A)+ func(N-2, A)) % 15746;
    }
}

int main(){

    int N;
    int* A;

    scanf("%d", &N);

    A = calloc(N, sizeof(int));

    func(N, A);

    printf("%d\n", A[N-1]);

    free(A);
}

// 동적할당 받아서 쫙 정렬했는데 더 괜찮게 푸는 방법도 막 보임
/*
#include <stdio.h>   << 이런식으로 되게 깔끔하게 품 // bottom-up
int main(){
	int N, dp[2] = {1, 2}, temp;
	scanf("%d", &N);
    if(N == 1){
        printf("%d", 1);
        return 0;
    }
	for(int i = 3; i <= N; i++){
		temp = dp[0];
		dp[0] = dp[1];
		dp[1] = (temp + dp[1]) % 15746;
	}
	printf("%d", dp[1]);
}
*/
