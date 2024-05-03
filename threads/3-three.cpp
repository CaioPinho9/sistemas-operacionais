#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>

int MAX_THREADS;
int contador_global = 0;

void *increment(void *id) {
    for (int i = 0; i < 100; ++i) {
        contador_global++;
    }
    return nullptr;
}


int runTest() {
    pthread_t threads[MAX_THREADS];

    for (unsigned long &thread: threads) {
        pthread_t a_thread;
        pthread_create(&a_thread, nullptr, increment, nullptr);
        thread = a_thread;
    }

    for (unsigned long thread: threads) {
        void *thread_result;
        pthread_join(thread, &thread_result);
    }

    printf("MAX_THREADS: %d, Resultado: %d\n", MAX_THREADS, contador_global);
}

int main() {
    for (int i = 2; i < 100000; i *= 2) {
        contador_global = 0;
        MAX_THREADS = i;
        runTest();
    }
}
