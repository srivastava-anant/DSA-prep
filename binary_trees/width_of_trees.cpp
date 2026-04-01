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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;

        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;

        q.push(make_pair(root, 0));

        while (!q.empty()) {
            int size = q.size();
            long long mini = q.front().second;

            long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                pair<TreeNode*, long long> frontNode = q.front();
                q.pop();

                TreeNode* node = frontNode.first;
                long long index = frontNode.second - mini;

                if (i == 0) first = index;
                if (i == size - 1) last = index;

                if (node->left != NULL) {
                    q.push(make_pair(node->left, 2 * index + 1));
                }

                if (node->right != NULL) {
                    q.push(make_pair(node->right, 2 * index + 2));
                }
            }

            ans = max(ans, last - first + 1);
        }

        return (int)ans;
    }
};
very important question 

