#include <gLib.h>
#include "../src/list.h"

void setUp(void)
{

    typedef struct
    {
        list_element header;
        int value;
    } apple;
}

void tearDown(void)
{

}

static void first_test(void)
{
    list apples;
    apple * a = (apple *) malloc(sizeof(apple));
    apple * b = (apple *) malloc(sizeof(apple));
    apple * c = (apple *) malloc(sizeof(apple));

    a->value = 1;
    b->value = 2;
    c->value = 3;

    list_init(&apples);

    list_push_back(&apples, &a->header);
    list_push_back(&apples, &b->header);
    list_push_back(&apples, &c->header);

    for(a = (apple*) list_begin(&apples); a; a = (apple *) list_next(&a->header))
    {
        printf("%d\n", a->value);
    }

    while (!list_empty(&apples))
    {
        a = (apple *) list_pop_front(&apples);
        free(a);
    }
}

int main(void)
{
    Unit
}