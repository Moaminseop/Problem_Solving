#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE 1 << 20

/*  내가 원래 짯던 코드.
int compare(const void *a, const void *b)
{   // 출처 : 코딩도장.
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;

    if (num1 > num2)
        return 1;

    return 0;
}

int main(){
    int N, M, order, a, b, x, count, temp;
    int* train;

    scanf("%d %d", &N, &M);

    train = calloc(N, sizeof(int));

    for(int i=0; i<M; i++){
        scanf("%d %d", &order, &a);

        if(order < 3){
            scanf("%d", &x);
        }

        b = 1;

        switch(order){
        case 1:
            if( (train[a-1] & (b << (x-1)) ) == 0) train[a-1] += (b << (x-1));
            break;
        case 2:
            if( (train[a-1] & (b << (x-1)) ) == (b << (x-1)) ) train[a-1] -= (b << (x-1));
            break;
        case 3:
            if((train[a-1] << 1) >= MAX_LINE) {
                    train[a-1] <<= 1;
                    train[a-1] -= MAX_LINE;
                    //train[a-1] = ((train[a-1] << 1) - MAX_LINE);  << 왜 안되지?
            }
            else train[a-1] <<= 1;
            break;
        case 4:
            train[a-1] >>= 1;
            break;
        }
    }

    qsort(train, N, sizeof(int), compare);

    count = 1;
    temp = train[0];

    for(int i=0; i<N; i++){
        if(train[i] != temp){
            temp = train[i];
            count += 1;
        }
    }

    printf("%d", count);

    free(train);
}
*/

int main(){
    int N, M, order, a, b, x, count;
    int* train;
    char pass[1<<20] = {0,};

    scanf("%d %d", &N, &M);

    train = calloc(N, sizeof(int));

    for(int i=0; i<M; i++){
        scanf("%d %d", &order, &a);

        if(order < 3){
            scanf("%d", &x);
        }

        b = 1;

        switch(order){
        case 1:
            if( (train[a-1] & (b << (x-1)) ) == 0) train[a-1] += (b << (x-1));
            break;
        case 2:
            if( (train[a-1] & (b << (x-1)) ) == (b << (x-1)) ) train[a-1] -= (b << (x-1));
            break;
        case 3:
            if((train[a-1] << 1) >= MAX_LINE) {
                    train[a-1] <<= 1;
                    train[a-1] -= MAX_LINE;
                    //train[a-1] = ((train[a-1] << 1) - MAX_LINE);  << 왜 안되지?
            }
            else train[a-1] <<= 1;
            break;
        case 4:
            train[a-1] >>= 1;
            break;
        }
    }

    count = 0;

    for(int i=0; i<N; i++){
        if(pass[train[i]] != 1){
        pass[train[i]] = 1;
        count += pass[train[i]];
        }
    }

    printf("%d", count);
    free(train);
}


/*
#include <stdio.h>
#define MASK 0x0fffff

int tr[100000];
char v[1<<20];

int main() {
	int n, m, c, i, x;
	scanf("%d%d", &n, &m);
	while (m-->0) {
		scanf("%d%d", &c, &i), i--;
		if (c <= 2) scanf("%d", &x), x--;
		if (c == 1) tr[i] |= 1<<x;
		else if (c == 2) tr[i] &= ~(1<<x);
		else if (c == 3) tr[i] <<= 1;
		else tr[i] >>= 1;
		tr[i] &= MASK;
	}
	m = 0;
	for (i = 0 ; i < n ; i++) m += !v[tr[i]], v[tr[i]] = 1; << 이해불가
	printf("%d", m);
}

*/
