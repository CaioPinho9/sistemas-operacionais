#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 5

void *increment(void *id) {
    printf("Nova thread criada. TID = %lu!\n", (unsigned long) pthread_self());
    return nullptr;
}

int main() {
    pthread_t threads[MAX_THREADS];

    for (unsigned long & thread : threads) {
        pthread_t a_thread;
        pthread_create(&a_thread, nullptr, increment, nullptr);
        thread = a_thread;
    }

    for (unsigned long thread : threads) {
        void *thread_result;
        pthread_join(thread, &thread_result);
    }

    printf("Waited");
}
