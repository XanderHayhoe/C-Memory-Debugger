#ifndef XAN_DEBUG
#define XAN_DEBUG
#include <iostream>
#include <iostream>
#include "Malloc_list.h"

#if defined(_WIN32) || defined(_WIN64)
#define fPrefix "\\"
#else
#define fPrefix "/"
#endif

#define     __FILENAME__    0
#define     XAN_new     new(__FILE__, __LINE__)
#define     new         XAN_new



// declare macros
#define OVER_MEM 0x192BA3A2
#define UNDER_MEM 0x39D7A5DA
typedef unsigned char byte;
// from matthew <3

//counters for malloc, free, new, delete
static int      malloc_counter;
static int      free_counter;
static int      new_counter;
static int      delete_counter;
//counter for total memory
static int      malloc_mem_counter;
static int      free_mem_counter;
static int      new_mem_counter;
static int      delete_mem_counter;
// linked list for nodes

// list for malloc tree
static size_t malloc_list_size;
static Malloc_list *head = nullptr;
#ifndef NULL
#ifdef __cplusplus
        #define NULL    0
    #else
        #define NULL    ((void *)0)
    #endif // __cplusplus
#endif // NULL
void printDebug(Node *head,
                int malloc_counter,
                int free_counter,
                int new_counter,
                int delete_counter
) {
    Node* temp = head;
    if (head == nullptr) {
        printf("No malloc, new, free, or delete calls");
    }
    else {
        int counter = 1;
        while(temp != nullptr) {
            printf("%d-th memory modification:\n", counter);
            printf("data alloc'd via malloc: %d\n", temp->getMemoryMallocSize());
            printf("data dealloc'd via free: %d\n", temp->getMemoryFreeSize());
            printf("data alloc'd via new: %d\n", temp->getMemoryNewSize());
            printf("data dealloc'd via delete: %d\n", temp->getMemoryDeleteSize());
            printf("source: %s, line: %d\n", temp->file, temp->getLine());
            temp = temp->next;
            counter++;
        }
    }
}

void * XAN_malloc(size_t size,
                  char* file,
                  int line
) {
    Node *temp;
    temp = head->head;
    void *ptr = nullptr;
    unsigned int *buffer_under;
    unsigned int *buffer_over;
    // check if malloc works ->
    buffer_under = (unsigned int *)malloc(size + 2 * sizeof(unsigned int));
    if (buffer_under != nullptr) {
        ptr = buffer_under + 1;
        buffer_over = (unsigned int *)((byte *)ptr + size);
        *buffer_over = OVER_MEM;
        *buffer_under = UNDER_MEM;

        malloc_counter++;

        malloc_mem_counter += size;

        head->malloc_list_append(size, line, file, true);
    }
    else {
        // if alloc failed
        printf("Alloc failed at location: %s, line %d", file, line);
        printDebug(temp, malloc_counter, free_counter, new_counter, delete_counter);
    }
    return ptr;
}

void * XAN_free(size_t size,
                char * file,
                int line
) {

}
// not working due to char *

#define     malloc(_size)   XAN_malloc(_size, __FILENAME__, __LINE__)
int main() {
    malloc(10);
    std::cout << "Ben" << std::endl;
    return 0;
}
//change
#define XAN_DEBUG_MODE
#ifdef XAN_DEBUG_MODE // default c++ mode

#endif // XAN_DEBUG_MODE
#endif // XAN_DEBUG