/*
183. LCA of BST: Given a binary search tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the BST.
*/

/**********************************************************

    Following is the Binary Tree Node class structure

    template <typename T>
    class BinaryTreeNode {
        public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

int getLCA(BinaryTreeNode<int> *root, int val1, int val2)
{

    if (root == NULL)
        return -1;
    if (root->data == val1 || root->data == val2)
        return root->data;

    int left = getLCA(root->left, val1, val2);
    int right = getLCA(root->right, val1, val2);

    if (left == -1 && right == -1)
        return -1;
    else if (left != -1 && right == -1)
        return left;
    else if (left == -1 && right != -1)
        return right;
    else
        return root->data;
}