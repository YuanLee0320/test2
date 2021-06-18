#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <iostream>
#include <unistd.h>
#include <string.h>
// number of elements in array
#define MAX (256)   // must be 4^n
// number of threads
#define THREAD_MAX_BUBBLE 16        // must be 2^n
#define THREAD_MAX_MERGE 4


// this is a test

//#define DBG

int part = 0;
int part_merge = 0;
using namespace std;

char a[MAX];

// bubble sort function
void bubblesort(char a[MAX], int low, int high) {
    char hdn;

    for (int n = low; n < high + 1; n++)
        for (int o = low; o < high; o++)

            if (a[o] > a[o + 1]) {
                hdn = a[o + 1];
                a[o + 1] = a[o];
                a[o] = hdn;
            }
#ifdef DBG
    for (int i = low; i <= high; i++)
        printf("%4d", a[i]);
    printf("\n");
#endif

}

int main(int argc, char *argv[]) {

    struct timespec start, finish;
    double elapsed;

    int n = THREAD_MAX_BUBBLE;

    for (int i = 0; i < MAX; i++)
        *(a + i) = rand() % 100;

    clock_gettime(CLOCK_MONOTONIC, &start);


    bubblesort(a, 0, MAX - 1);


#ifdef DBG
    printf("\n");
    for (int i = 0; i < MAX; i++) {
        printf("%4d", a[i]);
    }
    printf("\n");
#endif
    clock_gettime(CLOCK_MONOTONIC, &finish);

    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

    cout << "total time spent:" << elapsed * 1000 << "ms" << endl;


}
