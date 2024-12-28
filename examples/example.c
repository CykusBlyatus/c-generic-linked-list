#include <llist.h>
#include <stdio.h>

int main() {
    llist(int) list;
    llist_init(&list);

    for (int i = 0; i < 5; ++i)
        llist_push_front(&list, i);

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
