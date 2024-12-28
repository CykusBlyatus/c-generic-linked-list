EXAMPLES=$(wildcard examples/*.c)
PROGRAMS=$(EXAMPLES:examples/%.c=bin/%)

CFLAGS=-Wall -Wextra -Werror -I.

all: $(PROGRAMS)
	@echo "Programs ready!"

bin/%: examples/%.c llist.h obj/llist.o
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< obj/llist.o -o $@

obj/llist.o: llist.h llist.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) llist.c -o $@

clean:
	rm -r obj/ bin/
