#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct list_element
{
    struct list_element * next;
};
typedef struct list_element list_element;

typedef struct
{
    list_element * first;
    list_element * last;
} list;


void list_init(list *);
bool list_empty(list *);
list_element * list_begin(list *);
list_element * list_next(list_element *);
void list_push_back(list *, list_element *);
list_element * list_pop_front(list *);


#endif