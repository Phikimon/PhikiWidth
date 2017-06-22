#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "tree.h"

typedef struct TreeNode* QueueType;

enum { POISON_INT   = 0xDEADBEEF };
enum { QUEUE_SIZE   = 128 };
enum { MAX_NAME_LEN = 128 };

enum QueueErrors
{
    QUEUE_ERROR_OK = 0,
    QUEUE_ERROR_NULLPTR,
    QUEUE_ERROR_FULL,
    QUEUE_ERROR_EMPTY
};

struct Queue
{
    QueueType arr[QUEUE_SIZE];
    int head;
    int tail;
};

#define   queueDump(q) queueDump_(q, #q)
int       queueDump_(struct Queue* q,
                     const char    name[MAX_NAME_LEN]);

int       queueCtor    (struct Queue* q);

int       queueDtor    (struct Queue* q);

int       queueIsFull  (struct Queue* q);

int       queueIsEmpty (struct Queue* q);

QueueType queuePop     (struct Queue* q);

int       queuePush    (struct Queue* q, QueueType n);
#endif
