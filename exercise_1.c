#include <stdio.h>

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>

int balance=1000;
pthread_mutex_t lock;
void *depositmoney (void *thid){
pthread_mutex_lock(&lock);
for(int i=0;i<500;i++){
balance=balance+10;
}
pthread_mutex_unlock(&lock);
pthread_exit(NULL);

}
void *withdmoney (void *thid){
pthread_mutex_t lock;
for(int i=0;i<200;i++){
balance=balance-5;
}

pthread_mutex_unlock(&lock);
pthread_exit(NULL);
}
int main(){
pthread_t th0;
pthread_t th1;

pthread_create(&th0,NULL,depositmoney,(void *)&th0);
pthread_create(&th1,NULL,withdmoney,(void *)&th1);
pthread_join(th0,NULL);
pthread_join(th1,NULL);
printf("Balance =%d\n,",balance);
pthread_mutex_destroy(&lock);
pthread_exit(NULL);
}
