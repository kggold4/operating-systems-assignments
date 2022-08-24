/**
 * Operating Systems Assignment #3
 * AUTHORS: Kfir Goldfarb and Yehonadav Yadai
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>

// global variables
long sum = 0;
long primeCounter = 0;

// implementing faster atoi
int atoi_faster(const char * str) {
    int value = 0;
    while(*str) { value = value*10 + (*str++ - '0'); }
    return value;
}

// is prime function
int isPrime(long number) {
    if(number <= 1) { return 0; }
    if(number == 2 || number == 3) { return 1; }
    int i, nb, test, limit;
    test = 0;
    nb = number;
    limit = sqrt(nb) + 1;
    if(nb % 2 == 0) { test = 1; }
    else {
        for(i = 3; i < limit && ! test; i += 2) {
            if(nb % i == 0) { test = 1; }
        }
    }
    if(!test) { return 1; }
    else { return 0; }
}

// the runnable function
void * checkRandom(int numOfRandomNumbers) {

    long temp_sum = 0;
    int temp_primeCounter = 0, random;
    do {
        // get random number
        random = rand();

        //check if the number is prime
        if(isPrime(random)) {
            temp_sum += random;
            ++temp_primeCounter;
        }
    } while(--numOfRandomNumbers);

    sum += temp_sum;
    primeCounter += temp_primeCounter;
}

int main(int argc, char *argv[]) {

    if(argc != 3) {
        printf("Too few arguments ");
        printf("USAGE: ./primeCalc <prime pivot> <num of random numbers>");
        exit(0);
    }

    // get arguments
    short randomPivot = atoi_faster(argv[1]);
    int numOfRandomNumbers = atoi_faster(argv[2]);

    // get number of cores in the CPU
    short cores = sysconf(_SC_NPROCESSORS_CONF);

    // divide the number of random number between cores
    int k = numOfRandomNumbers / cores;
    int r = numOfRandomNumbers % cores;
    srand(randomPivot);

    // malloc thread in number of cores in CPU
    pthread_t *ptr = malloc(sizeof(pthread_t)*cores);

    short i;
    for(i = 0; i < cores; i++) {
        if(i != cores - 1) {

            // create and run all the thread (without the last one)
            pthread_create(&ptr[i], NULL, (void *) &checkRandom, k);

        // the last thread
        } else {
            int t = k + r;
            pthread_create(&ptr[i], NULL, (void *) &checkRandom, t);
        }
    }

    // join every thread
    for(i = 0; i < cores; ++i) { pthread_join(ptr[i], NULL); }

    // output
    printf("%ld,%ld\n", sum, primeCounter);

    // done
    exit(0);
}
