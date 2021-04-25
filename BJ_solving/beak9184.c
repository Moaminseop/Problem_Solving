#include <stdio.h>

int w[100][100][100] = {0};

int function(int a, int b, int c){


    if(a>20 || b>20 || c>20){
        return function(20, 20, 20);
    }

    if(a <= 0 || b <= 0 || c <= 0 ){  // �ݷ� 21 -2 -2 �� �ϸ� 1�̳��;ߵǴµ� 10480000 �̷����� ���´�. �� ������ �߿��ϴ�.
        return 1;
    }

    if(w[a][b][c] != 0){
        return w[a][b][c];
    }

    if(a<b && b<c){
        return w[a][b][c] = function(a,b,c-1) + function(a, b-1, c-1) - function(a, b-1, c);
    }

    else {
        return w[a][b][c] = function(a-1,b,c) + function(a-1, b-1, c) + function(a-1, b, c-1) - function(a-1,b-1,c-1);
    }


}

int main(){

    int a, b, c;

    while(1){

        scanf("%d %d %d", &a, &b, &c);

        if(a == -1 && b == -1 && c == -1){
            break;
        }

        printf("w(%d, %d, %d) = %d\n", a, b, c, function(a,b,c));
    }

    return 0;

}
