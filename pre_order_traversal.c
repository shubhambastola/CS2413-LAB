#include <stdio.h>

void preorder(struct TreeNode* root, int *arr, int *returnSize){
    if(root!=NULL){
        arr[(*returnSize)++]=root->val;
        preorder(root->left, arr, returnSize);
        preorder(root->right, arr, returnSize);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr=(int*)malloc(sizeof(int)*100);
    *returnSize=0;
    preorder(root, arr, returnSize);
    return arr;
    free(arr);
}