#ifndef C_GENERIC_LINKED_LIST_NODE_NO_STDLIB_H
#define C_GENERIC_LINKED_LIST_NODE_NO_STDLIB_H

#include "llist_functions.h"

/**
 * @brief Used to represent nodes for linked lists
 * @param T Type of the value to hold
 */
#define llist_node(T)\
    struct {\
        void *next;\
        T val;\
    }

#define llist_node_pushf_f(head, value, allocator) do {\
    llist_node_allocf(head, sizeof(**(head)), allocator);\
    (*(head))->val = value;\
} while(0)

/**
 * @brief Linked List Node Foreach: Iterates over a Linked List, given its head
 * @param head list_node(T)*: Pointer to the head of the linked list
 * @param node Variable name for the node
 */
#define llist_node_foreach(head, node) for (typeof(head) node = head; node != NULL; node = node->next)

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

#endif // C_GENERIC_LINKED_LIST_NODE_NO_STDLIB_H
