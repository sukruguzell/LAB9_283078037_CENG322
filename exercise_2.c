#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define NUM_OF_THREADS 4
typedef struct string {
char original[MAX];
char reverse[MAX];
}structure;
structure p1[4];

int k=0;
void *reverse_str (void *thid){
int *id=(int *) thid;
int j;
printf("Thread ID:%d\n",*id);
int n=strlen(p1[k].original);
for(int g = n - 1; g >= 0; g--) {
        p1[k].reverse[j++]=p1[k].original[g];
    }
printf("New: %s\n",p1[k].reverse);
k++;
}

int main(){



printf("Enter the line  \n");
scanf(" %s",p1[0].original);
scanf(" %s",p1[1].original);
scanf(" %s",p1[2].original);
scanf(" %s",p1[3].original);

pthread_t tid[4];
int thread_no[4];
int i=0;
for(i=0; i<NUM_OF_THREADS; i++)
	{
		thread_no[i] = i;
		pthread_create(&tid[i], NULL, reverse_str, &p1[i]);
		
			
	}
 
for(i=0; i<NUM_OF_THREADS; i++)
	{
		pthread_join(tid[i], NULL);
	}

pthread_exit(NULL);
}
