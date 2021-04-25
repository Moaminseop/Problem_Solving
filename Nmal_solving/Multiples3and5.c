#include <stdio.h>


int main(void) {

    int i, sum1, sum2, sum3, rel;

    sum1 = 0;
    sum2 = 0;
    sum3 = 0;
    rel = 0;

    for (i=1; i<=999; i++){
        if (i%3 == 0) {
            sum1 = sum1 + i;
        }
    }

    for (i=1; i<=999; i++){
        if (i%5 == 0) {
            sum2 = sum2 + i;
        }
    }

    for (i=1; i<=999; i++){
        if (i%15 == 0) {
            sum3 = sum3 + i;
        }
    }

    rel = sum1 + sum2 - sum3;

    printf("%d\n", sum1);
    printf("%d\n", sum2);
    printf("%d", sum3);
    printf("%d", rel);

}


/*
#include <stdio.h>

int main(void)

{

    int i = 0, sum = 0;

    for (i = 0; i < 1000; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }

    printf("총합은 %d 입니다\n", sum);

    return 0;

}
*/
