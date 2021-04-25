#include <stdio.h>
#include <stdlib.h>

int max,min,maxloc,minloc;

int myatoi(char str[])
{
    int i = 0;
    int num = 0;

    for (i=0 ; str[i] != 0x00; i++)
    {
        if(str[i] == 0x3A){
            continue;
        }
        num = num * 10;
        num = num + (str[i] - 0x30);
    }
    return num;
}

int array_max(int a[], int size){

    max = a[0];
		maxloc = 0;

    for(int i=1; i<size; i++){
        if(a[i]>max){
            max=a[i];
						maxloc = i;
        }
    }
    return 0;
}

int array_min(int a[], int size){

    min = a[0];
		minloc = 0;

    for(int i=1; i<size; i++){
        if(a[i]<min){
            min=a[i];
						minloc = i;
        }
    }
    return 0;
}

int main() {
	int i,N;
	int* Stime;
	int* Etime;
	char** St;
	char** Et;

	scanf("%d", &N);

	St = (char**)malloc(sizeof(char)*N);
	Et = (char**)malloc(sizeof(char)*N);
	St[0] = (char*)malloc(sizeof(char)*10*N);
	Et[0] = (char*)malloc(sizeof(char)*10*N);
	Stime = (int*)malloc(sizeof(int)*N);
	Etime = (int*)malloc(sizeof(int)*N);

	for(i=1; i<N; i++){
		St[i] = St[i-1]+10;
		Et[i] = Et[i-1]+10;
	}

	for(i=0; i<N; i++){
		scanf("%s ~ %s",St[i], Et[i]);
	}

	for(i=0; i<N; i++){
		Stime[i] = myatoi(St[i]);
		Etime[i] = myatoi(Et[i]);
	}

	array_max(Stime, N);
	array_min(Etime, N);

	if(max > min){
		printf("%d", -1);
	}
	else {
		printf("%s ~", St[maxloc]);
		printf(" %s", Et[minloc]);
	}

	free(Etime);
	free(Stime);
	free(Et[0]);
	free(St[0]);
	free(Et);
	free(St);

	return 0;
}

