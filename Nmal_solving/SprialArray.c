#include <stdio.h>
#include <stdlib.h>

int i, j; // �������� i j �����Ѵ�.
int** arr; // ���� ����������int arr �����Ѵ�. << 2�����迭�� ��������� ���.

int a = 0; // �������� a=0 ���� ������ش�.

void spiral(int n, int m, int k){ // �迭�� ȸ���� �ִ� �Լ� spiral�� �����. >> n�� ��, m�� ��, k�� ��ġ����Ʈ.

    if(m < 1 || n < 1){  // �� or ���� 1�̸��� �Ǹ� �Լ� ����.
        return;
    }

    for(i=0; i<m; i++){ // ���η� �ø��鼭 �迭.
        arr[k][k+i] = a;
        a += 1;
    }

    if(n == 1){ // ���� 1�̸� �Լ�����
        return;
    }

    for(i=0; i<n-1; i++){ // ���η� �ø��鼭 �迭
        arr[i+1+k][m-1+k] = a;
         a += 1;
    }

    if(m == 1){ // ���� 1�̸� �Լ�����
        return;
    }

    for(i=0; i<m-1; i++){ // ���η� ���̸鼭 �迭
        arr[n-1+k][m-2+k-i] = a;
         a += 1;
    }

    for(i=0; i<n-2; i++){ // ���η� ���̸鼭 �迭
        arr[n-2+k-i][k] = a;
        a += 1;
    }

    spiral(n-2, m-2, k+1); // ��� ���� 2���̰� ��ġ����Ʈ�� 1 �ø� �� �ڱ��ڽ��� ȣ��

}

int main(){

    int n, m, k;

    k = 0;

    scanf("%d %d", &n, &m);

    arr = (int**)calloc(n, sizeof(int*));  // ** �����Ҵ�

    arr[0] = (int*)calloc(n*m, sizeof(int)); // * �����Ҵ�

    for(i=1; i<n; i++){ // 2���� �迭�� �����.
        arr[i] = arr[i-1]+m;
    }

    spiral(n, m, k); // spiral�Լ� ȣ��

    for(i=0; i<n; i++){ // ������� �迭�� ����Ѵ�.
        for(j=0; j<m; j++){
            printf("%d    ", arr[i][j]);
        }
        printf("\n");
     }

    free(arr); // �����Ҵ����� �迭�� �����Ѵ�.
    free(arr[0]);

}
