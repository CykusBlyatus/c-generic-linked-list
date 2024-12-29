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
 * @note If you wish to use a node whose name is not "head", see llist_node_destruct
 */
#define llist_destruct(self) llist_node_destruct(&(self)->head)

/**
 * @brief Linked List Node Destruct: Deallocates all nodes of a linked list, given its head
 * @param head llist_node(T)** (Pointer to a pointer to a type of llist_note(T)).
 *             The extra "*" is to make it clear that the head is a pointer whose address will be changed.
 */
#define llist_node_destruct(head) do {\
    for (typeof(*(head)) node = *(head); node != NULL;) {\
        void *tmp = node->next;\
        free(node);\
        node = tmp;\
    }\
    *(head) = NULL;\
} while(0)

/**
 * @brief Linked List Push Front: Adds a value to the beginning of a linked list
 * @param self Pointer to a struct that has an attribute called "head" that is a pointer to a type of llist_node(T)
 * @param value Value to add
 * @note If you wish to use a node whose name is not "head", see llist_node_pushf
 */
#define llist_pushf(self,value) llist_node_pushf(&(self)->head,value)

/**
 * @brief Linked List Node Push Front: Adds an element to the beginning of a linked list, given its head
 * @param head llist_node(T)** (Pointer to a pointer to a type of llist_note(T)).
 *             The extra "*" is to make it clear that the head is a pointer whose address will be changed.
 * @param value Value to add
 */
#define llist_node_pushf(head,value) do {\
    typeof(*(head)) node = malloc(sizeof(**(head)));\
    node->val = value;\
    node->next = *(head);\
    *(head) = node;\
} while(0)

/**
 * @brief Linked List Pop Front: Removes the first element of a linked list
 * @param self Pointer to a struct that has an attribute called "head" that is a pointer to a type of llist_node(T)
 * @param value Value to add
 * @note If you wish to use a node whose name is not "head", see llist_node_popf
 */
#define llist_popf(self) llist_node_popf(&(self)->head)

/**
 * @brief Linked List Node Pop Front: Removes the first element of a linked list, given its head
 * @param head llist_node(T)** (Pointer to a pointer to a type of llist_note(T)).
 *             The extra "*" is to make it clear that the head is a pointer whose address will be changed.
 */
#define llist_node_popf(head) do {\
    typeof(*(head)) new_head = (*(head))->next;\
    free(*(head));\
    *(head) = new_head;\
} while(0)

/**
 * @brief Linked List Foreach: Iterates over a Linked List
 * @param self Pointer to a struct that has an attribute called "head" that is a pointer to a type of llist_node(T)
 * @param node Variable name for the node
 */
#define llist_foreach(self,node) for (typeof((self)->head) node = (self)->head; node != NULL; node = node->next)

/**
 * @brief Circular Linked List Foreach: Iterates over a Circular Linked List
 * @param self Pointer to a struct that has an attribute called "head" that is a pointer to a type of llist_node(T)
 * @param node Variable name for the node
 */
#define cllist_foreach(self,node)\
    for (\
        typeof((self)->head) node = (self)->head, _cllist_foreach_flag = 0;\
        node != (self)->head || !(_cllist_foreach_flag++);\
        node = node->next\
    )

#endif // C_GENERIC_LINKED_LIST_H
