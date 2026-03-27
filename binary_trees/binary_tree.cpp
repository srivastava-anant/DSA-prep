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
    void allpath(TreeNode* root, string path, vector<string>& ans) {
        if (root == NULL) return;

        // add current node to path
        if (path == "") path = to_string(root->val);
        else path += "->" + to_string(root->val);

        // if leaf node → store result
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }

        // go left and right
        allpath(root->left, path, ans);
        allpath(root->right, path, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        allpath(root, "", ans);
        return ans;
    }
};
