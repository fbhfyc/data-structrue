#include <stdio.h>
#include <stdlib.h>

// 二叉树节点结构体
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 创建新节点
TreeNode* createNode(int val) {
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 插入节点
TreeNode* insert(TreeNode *root, int val) {
    if (root == NULL) {
        return createNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

// 查找节点
TreeNode* search(TreeNode *root, int val) {
    if (root == NULL || root->val == val) {
        return root;
    }
    if (val < root->val) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

// 删除节点
TreeNode* delete(TreeNode *root, int val) {
    if (root == NULL) {
        return root;
    }
    if (val < root->val) {
        root->left = delete(root->left, val);
    } else if (val > root->val) {
        root->right = delete(root->right, val);
    } else {
        if (root->left == NULL) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        TreeNode *temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->val = temp->val;
        root->right = delete(root->right, temp->val);
    }
    return root;
}

// 中序遍历
void inorderTraversal(TreeNode *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}

int main() {
    TreeNode *root = NULL;
    
    // 插入节点
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 18);

    // 中序遍历
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    // 查找节点
    int valToFind = 15;
    TreeNode *foundNode = search(root, valToFind);
    if (foundNode != NULL) {
        printf("Found %d\n", valToFind);
    } else {
        printf("%d not found\n", valToFind);
    }

    // 删除节点
    int valToDelete = 10;
    root = delete(root, valToDelete);
    printf("Inorder traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}

