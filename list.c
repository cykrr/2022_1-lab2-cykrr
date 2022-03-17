#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
	List *tmp = (List *)malloc(sizeof(List));
	assert(tmp != NULL);

	tmp->current = NULL, 
		tmp->head = NULL,
		tmp->tail = NULL;

	return tmp;
}

void * firstList(List * list) {
	if (!list->head) return NULL;
	list->current = list->head;
    return list->head->data;
}

void * nextList(List * list) {
	if (!list->current) return NULL;
	if (!list->current->next) return NULL;
	list->current = list->current->next;
    return list->current->data;
}

void * lastList(List * list) {
	list->current = list->tail;
	if(!list->tail) return NULL;
	return list->tail->data;
	
}

void * prevList(List * list) {
	if(!list->current) return NULL;
	list->current = list->current->prev;
    return list->current->data;
}

void pushFront(List * list, void * data) {
	Node *new = createNode(data);
	if (list->head){
		Node* tmp = list->head;
		list->head = new;
		new->next = tmp;

	} else {
		list->head = new;
		list->tail = new;
	}
}


void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
	return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}
