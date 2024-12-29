#include <llist.h>

typedef llist_node(char) auxil_node_t;

void llist_node_destruct_f(void *ptr, void (*deallocator)(void*)) {
    void **head = ptr;
    for (auxil_node_t *node = *head; node != NULL;) {
        void *tmp = node->next;
        deallocator(node);
        node = tmp;
    }
    *head = NULL;
}

void *llist_node_allocf(void *ptr, size_t node_size, void *(*allocator)(size_t)) {
    auxil_node_t **head_ptr_ptr = ptr;
    auxil_node_t *node_ptr = allocator(node_size);
    if (!node_ptr)
        return NULL;
    node_ptr->next = *head_ptr_ptr;
    *head_ptr_ptr = node_ptr;
    return node_ptr;
}

void llist_node_popf_f(void *ptr, void (*deallocator)(void*)) {
    auxil_node_t **head_ptr_ptr = ptr;
    auxil_node_t *next_ptr = (*(head_ptr_ptr))->next;
    deallocator(*head_ptr_ptr);
    *head_ptr_ptr = next_ptr;
}
