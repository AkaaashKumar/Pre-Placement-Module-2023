 class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans; 
        stack<TreeNode*> stk; stk.push(root); 
        while (stk.size()) {
            TreeNode* node = stk.top(); stk.pop(); 
            if (node) {
                ans.push_back(node->val); 
                stk.push(node->right); 
                stk.push(node->left); 
            }
        }
        return ans; 
    }
};
