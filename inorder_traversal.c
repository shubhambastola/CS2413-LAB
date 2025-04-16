#include <stdio.h>
void Inorder(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) {
        return;
    }
    Inorder(root->left, arr, index);
    arr[(*index)++] = root->val;
    Inorder(root->right, arr, index);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(100 * sizeof(int));
    int index = 0;
    Inorder(root, arr, &index);
    *returnSize = index;
    return arr;
}
