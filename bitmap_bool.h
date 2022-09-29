#ifndef BITMAP_BOOL_H
#define BITMAP_BOOL_H

int create_bitmap(int size);
void release_bitmap(void);
bool get_bit(unsigned int index);
void set_bit(unsigned int index);

#endif // BITMAP_BOOL_H
    