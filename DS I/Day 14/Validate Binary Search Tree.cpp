 class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root,NULL,NULL);
    }
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max)
    {
        if(root==NULL)
            return true;
        else if(min!=NULL && root->val<=min->val || max!=NULL && root->val>=max->val)
            return false;
        else if( helper(root->left, min, root) && helper(root->right, root, max))
            return true;
        return false;
    }
};
