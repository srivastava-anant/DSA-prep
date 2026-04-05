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
class Solution {
public:
    TreeNode* build(vector<int>& preorder, int& i, int minVal, int maxVal) {
        if (i >= preorder.size()) return NULL;

        if (preorder[i] < minVal || preorder[i] > maxVal) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[i++]);

        root->left = build(preorder, i, minVal, root->val);
        root->right = build(preorder, i, root->val, maxVal);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MIN, INT_MAX);
    }
};
