/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *getMirror(TreeNode *ori, TreeNode *mir)
    {
        if (ori == NULL)
            return mir;
        mir = new TreeNode(ori->val);
        if (ori->left != NULL)
            mir->right = getMirror(ori->left, mir->right);
        if (ori->right != NULL)
            mir->left = getMirror(ori->right, mir->left);
        return mir;
    }
    bool compareTwoTree(TreeNode *tree1, TreeNode *tree2)
    {
        if (tree1 == NULL && tree2 == NULL)
            return true;
        if (tree1 == NULL && tree2 != NULL)
            return false;
        if (tree1 != NULL && tree2 == NULL)
            return false;
        if (tree1->val != tree2->val)
            return false;
        return compareTwoTree(tree1->left, tree2->left) &&
               compareTwoTree(tree1->right, tree2->right);
    }
    bool isSymmetric(TreeNode *root)
    {
        TreeNode *mir = getMirror(root, NULL);
        return compareTwoTree(root, mir);
    }
};
