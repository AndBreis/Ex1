#include <pthread.h>
#include <stdio.h>

int i = 0;

// Note the return type: void*
void* incrementingThreadFunction(){
    for (int x = 0; x < 1000000 ; x++){
      i++
    }
    return NULL;
}

void* decrementingThreadFunction(){
    for (int x = 0; x < 1000000 ; x++){
      i--
    }
    return NULL;
}


int main(){
    pthread_t incrementingThreadFunction
    pthread_t decrementingThreadFunction
    // TODO: declare incrementingThread and decrementingThread (hint: google pthread_create)
    pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL);
    pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL);

    pthread_join(incrementingThread, NULL);
    pthread_join(decrementingThread, NULL);

    printf("The magic number is: %d\n", i);
    return 0;
}
