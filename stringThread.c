#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct {
	char *string1;
	char *string2;
} strings;

pthread_t tid[2];
int counter;
pthread_mutex_t lock;

void* jobs(void *arg){
	pthread_mutex_lock(&lock);
	strings *myStrings = (strings *)arg;
	unsigned long a = 0;
	counter += 1;
	printf("\n Job %d has started\n",counter);
	//for task
	for(a=0;a<5;a++){
		strcat(myStrings->string1,myStrings->string2);
		printf("%s\n%d\n",myStrings->string1,strlen(myStrings->string1));
	}
	printf("Hello %d",counter);
	printf("\n Job %d has finished\n",counter);
	pthread_mutex_unlock(&lock);
	return NULL;
}

int main() {
	//printf("Hello world!\n");
	strings myStrings;
	strings myStrings2;
	char string1[16384] = "Hello World,";
	char string2[16384] = " Goodbye";
	char string3[16384] = "Pizza";
	char string4[16384] = " Mozzarella";
	//char string3[4] = ", ";
	myStrings.string1 = string1;
	myStrings.string2 = string2;
	myStrings2.string1 = string3;
	myStrings2.string2 = string4;
	int a = 0;
	int error;
	if(pthread_mutex_init(&lock,NULL) != 0){
		printf("\n mutex init has failed\n");
	}
	
	while(a<2){
		strings *pass = !(a & 1) ? &myStrings : &myStrings2;

		//strings *pass;
		//if(!(a&1)) pass = &myStrings;
		//else pass = &myStrings2;
		error = pthread_create(&(tid[a]),NULL,&jobs,pass);
		if(error != 0){
			printf("\nThread can't be created : [%s]",strerror(error));
		}
		a++;
	}
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	pthread_mutex_destroy(&lock);
	
	return 0;
}
