#ifndef QUEUE_H
#define QUEUE_H

#include "common.h"

extern void* free_pointers [4];

#define QUEUE_EMPTY INT_MIN

typedef struct node {
    int value;
    struct node *next;
} node;

typedef struct {
    node *head;
    node *tail;
} queue;

void init_queue(queue *q);

bool enqueue(queue *q, int value);

int dequeue(queue *q);

typedef struct free_node {
    void* value_to_free;
    struct free_node *next;
} free_node;

typedef struct {
    free_node *head;
    free_node *tail;
} free_queue;

void init_free_queue(free_queue *q);

bool free_enqueue(free_queue *q, void* value_to_free);

bool free_dequeue(free_queue *q);

void clear_free_queue(free_queue *q);

void print_free_queue(free_queue *q);

extern free_queue garbage_strings;

#endif // QUEUE_H //