#include <stdio.h>
#include <stdlib.h>

int i, j; // 전역변수 i j 선언한다.
int** arr; // 전역 이중포인터int arr 선언한다. << 2차원배열을 만들기위해 사용.

int a = 0; // 전역변수 a=0 으로 만들어준다.

void spiral(int n, int m, int k){ // 배열에 회전을 주는 함수 spiral을 만든다. >> n은 행, m은 열, k는 위치포인트.

    if(m < 1 || n < 1){  // 행 or 열이 1미만이 되면 함수 종료.
        return;
    }

    for(i=0; i<m; i++){ // 가로로 늘리면서 배열.
        arr[k][k+i] = a;
        a += 1;
    }

    if(n == 1){ // 행이 1이면 함수종료
        return;
    }

    for(i=0; i<n-1; i++){ // 세로로 늘리면서 배열
        arr[i+1+k][m-1+k] = a;
         a += 1;
    }

    if(m == 1){ // 열이 1이면 함수종료
        return;
    }

    for(i=0; i<m-1; i++){ // 가로로 줄이면서 배열
        arr[n-1+k][m-2+k-i] = a;
         a += 1;
    }

    for(i=0; i<n-2; i++){ // 세로로 줄이면서 배열
        arr[n-2+k-i][k] = a;
        a += 1;
    }

    spiral(n-2, m-2, k+1); // 행과 열을 2줄이고 위치포인트를 1 늘린 뒤 자기자신을 호출

}

int main(){

    int n, m, k;

    k = 0;

    scanf("%d %d", &n, &m);

    arr = (int**)calloc(n, sizeof(int*));  // ** 동적할당

    arr[0] = (int*)calloc(n*m, sizeof(int)); // * 동적할당

    for(i=1; i<n; i++){ // 2차원 배열을 만든다.
        arr[i] = arr[i-1]+m;
    }

    spiral(n, m, k); // spiral함수 호출

    for(i=0; i<n; i++){ // 만들어진 배열을 출력한다.
        for(j=0; j<m; j++){
            printf("%d    ", arr[i][j]);
        }
        printf("\n");
     }

    free(arr); // 동적할당해준 배열을 해제한다.
    free(arr[0]);

}
