#include <stdlib.h>


// Helper function to traverse recursively
void preorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;

    result[(*index)++] = root->val;            // Visit root
    preorder(root->left, result, index);       // Visit left
    preorder(root->right, result, index);      // Visit right
}

// Main function called by LeetCode
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    // Allocate space for 100 nodes (max constraint)
    int* result = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;  // Initialize the size counter

    preorder(root, result, returnSize);  // Start recursion
    return result;
}
