#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *arr;

void delete(int idx)

{
     memmove(arr+idx,arr+idx+1,(4999-idx)*sizeof(int)); // arr[idx+1] ���� arr[4999] ���� arr[idx]�� �����.
}

int main(void) {

    int i, rel, a, b, c, d, sum;

    arr = (int*)malloc(sizeof(int)*5000); // �迭 �����Ҵ�.

    for(i=0; i<4999; i++){  // �迭�� �� ����ֱ�
        arr[i] = i+1;
    }

    for(a=0; a<=4; a++){
        for(b=0; b<=9; b++){
            for(c=0; c<=9; c++){
                for(d=0; d<=9; d++){
                    rel = a+b+c+d+a*1000+b*100+c*10+d;  // ���׷������� ����

                    for(i=0; i<5000; i++){  // ���׷������� ���� �迭���� ���ش�.
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
            sum = sum + arr[i];  // ���� �ѹ��� ���� �迭�� �� �����ش�.
    }

    printf("%d", sum); // �������
	
    free(arr);
}
