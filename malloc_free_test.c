#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static int count = 0;

typedef struct thing
{
    int cnt;
} thing;

void changeStruct(thing * ts);
void freeStruct(thing * ts);

int main()
{
    thing * t = (thing*) malloc(sizeof(thing));

    t->cnt = 1;
    printf("pointer in main %p, value %d\n", t, *t);
    changeStruct(t);
    printf("pointer in main  %p, value %d\n", t, *t);
    freeStruct(t);
    printf("pointer  in main %p, value %d\n", t, *t);
    t=NULL;
    assert(t == NULL);
    printf("pointer in main %p\n", t);
    return 0;
}

void changeStruct(thing * ts)
{
    ts->cnt =2;
}

void freeStruct(thing * ts)
{
    free(ts);
    printf("pointer in freeStruct %p, value %d\n", ts, *ts);
    ts = NULL;
    printf("pointer in freeStruct %p\n", ts);
}