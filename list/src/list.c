#include <list.h>


void list_init(list * container)
{
    container->first = 0;
    container->last = 0;
}

bool list_empty(list * container)
{
    return 0 == container->first;
}

list_element * list_begin(list * container)
{
    return container->first;
}

list_element * list_next(list_element * element)
{
    return element->next;
}

void list_push_back(list * container, list_element * element)
{
    if (list_empty(container))
    {
        container->first = element;
        container->last = element;
    }
    else
    {
        container->last->next = element;
        container->last = element;
    }

    element->next = 0;
}

list_element * list_pop_front(list * container)
{
    list_element * element = container->first;
    container->first = container->first->next;
    return element;
}

typedef struct
{
    list_element header;
    int value;
} apple;

