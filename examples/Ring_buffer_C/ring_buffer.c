#include <stdio.h>
#include <stdbool.h>
#include "ring_buffer.h"


void rb_init(RingBuffer *rb)
{
    if (NULL == rb) {
        return;
    }

    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
}

int rb_is_full(RingBuffer *rb, bool *is_full)
{
    if (NULL == rb) {
        return -1;
    }

    *is_full = rb->count == BUFFER_SIZE;
     return 0;
}


int rb_is_empty(RingBuffer *rb, bool *is_empty)
{
    if (NULL == rb) {
        return -1;
    }

    *is_empty = rb->count == 0;

    return 0;
}

int rb_push(RingBuffer *rb, uint8_t data)
{
    if (NULL == rb) {
        return -1;
    }

    if (rb->count == BUFFER_SIZE) {
        return -1;
    }

    rb->buffer[rb->head] = data;
    rb->head = (rb->head + 1) % BUFFER_SIZE;
    rb->count++;

    return 0;
}


int rb_pop(RingBuffer *rb, uint8_t *data)
{
    if (NULL == rb || NULL == data) {
        return -1;
    }

    if (0 == rb->count) {
        return -1;
    }

    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % BUFFER_SIZE;
    rb->count--;

    return 0;
}

