#include "../include/queue.h"
#include "../include/common.h"

void* free_pointers[4];

void init_queue(queue* q)
{
	q->head = NULL;
	q->tail = NULL;
}

bool enqueue(queue* q, int value)
{
	node* newnode = malloc(sizeof(node));
	if (newnode == NULL)
		return false;
	newnode->value = value;
	newnode->next = NULL;
	if (q->tail != NULL) {
		q->tail->next = newnode;
	}
	q->tail = newnode;
	if (q->head == NULL) {
		q->head = newnode;
	}
	return true;
}

int dequeue(queue* q)
{
	if (q->head == NULL)
		return QUEUE_EMPTY;
	node* tmp = q->head;
	int result = tmp->value;
	q->head = q->head->next;
	if (q->head == NULL)
		q->tail = NULL;
	free(tmp);
	return result;
}

void init_free_queue(free_queue* q)
{
	q->head = NULL;
	q->tail = NULL;
}

bool free_enqueue(free_queue* q, void* value_to_free)
{
	free_node* newnode = malloc(sizeof(free_node));
	if (newnode == NULL)
		return false;
	newnode->value_to_free = value_to_free;
	newnode->next = NULL;
	if (q->tail != NULL) {
		q->tail->next = newnode;
	}
	q->tail = newnode;
	if (q->head == NULL) {
		q->head = newnode;
	}
	return true;
}

bool free_dequeue(free_queue* q)
{
	if (q->head == NULL)
		return false;
	free_node* tmp = q->head;
	free(tmp->value_to_free);
	tmp->value_to_free = NULL;
	q->head = q->head->next;
	if (q->head == NULL)
		q->tail = NULL;
	free(tmp);
	return true;
}

void clear_free_queue(free_queue* q)
{
	while (free_dequeue(q) != false)
		;
}

void print_free_queue(free_queue* q)
{
	free_node* tmp = q->head;
	if (tmp == NULL)
		return;
	printf("Queue:\n%s\n", tmp->value_to_free);
	while (tmp->next != NULL) {
		tmp = tmp->next;
		printf("%s\n", tmp->value_to_free);
	}
}

free_queue garbage_strings = {NULL, NULL};