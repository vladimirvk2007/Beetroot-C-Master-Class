#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

#define BUFFER_SIZE  8

typedef struct {
    uint8_t buffer[BUFFER_SIZE];
    int head;
    int tail;
    int count;
} RingBuffer;

void rb_init(RingBuffer *rb);
int rb_is_full(RingBuffer *rb, bool *is_full);
int rb_is_empty(RingBuffer *rb, bool *is_empty);
int rb_push(RingBuffer *rb, uint8_t data);
int rb_pop(RingBuffer *rb, uint8_t *data);

#endif /* RING_BUFFER_H */