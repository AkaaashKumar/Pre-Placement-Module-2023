class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        dfs(root, key);
        return root;
    }
    
    // Time: O(h)
    // Space: O(h)
    void dfs(TreeNode * & node, int key) {
        if (!node) return;
        if (key == node->val) {
            if (!node->left && !node->right) node = nullptr;
            else if (!node->left) node = node->right;
            else if (!node->right) node = node->left;
            else {
                // have both left and right child, find the successor
                auto p = node->right;
                while (p->left) p = p->left;
                node->val = p->val;
                dfs(node->right, p->val);
            }
        } else if (key < node->val) {
            dfs(node->left, key);
        } else {
            dfs(node->right, key);
        }
    }
};
