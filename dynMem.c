#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

int i;

int main() {
	printf("Hello World\n");
	int *arr;
	arr = (int *)calloc(2,sizeof(int));
	int *ptr;
	ptr = (int *)malloc(5*sizeof(int));
	for(i=0;i<4;i++){
		const int a = 257;
		memcpy(ptr,&a,1);
		printf("pointer at 0x%p is %d test %s\n",ptr,*ptr,"test");
	}
	free(ptr);
	free(arr);
	return 0;
}
