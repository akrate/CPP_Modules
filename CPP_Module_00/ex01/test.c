#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* add(void *arg)
{
    int *p = (int *)arg;

    for (int j = 0; j < 65; j++)
    {
        (*p)++;
    }

    // printf("[%d]\n", *p);
    return NULL;
}


int main()
{
    pthread_t test;
    int h = 0;
    pthread_create(&test,NULL,add,&h);
    usleep(1); 
    printf("%d\n", h);
} 