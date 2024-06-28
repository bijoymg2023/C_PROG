#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

int sumOfDigits(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    //key_t key = ftok("shmfile", 65);
    int shmid = shmget((key_t)2345, 1024, 0666 | IPC_CREAT);
    int *sharedMemory = shmat(shmid, NULL, 0);

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    *sharedMemory = sumOfDigits(num);

    printf("Sum of digits written to shared memory: %d\n", sharedMemory);

    //shmdt(sharedMemory);

    return 0;
}