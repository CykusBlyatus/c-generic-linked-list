#ifndef C_GENERIC_LINKED_LIST_H
#define C_GENERIC_LINKED_LIST_H

#include <stdlib.h>

/**
 * @brief Used to represent nodes for linked lists
 * @param T Type of the value to hold
 */
#define llist_node(T)\
    struct {\
        void *next;\
        T val;\
    }

/**
 * @brief Linked List Destruct: Deallocates all nodes of a linked list
 * @param self Pointer to a struct that has an attribute called "head" that is a pointer to a type of llist_node(T)
 */
#define llist_destruct(self) llist_destruct_f(self, free)

/**
 * @brief Linked List Destruct Full: Deallocates all nodes of a linked list
 * @param self Pointer to a struct that has an attribute called "head" that is a pointer to a type of llist_node(T)
 * @param deallocator A memory deallocator, like the "free" function from <stdlib.h>
 */
#define llist_destruct_f(self, deallocator) llist_node_destruct_f(&(self)->head, deallocator)

/**
 * @brief Linked List Node Destruct: Deallocates all nodes of a linked list, given its head
 * @param head list_node(T)**: Pointer to the address (to a pointer, not to the head itself!) of the head of the linked list
 */
#define llist_node_destruct(head) llist_node_destruct_f(head, free)

/**
 * @brief Linked List Node Destruct Full: Deallocates all nodes of a linked list, given its head and a deallocator
 * @param head_ptr_ptr list_node(T)**: Pointer to the address (to a pointer, not to the head itself!) of the head of the linked list
 * @param deallocator A memory deallocator, like the "free" function from <stdlib.h>
 */
void llist_node_destruct_f(void *head_ptr_ptr, void (*deallocator)(void*));

/**
 * @brief Linked List Push Front: Adds a value to the beginning of a linked list
 * @param self Pointer to a struct that has an attribute called "head" that is a pointer to a type of llist_node(T)
 * @param value Value to add
 */
#define llist_pushf(self, value) llist_pushf_f(self, value, malloc)

/**
 * @brief Linked List Push Front Full: Adds a value to the beginning of a linked list
 * @param self Pointer to a struct that has an attribute called "head" that is a pointer to a type of llist_node(T)
 * @param value Value to add
 */
#define llist_pushf_f(self, value, allocator) llist_node_pushf_f(&(self)->head, value, allocator)

/**
 * @brief Linked List Node Push Front: Adds an element to the beginning of a linked list, given its head
 * @param head  list_node(T)**: Pointer to the address (to a pointer, not to the head itself!) of the head of the linked list
 * @param value Value to add
 */
#define llist_node_pushf(head, value) llist_node_pushf_f(head, value, malloc)

#define llist_node_pushf_f(head, value, allocator) do {\
    llist_node_allocf(head, sizeof(**(head)), allocator);\
    (*(head))->val = value;\
} while(0)

/**
 * @brief Linked List Node Allocate Front: Adds a node with an unitialized value to the beginning of a linked list, given its head and a memory allocator
 * @param head_ptr_ptr list_node(T)**: Pointer to the address (to a pointer, not to the head itself!) of the head of the linked list
 * @param allocator A memory allocator, like the "malloc" function from <stdlib.h>
 * @return void* On success, returns the new head of the linked list (which should be equal to the (updated) value *head_ptr_ptr).
                 On failure, returns NULL.
 */
void *llist_node_allocf(void *head_ptr_ptr, size_t node_size, void *(*allocator)(size_t));

/**
 * @brief Linked List Pop Front: Removes the first element of a linked list
 * @param self Pointer to a struct that has an attribute called "head" that is a pointer to a type of llist_node(T)
 * @param value Value to add
 */
#define llist_popf(self) llist_node_popf(&(self)->head)

#define llist_popf_f(self, deallocator) llist_node_popf_f(&(self)->head, deallocator)

/**
 * @brief Linked List Node Pop Front: Removes the first element of a linked list, given its head
 * @param head  list_node(T)**: Pointer to the address (to a pointer, not to the head itself!) of the head of the linked list
 */
#define llist_node_popf(head) llist_node_popf_f(head, free)

void llist_node_popf_f(void *head_ptr_ptr, void (*deallocator)(void*));

/**
 * @brief Linked List Foreach: Iterates over a Linked List
 * @param self Pointer to a struct that has an attribute called "head" that is a pointer to a type of llist_node(T)
 * @param node Variable name for the node
 */
#define llist_foreach(self, node) llist_node_foreach((self)->head, node)

/**
 * @brief Linked List Node Foreach: Iterates over a Linked List, given its head
 * @param head list_node(T)*: Pointer to the head of the linked list
 * @param node Variable name for the node
 */
#define llist_node_foreach(head, node) for (typeof(head) node = head; node != NULL; node = node->next)

/**
 * @brief Circular Linked List Foreach: Iterates over a Circular Linked List
 * @param self Pointer to a struct that has an attribute called "head" that is a pointer to a type of llist_node(T)
 * @param node Variable name for the node
 */
#define cllist_foreach(self, node) cllist_node_foreach((self)->head, node)\

/**
 * @brief Circular Linked List Node Foreach: Iterates over a Linked List, given its head
 * @param head list_node(T)*: Pointer to the head of the circular linked list
 * @param node Variable name for the node
 */
#define cllist_node_foreach(head, node)\
    for (\
        typeof(head) node = head, _cllist_foreach_flag = 0;\
        node != head || !(_cllist_foreach_flag++);\
        node = node->next\
    )

#endif // C_GENERIC_LINKED_LIST_H
