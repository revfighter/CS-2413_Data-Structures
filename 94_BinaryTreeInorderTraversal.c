#include <stdlib.h> 

void inorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;                     
    inorder(root->left, result, index);          
    result[(*index)++] = root->val;            
    inorder(root->right, result, index);      
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;                             
    inorder(root, result, returnSize);          
    return result;                               
}
