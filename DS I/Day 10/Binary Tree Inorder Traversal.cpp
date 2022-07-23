class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans; 
        TreeNode* node = root; 
        stack<TreeNode*> stk; 
        while (node || stk.size()) 
            if (node) {
                stk.push(node); 
                node = node->left; 
            } else {
                node = stk.top(); stk.pop(); 
                ans.push_back(node->val); 
                node = node->right; 
            }
        return ans; 
    }
};
