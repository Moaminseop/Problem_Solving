#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *arr;

void delete(int idx)

{
     memmove(arr+idx,arr+idx+1,(4999-idx)*sizeof(int)); // arr[idx+1] 부터 arr[4999] 까지 arr[idx]로 덮어쓴다.
}

int main(void) {

    int i, rel, a, b, c, d, sum;

    arr = (int*)malloc(sizeof(int)*5000); // 배열 동적할당.

    for(i=0; i<4999; i++){  // 배열에 값 집어넣기
        arr[i] = i+1;
    }

    for(a=0; a<=4; a++){
        for(b=0; b<=9; b++){
            for(c=0; c<=9; c++){
                for(d=0; d<=9; d++){
                    rel = a+b+c+d+a*1000+b*100+c*10+d;  // 제네레이터인 값들

                    for(i=0; i<5000; i++){  // 제네레이터인 값을 배열에서 빼준다.
                        if(arr[i] == rel) {
                            delete(i);

                        }
                    }
                }
            }
        }
    }

    sum = 0;
    for(i=0; i<4999; i++){
            sum = sum + arr[i];  // 셀프 넘버만 남은 배열을 다 더해준다.
    }

    printf("%d", sum); // 결과도출
	
    free(arr);
}
