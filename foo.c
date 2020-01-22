#include <pthread.h>
#include <stdio.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

int i = 0;

// Note the return type: void*
void* incrementingThreadFunction(){
    for (int x = 0 ; x < 1000000 ; x++) {
      i++;
    }
    return NULL;
}

void* decrementingThreadFunction(){
    for (int k = 0; k < 1000000 ; k++){
      i--;
    }
    return NULL;
}


int main(){
    pthread_t incrementingThread;
    pthread_t decrementingThread;
    // TODO: declare incrementingThread and decrementingThread (hint: google pthread_create)
    pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL);
    pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL);

    pthread_join(incrementingThread, NULL);
    pthread_join(decrementingThread, NULL);

    printf("The magic number is: %d\n", i);
    sleep(5);
    return 0;
}
