#include "queue.h"

#include "assert.h"
#include "stdlib.h" //< for NULL definition
#include "stdio.h"

int queueCtor(struct Queue* q)
{
    q->tail = q->head = 0;
    return 0;
}

int queueDtor(struct Queue* q)
{
    q->tail = q->head = POISON_INT;
    return 0;
}

int queueIsFull(struct Queue* q)
{
    if (!q) return -QUEUE_ERROR_NULLPTR;
    return (q->head           >  q->tail   ) ?
           (q->tail - q->head >= 0         ) :
           (q->tail - q->head >= QUEUE_SIZE);
}

int queueIsEmpty(struct Queue* q)
{
    assert(q);
    if (!q) return -1;
    return (q->head == q->tail);
}

int queuePush(struct Queue* q, QueueType n)
{
    if ((!q) || (!n))   return -QUEUE_ERROR_NULLPTR;
    if (queueIsFull(q)) return -QUEUE_ERROR_FULL;
    q->arr[q->tail] = n;
    q->tail = (q->tail + 1) % QUEUE_SIZE;
    return 0;
}

QueueType queuePop(struct Queue* q)
{
    assert(q);
    if (!q) return NULL;
    assert(!queueIsEmpty(q));
    if (queueIsEmpty(q)) return NULL;
    QueueType result = q->arr[q->head];
    q->head = (q->head + 1 ) % QUEUE_SIZE;
    return result;
}

int queueDump_(struct Queue* q,
               const char    name[MAX_NAME_LEN])
{
    assert(q);
    if (!q) return QUEUE_ERROR_NULLPTR;
    printf("Queue %s [%p]:\n", name, q);
    printf("{\n\tContent:\n");
    int i, j;
    for (i = q->head, j = 0;
         j < QUEUE_SIZE;
         i = (i + 1) % QUEUE_SIZE, j++)
    {
        if (!q->arr[i]) continue;
        printf("\t[%-2d] %p\n", i, q->arr[i]);
    }
    printf("\thead = %d\n", q->head);
    printf("\ttail = %d\n", q->tail);
    printf("}\n");
    return 0;
}

