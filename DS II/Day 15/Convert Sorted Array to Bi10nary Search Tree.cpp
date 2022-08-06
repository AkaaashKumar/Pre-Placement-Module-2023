class Solution {
    public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* head = NULL;
        helper(head, 0, nums.size()-1, nums);
        return head;
    }
    
    void helper(TreeNode* node, int left, int right, vector<int> nums) {
        if(left>right) 
            return ;
        int mid = (left+right)/2;
        TreeNode* temp = new TreeNode(nums[mid]);
        node = temp;
        helper(temp->left, left, mid-1, nums);
        helper(temp->right, mid+1, right, nums);
    }
};
