#ifndef C_GENERIC_LINKED_LIST_FUNCTIONS_H
#define C_GENERIC_LINKED_LIST_FUNCTIONS_H

#include <stddef.h>

/**
 * @brief Linked List Node Allocate Front: Adds a node with an unitialized value to the beginning of a linked list, given its head and a memory allocator
 * @param head_ptr_ptr list_node(T)**: Pointer to the address (to a pointer, not to the head itself!) of the head of the linked list
 * @param allocator A memory allocator, like the "malloc" function from <stdlib.h>
 * @return void* On success, returns the new head of the linked list (which should be equal to the (updated) value *head_ptr_ptr).
                 On failure, returns NULL.
 */
void *llist_node_allocf(void *head_ptr_ptr, size_t node_size, void *(*allocator)(size_t));

/**
 * @brief Linked List Node Pop Front: Removes the first element of a linked list, given its head and a deallocator
 * @param head  list_node(T)**: Pointer to the address (to a pointer, not to the head itself!) of the head of the linked list
 */
void llist_node_popf_f(void *head_ptr_ptr, void (*deallocator)(void*));

/**
 * @brief Linked List Node Destruct Full: Deallocates all nodes of a linked list, given its head and a deallocator
 * @param head_ptr_ptr list_node(T)**: Pointer to the address (to a pointer, not to the head itself!) of the head of the linked list
 * @param deallocator A memory deallocator, like the "free" function from <stdlib.h>
 */
void llist_node_destruct_f(void *head_ptr_ptr, void (*deallocator)(void*));

#endif // C_GENERIC_LINKED_LIST_FUNCTIONS_H
