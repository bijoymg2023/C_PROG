#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    //key_t key = ftok("shmfile", 65);
    int shmid = shmget((key_t)2345, 1024, 0666 );
    int *sharedMemory = shmat(shmid, NULL, 0);

    printf("Sum of digits read from shared memory: %d\n", *sharedMemory);

    return 0;
}