#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include "queue.h"

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* rght;
};

int treeWidthPass(struct TreeNode* root);

int widthPassUnitTest(void);
#endif
