#ifndef C_GENERIC_LINKED_LIST_NODE_H
#define C_GENERIC_LINKED_LIST_NODE_H

#include "llist_node_no_stdlib.h"
#include <stdlib.h>

/**
 * @brief Linked List Node Destruct: Deallocates all nodes of a linked list, given its head
 * @param head list_node(T)**: Pointer to the address (to a pointer, not to the head itself!) of the head of the linked list
 */
#define llist_node_destruct(head) llist_node_destruct_f(head, free)

/**
 * @brief Linked List Node Push Front: Adds an element to the beginning of a linked list, given its head
 * @param head  list_node(T)**: Pointer to the address (to a pointer, not to the head itself!) of the head of the linked list
 * @param value Value to add
 */
#define llist_node_pushf(head, value) llist_node_pushf_f(head, value, malloc)

/**
 * @brief Linked List Node Pop Front: Removes the first element of a linked list, given its head
 * @param head  list_node(T)**: Pointer to the address (to a pointer, not to the head itself!) of the head of the linked list
 */
#define llist_node_popf(head) llist_node_popf_f(head, free)

#endif // C_GENERIC_LINKED_LIST_NODE_H
