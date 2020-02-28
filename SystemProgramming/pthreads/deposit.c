#include <stdio.h>
#include <pthread.h>

int balance = 0;
pthread_mutex_t myMutex;

void * deposit(void *param) {
    char *thread = param;
    int i = 0;
    printf("%s begin\n", thread);
    for(i = 0; i < 1000000000; i++) {
        pthread_mutex_lock(&myMutex);
        balance = balance + 1;
        pthread_mutex_unlock(&myMutex);
    }
    printf("%s done\n", thread);
    return NULL;
}

int main() {

    pthread_t p1, p2;
    printf("main() creates two threads to execute deposit\n");

    pthread_create(&p1, NULL, deposit, "A");
    pthread_create(&p2, NULL, deposit, "B");
    
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("%d\n", balance);
    return 0;
}
