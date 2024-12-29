#ifndef C_GENERIC_LINKED_LIST_H
#define C_GENERIC_LINKED_LIST_H

#include "llist_no_stdlib.h"
#include "llist_node.h"

/**
 * @brief Linked List Destruct: Deallocates all nodes of a linked list
 * @param self Pointer to a struct that has an attribute called "head" that is a pointer to a type of llist_node(T)
 */
#define llist_destruct(self) llist_destruct_f(self, free)

/**
 * @brief Linked List Push Front: Adds a value to the beginning of a linked list
 * @param self Pointer to a struct that has an attribute called "head" that is a pointer to a type of llist_node(T)
 * @param value Value to add
 */
#define llist_pushf(self, value) llist_pushf_f(self, value, malloc)

/**
 * @brief Linked List Pop Front: Removes the first element of a linked list
 * @param self Pointer to a struct that has an attribute called "head" that is a pointer to a type of llist_node(T)
 * @param value Value to add
 */
#define llist_popf(self) llist_node_popf(&(self)->head)

#endif // C_GENERIC_LINKED_LIST_H
