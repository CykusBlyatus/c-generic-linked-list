#ifndef C_GENERIC_LINKED_LIST_NO_STDLIB_H
#define C_GENERIC_LINKED_LIST_NO_STDLIB_H

#include "llist_node_no_stdlib.h"

/**
 * @brief Linked List Destruct Full: Deallocates all nodes of a linked list
 * @param self Pointer to a struct that has an attribute called "head" that is a pointer to a type of llist_node(T)
 * @param deallocator A memory deallocator, like the "free" function from <stdlib.h>
 */
#define llist_destruct_f(self, deallocator) llist_node_destruct_f(&(self)->head, deallocator)

/**
 * @brief Linked List Push Front Full: Adds a value to the beginning of a linked list
 * @param self Pointer to a struct that has an attribute called "head" that is a pointer to a type of llist_node(T)
 * @param value Value to add
 */
#define llist_pushf_f(self, value, allocator) llist_node_pushf_f(&(self)->head, value, allocator)

#define llist_popf_f(self, deallocator) llist_node_popf_f(&(self)->head, deallocator)

/**
 * @brief Linked List Foreach: Iterates over a Linked List
 * @param self Pointer to a struct that has an attribute called "head" that is a pointer to a type of llist_node(T)
 * @param node Variable name for the node
 */
#define llist_foreach(self, node) llist_node_foreach((self)->head, node)

/**
 * @brief Circular Linked List Foreach: Iterates over a Circular Linked List
 * @param self Pointer to a struct that has an attribute called "head" that is a pointer to a type of llist_node(T)
 * @param node Variable name for the node
 */
#define cllist_foreach(self, node) cllist_node_foreach((self)->head, node)\

#endif // C_GENERIC_LINKED_LIST_NO_STDLIB_H
