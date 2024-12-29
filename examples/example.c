#include <llist.h>
#include <stdio.h>

#define llist(T)\
    struct {\
        llist_node(T) *head;\
    }

int main() {
    llist(int) list = {};

    for (int i = 0; i < 5; ++i)
        llist_pushf(&list, i);

    typeof(list.head) last = NULL;
    for (typeof(list.head) node = list.head; node != NULL; node = node->next) {
        printf("%d ", node->val);
        last = node;
    }
    putchar('\n');

    llist_foreach(&list, node)
        printf("%d ", node->val);
    putchar('\n');

    last->next = list.head;
    cllist_foreach(&list, node)
        printf("%d ", node->val);
    putchar('\n');

    last->next = NULL;
    llist_destruct(&list);
}
