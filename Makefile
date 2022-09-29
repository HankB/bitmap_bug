CC=gcc
CFLAGS=-I. -Wall -g -fsanitize=address
DEPS = bitmap_bool.h
OBJS = test_bitmap_bool.o bitmap_bool.o
LIBS=-lcunit -lefence

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test_bitmap_bool: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean valgrind

clean:
	rm -f *.o test_bitmap_bool core 

valgrind: ./test_bitmap_bool
	valgrind ./test_bitmap_bool
