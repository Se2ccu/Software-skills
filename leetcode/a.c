struct TreeNode {
    int val;
    struct TreeNode *Left;
    struct TreeNode *Right;
}

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int minDepth(struct TreeNode* root){
    if (NULL == root)
    {
        return 0;
    }

    if ((root->left == NULL) && (root->right == NULL)) {
        return 1;
    }

    /* 取左右叶节点的最小值 */
    int minDeepLen = __INT_MAX__;
    if (NULL != root->left)
    {
        minDeepLen = fmin(minDepth(root->left), minDeepLen);
    }

    if (NULL != root->right)
    {
        minDeepLen = fmin(minDepth(root->right), minDeepLen);
    }

    return minDeepLen + 1;
}

