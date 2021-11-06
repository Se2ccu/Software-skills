char result[201];
char * longestCommonPrefix(char ** strs, int strsSize){
    for (int i = 0; i < strlen(strs[0]); i++) {
        char sameChar = strs[0][i];
        for (int j = 0; j < strsSize; j++) {
            if (strs[j][i] != sameChar)
        }
    }
    return result;
}

void preorder(struct TreeNode *root, int *res)
{
    if (root == NULL) {
        return;
    }

    *res = root->val;
    preoder(root->left, res);
    preoder(root->right, res);

    return;
}

int *preorderTraversal(struct TreeNode* root, int *returnSize)
{
    int *res = (int *)malloc(sizeof(int) * 100);
    *returnSize = 0;
    preorder(root, res);
    return res;

}

#ifdef BIG_ENDIAN
typedef struct
{
    int a:2;
    int b:10;
    int c:12;
    int d:8;
} BigmapStru;
#else
typedef struct
{
    int d:8;
    int c:12;
    int b:10;
    int a:2;
} SmallmapStru;
#endif

BigmapStru test;
ntohl(test);