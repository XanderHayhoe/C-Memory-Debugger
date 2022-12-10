//
// Created by xande on 12/9/2022.
//

#ifndef XANDEBUG_MALLOC_LIST_H
#define XANDEBUG_MALLOC_LIST_H
#include <iostream>
class Node{
public:
    int memory_malloc_size;
    int memory_free_size;
    int memory_new_size;
    int memory_delete_size;
    int line;
    std::string file;
    Node* next;
    Node() {
        this->memory_delete_size = 0;
        this->memory_new_size = 0;
        this->memory_free_size = 0;
        this->memory_malloc_size = 0;
        this->file = " ";
        this->line = 0;
        this->next = nullptr;
    }
    int getMemoryMallocSize() const {return this->memory_malloc_size; }
    int getMemoryFreeSize() const { return this->memory_free_size;}
    int getMemoryNewSize() const {return this->memory_new_size;}
    int getMemoryDeleteSize() const {return this->memory_delete_size;}
    int getLine() const {return this->line; }
    std::string getFile() const { return this->file; }

};
class Malloc_list {


public:
    Node* head;
    Malloc_list() {
        head = NULL;
    }
    void malloc_list_append(int size,
                            int line,
                            std::string file,
                            bool malloc
    );
};
//change

#endif //XANDEBUG_MALLOC_LIST_H
