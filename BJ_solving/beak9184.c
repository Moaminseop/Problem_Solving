#include <stdio.h>

int w[100][100][100] = {0};

int function(int a, int b, int c){


    if(a>20 || b>20 || c>20){
        return function(20, 20, 20);
    }

    if(a <= 0 || b <= 0 || c <= 0 ){  // 반례 21 -2 -2 를 하면 1이나와야되는데 10480000 이런값이 나온다. 즉 순서가 중요하다.
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
