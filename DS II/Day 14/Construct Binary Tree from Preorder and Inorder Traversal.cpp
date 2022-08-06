class Solution
{
private:
    vector<int> preorderTraversal;
    vector<int> inorderTraversal;

    // right means the last valid item
    TreeNode* buildTree(int preLeft, int preRight, int inLeft, int inRight)
    {
        if(preLeft > preRight || inLeft > inRight) return nullptr;

        TreeNode *result = new TreeNode(preorderTraversal[preLeft]);

        int inorderRootIndex = find(inorderTraversal.begin(), inorderTraversal.end(), preorderTraversal[preLeft]) - inorderTraversal.begin();
        int leftChildNodesCount = inorderRootIndex - inLeft;
        int rightChildNodesCount = inRight - inorderRootIndex;

        result->left = buildTree(preLeft + 1, preLeft + leftChildNodesCount, inLeft, inorderRootIndex - 1);
        result->right = buildTree(preRight - rightChildNodesCount + 1, preRight, inorderRootIndex + 1, inRight);

        return result;
    }
public:
    // TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    TreeNode* buildTree(const vector<int> &i_preorderTraversal, vector<int> &i_inorderTraversal)
    {
        preorderTraversal = i_preorderTraversal;
        inorderTraversal = i_inorderTraversal;

        return buildTree(0, preorderTraversal.size() - 1, 0, inorderTraversal.size() - 1);
    } 
};
