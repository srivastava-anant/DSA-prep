class Solution {
public:
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    void helper(TreeNode* root){
        if(root == NULL)return;
        helper(root->left);

        if(prev && prev->val > root->val){
            if(first== NULL){
                first = prev;
            }
            second = root;
        }
        prev = root;

        helper(root->right);
    }
    void recoverTree(TreeNode* root) {
        helper(root);
        int val = first->val;
        first->val = second->val;
        second->val = val;
    }
};
