#include <stdio.h>

int main(void) {

    int i, cont, a, b, c, d;

    cont = 0;

    for(a=0; a<=9; a++){
        for(b=0; b<=9; b++){
            for(c=0; c<=9; c++){
                for(d=0; d<=9; d++){
                    if(d == 8){
                        cont += 1;
                    }

                    if(c == 8){
                        cont += 1;
                    }

                    if(b == 8){
                        cont += 1;
                    }

                    if(a == 8){
                        cont += 1;
                    }

                }
            }
        }
    }

    printf("%d", cont);

}
