#include <stdio.h>
#include <stdlib.h>

int areFriends[10][10];
int n;


int countPairs(int taken[10]) {

    int firstFree = -1;

    for (int i = 0; i < n; i++) {
        if (!taken[i]) {
            firstFree = i;
            break;
        }
    }

    if (firstFree == -1) return 1;

    int ret = 0;

    for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
        if ((!taken[pairWith]) && areFriends[firstFree][pairWith]) {
            taken[firstFree] = taken[pairWith] = 1;
            ret += countPairs(taken);
            taken[firstFree] = taken[pairWith] = 0;
        }

    }

    return ret;

}

int main() {
    int C, m;
    int friendNum1, friendNum2;
    int ret;
    int taken[10] = { 0, };

    scanf_s("%d", &C);

    for (int i = 0; i < C; i++) {

        scanf_s("%d", &n);
        scanf_s("%d", &m);

        for (int j = 0; j < m; j++) {
            scanf_s("%d %d", &friendNum1, &friendNum2);
            areFriends[friendNum1][friendNum2] = 1;
            areFriends[friendNum2][friendNum1] = 1;
        }

        ret = countPairs(taken);

        for (int k = 0; k < 11; k++) {
            for (int j = 0; j < 11; j++) {
                areFriends[i][j] = 0;
            }
        }

        n = 0;

        printf("%d\n", ret);
    }
}
