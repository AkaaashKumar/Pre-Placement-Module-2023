class Solution {
public:
    void inorderTraversal(TreeNode* root) {
        if (root == nullptr) return;
        inorderTraversal(root->left);
        inorder_traversal.push_back(root->val);
        inorderTraversal(root->right);
    }

    bool findTarget(TreeNode* root, int k) {
        inorderTraversal(root);
        int head = 0;
        int tail = inorder_traversal.size() - 1;
        while (head < tail) {
            if (inorder_traversal[head] + inorder_traversal[tail] < k) ++head;
            else if (inorder_traversal[head] + inorder_traversal[tail] > k) --tail;
            else return true;
        }
        return false;
    }

private:
    vector<int> inorder_traversal;
};
