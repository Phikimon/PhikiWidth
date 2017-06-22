#include "tree.h"
#include "assert.h"
#include "stdio.h"

int treeWidthPass(struct TreeNode* root)
{
#define DO_OR_DIE(smth)   \
{                         \
    int errcode = smth;   \
    if (errcode != 0)     \
        return (errcode); \
}
    assert(root);
    struct Queue q = {};
    DO_OR_DIE(queueCtor(&q));
    DO_OR_DIE(queuePush(&q, root));
    while (!queueIsEmpty(&q)) //< ignoring return value, because
                              //< (&q) definitely is not NULL
    {
#ifdef DUMP_QUEUE
        queueDump(&q);
#endif
        struct TreeNode* currentNode = queuePop(&q);
        assert(currentNode);
        printf("Node №%d\n", currentNode->val);
        if (currentNode->left)
            DO_OR_DIE(queuePush(&q, currentNode->left));
        if (currentNode->rght)
            DO_OR_DIE(queuePush(&q, currentNode->rght));
    }
    DO_OR_DIE(queueDtor(&q));
    return 0;
#undef DO_OR_DIE
}

int widthPassUnitTest(void)
{
    //Creating test tree
    struct TreeNode rr =   { 7, NULL, NULL };
    struct TreeNode rl =   { 6, NULL, NULL };
    struct TreeNode lr =   { 5, NULL, NULL };
    struct TreeNode ll =   { 4, NULL, NULL };
    struct TreeNode r  =   { 3, &rl,  &rr  };
    struct TreeNode l  =   { 2, &ll,  &lr  };
    struct TreeNode root = { 1, &l,   &r   };
    return treeWidthPass(&root);
}
