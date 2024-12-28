#include "llist.h"
#include <stdlib.h>

typedef llist(char) auxil_llist_t;
typedef llist_node(char) auxil_llist_node_t;

int llist_init_(void *self /*, __attribute__((unused)) size_t type_size*/) {
    llist_init((auxil_llist_t*)self);
    return 0;
}

void *llist_node_alloc_(size_t type_size) {
    return malloc(sizeof(auxil_llist_node_t) + type_size - 1);
}
