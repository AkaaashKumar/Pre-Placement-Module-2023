 class Solution
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        return hasPathSum(root, 0, sum);
    }

private:
    bool hasPathSum(TreeNode *cur, int sum, int target)
    {
        if (cur == NULL)
            return false;
        sum += cur->val;
        if (target == sum && cur->left == NULL && cur->right == NULL)
            return true;
        return hasPathSum(cur->left, sum, target) ||
               hasPathSum(cur->right, sum, target);
    }
};
