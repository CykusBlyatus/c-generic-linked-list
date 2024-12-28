#ifndef C_GENERIC_LINKED_LIST_H
#define C_GENERIC_LINKED_LIST_H

#include <stddef.h>
#include <stdlib.h>

#define llist_node(T)\
    struct {\
        void *next;\
        T val;\
    }

#define llist(T)\
    struct {\
        size_t size;\
        llist_node(T) *head;\
    }

#define llist_init(self) do {*(self) = (typeof(*(self))) {};} while(0)
#define llist_destruct(self) do {\
    for (typeof((self)->head) node = (self)->head; node != NULL;) {\
        void *tmp = node->next;\
        free(node);\
        node = tmp;\
    }\
} while(0)

#define llist_push_front(self,value) do {\
    typeof((self)->head) node = malloc(sizeof(*(self)->head));\
    node->val = value;\
    node->next = (self)->head;\
    (self)->head = node;\
    ++(self)->size;\
} while(0)

#define llist_pop_front(self,val) do {\
    typeof((self)->head) head = (self)->head;\
    (self)->head = head->next;\
    free(head);\
    --(self)->size;\
} while(0)

#define llist_foreach(self,node) for (typeof((self)->head) node = (self)->head; node != NULL; node = node->next)
#define cllist_foreach(self,node)\
    for (typeof((self)->head) node = (self)->head, _cllist_foreach_flag = 0; ; node = node->next)\
        if (node == (self)->head && (_cllist_foreach_flag++))\
            break;\
        else

int llist_init_(void *self /*, size_t type_size*/);
void *llist_node_alloc_(size_t type_size);
int llist_pop_front_(void *self, size_t type_size);

#endif // C_GENERIC_LINKED_LIST_H
