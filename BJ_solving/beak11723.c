#include <stdio.h>
#include <string.h>



int main(){
    int m, x;
    int s[20] = {0,};
    char order[10];

    scanf("%d", &m);

    for(int i=0; i<m; i++){
        scanf("%s %d", &order, &x);

        if(strcmp(order, "add") == 0) s[x-1] = 1;

        if(strcmp(order, "remove") == 0) s[x-1] = 0;

        if(strcmp(order, "check") == 0){
            if (s[x-1] == 1) printf("%d\n", 1);
            else printf("%d\n", 0);
        }

        if(strcmp(order, "toggle") == 0) s[x-1] = !s[x-1];

        if(strcmp(order, "all") == 0) for(int i=0; i<21; i++) s[i] = 1;

        if(strcmp(order, "empty") == 0) for(int i=0; i<21; i++) s[i] = 0;
    }

}
