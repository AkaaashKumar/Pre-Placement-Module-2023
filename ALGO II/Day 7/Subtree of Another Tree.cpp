class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t)return true;
        if(!t)return true;
        if(!s)return false;
        function<bool(TreeNode*, TreeNode*)> equalTree;
        equalTree = [&] (TreeNode* s, TreeNode* t){
        if(!s && !t)return true;
        if(!s || !t)return false;
        return s->val==t->val && equalTree(s->left, t->left) && equalTree(s->right, t->right);
        };
         return equalTree(s, t) ? true : isSubtree(s->left, t) || isSubtree(s->right, t);
   }
};
