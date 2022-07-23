 class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans; 
        TreeNode *node = root, *prev = nullptr; 
        stack<TreeNode*> stk; 
        while (node || stk.size()) 
            if (node) {
                stk.push(node);
                node = node->left; 
            } else {
                node = stk.top(); 
                if (node->right && prev != node->right) node = node->right; 
                else {
                    ans.push_back(node->val); 
                    stk.pop(); 
                    prev = node; 
                    node = nullptr; 
                }
            }
        return ans; 
    }
};
