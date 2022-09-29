/*
    manipulate bitmaps as bools
    We assume the value returned by sizeof() represents
    storage available in 8 bit chunks. IOW sizeof(int) == 4
    and can store 4*8 =? 32 bits.
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "bitmap_bool.h"

static int *bitmap_storage = 0;    // storage for bitmapped flags
static long int word_size = 0;     // number of bits in a storage word
static size_t words_allocated = 0; // words of storage allocated
static size_t bitmap_size = 0;     // size of created bitmap

static void err_exit(const char *const msg, int status)
{
    fprintf(stderr, "exiting due to \"%s\"\n", msg);
    exit(status);
}
// Allocate space for the bitmap and
int create_bitmap(int size)
{
    bitmap_size = size; // save for range checking
    word_size = sizeof(bitmap_storage[0]) * 8;
    words_allocated = size / word_size;
    bitmap_storage = calloc(words_allocated, word_size);
    fprintf(stderr, "allocated %ld size %ld at %lx\n\n",
            words_allocated, sizeof(bitmap_storage[0]), (unsigned long int)bitmap_storage);
    fprintf(stderr, "%d bitmap_storage[0]\n\n", bitmap_storage[0]);

    return (bitmap_storage != 0);
}

// release space allocated for bitmap
void release_bitmap(void)
{
    if (bitmap_storage == 0)
        err_exit("attempt to free unallocated bitmap", 1);
    else
        free(bitmap_storage);
}

bool get_bit(unsigned int index)
{
    if (index > bitmap_size)
        err_exit("get_bit() bit index out of range", 1);

    int word_index = index / word_size;
    int bit_index = index % word_size;
    return ((bitmap_storage[word_index] & (1 << bit_index)) != 0);
}

void set_bit(unsigned int index) //
{
    if (index > bitmap_size)
        err_exit("set_bit() bit index out of range", 1);

    int word_index = index / word_size;
    int bit_index = index % word_size;
    fprintf(stderr, "%d %d\n\n", word_index, bit_index);
    bitmap_storage[word_index] |= (1 << bit_index);
}

// Algorithm does not require ability to clear a bit so that
// capability is not provided.