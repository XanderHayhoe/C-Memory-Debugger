//
// Created by xande on 12/9/2022.
//

#include "Malloc_list.h"

void Malloc_list::malloc_list_append(int size,
                                     int line,
                                     std::string file,
                                     bool malloc
) {
    Node *new_node = new Node();
    if (head == NULL) {
        head = new_node;
    } else {
        if (malloc) {
            new_node->memory_malloc_size = size;
            new_node->line = line;
            new_node->file = file;
        } else {
            new_node->memory_free_size = size;
            new_node->line = line;
            new_node->file = file;
        }
        new_node->next = NULL;
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}
//change
// global funct


