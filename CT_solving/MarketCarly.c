#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a, i, route, count;


void GetCharCount1(char a[]){
    count = 0;

    for(i=0; a[i] != NULL; i++){
        if(a[i]=='1') count++;
    }
}

void GetCharCount0(char a[]){
    count = 0;

    for(int i=0; a[i] != NULL; i++){
        if(a[i]=='0') count++;
    }
}

int RouteCount(int a){

    if(a==1 || a==2){
        route = 1;
        return 1;
    }

    else{
        route = RouteCount(a-1) + RouteCount(a-2);
    }

}

int main(){
    int N, roof, sum;
    int* arr;
    char* R;
    char* ptr;

    scanf("%d", &N);

    R = (char*)malloc(sizeof(char)*N);

    scanf("%s", R);

    GetCharCount0(R);

    arr = (int*)malloc(sizeof(int)*count);

    ptr = strtok(R,"0");
    roof = 0;

    while(ptr != NULL){

        GetCharCount1(ptr);
        RouteCount(count);
        arr[roof] = route;
        ptr = strtok(NULL,"0");

        roof++;
    }

    sum = 1;

    for(i=0; i<roof; i++){
         sum = sum*arr[i];
    }

    printf("%d", sum);

    free(arr);
    free(R);
}

//피보나치 수열 for문으로 썻으면 더 괜찮았을듯. 재귀함수 말고 ㅠㅠ
