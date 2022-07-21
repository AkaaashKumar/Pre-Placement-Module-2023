 class Solution {
public:
    Node* connect(Node* root) {
        Node* head = root; 
        while (head && head->left) {
            for (Node* node = head; node; node = node->next) {
                node->left->next = node->right; 
                if (node->next) node->right->next = node->next->left; 
            }
            head = head->left; 
        }
        return root; 
    }
};
