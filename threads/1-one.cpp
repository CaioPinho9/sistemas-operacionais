#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>

void *increment(void *id) {
    printf("Nova thread criada. TID = %lu!\n", (unsigned long) pthread_self());
    return nullptr;
}

int main() {
    pthread_t a_thread;
    void *thread_result;
    pthread_create(&a_thread, nullptr, increment, nullptr);
    pthread_join(a_thread, &thread_result);
    printf("Waited");
}
