#include <windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define NUM_THREADS 5
#define INCREMENTS_PER_THREAD 100000

// Shared counter
int counter_mutex = 0;
int counter_semaphore = 0;

// Synchronization objects
HANDLE mutex;
HANDLE semaphore;

DWORD WINAPI increment_with_mutex(LPVOID arg)
{
    for (int i = 0; i < INCREMENTS_PER_THREAD; i++)
    {
        WaitForSingleObject(mutex, INFINITE);
        counter_mutex++;
        ReleaseMutex(mutex);
    }
    return 0;
}

DWORD WINAPI increment_with_semaphore(LPVOID arg)
{
    for (int i = 0; i < INCREMENTS_PER_THREAD; i++)
    {
        WaitForSingleObject(semaphore, INFINITE);
        counter_semaphore++;
        ReleaseSemaphore(semaphore, 1, NULL);
    }
    return 0;
}

int main()
{
    HANDLE threads[NUM_THREADS];

    // Initialize mutex and semaphore
    mutex = CreateMutex(NULL, FALSE, NULL);
    semaphore = CreateSemaphore(NULL, 1, 1, NULL);

    printf("Starting mutex version...\n");

    // Create threads for mutex version
    for (int i = 0; i < NUM_THREADS; i++)
    {
        threads[i] = CreateThread(NULL, 0, increment_with_mutex, NULL, 0, NULL);
    }

    // Wait for all threads to complete
    WaitForMultipleObjects(NUM_THREADS, threads, TRUE, INFINITE);

    printf("Mutex version complete. Final counter value: %d (expected: %d)\n",
           counter_mutex, NUM_THREADS * INCREMENTS_PER_THREAD);

    printf("\nStarting semaphore version...\n");

    // Create threads for semaphore version
    for (int i = 0; i < NUM_THREADS; i++)
    {
        threads[i] = CreateThread(NULL, 0, increment_with_semaphore, NULL, 0, NULL);
    }

    // Wait for all threads to complete
    WaitForMultipleObjects(NUM_THREADS, threads, TRUE, INFINITE);

    printf("Semaphore version complete. Final counter value: %d (expected: %d)\n",
           counter_semaphore, NUM_THREADS * INCREMENTS_PER_THREAD);

    // Clean up
    CloseHandle(mutex);
    CloseHandle(semaphore);

    cout << "Priyam Talukdar 24BAI10201";

    return 0;
}