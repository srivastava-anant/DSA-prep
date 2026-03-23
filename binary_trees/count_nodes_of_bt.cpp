class Solution {
public:
    int countNodes(TreeNode* root) {
         if(root == NULL){
            return 0;
        }
    int leftHt = countNodes(root->left);
     int rightHt =countNodes(root->right);
     return leftHt + rightHt +1;

    }
};
