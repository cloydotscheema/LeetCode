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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        vector<TreeNode*> vt;
        TreeNode* curr = root;

        while(curr || !vt.empty()) {
            while(curr) {
                vt.push_back(curr);
                curr = curr->left;
            }
            curr = vt.back();
            vt.pop_back();
            result.push_back(curr->val);
            curr = curr->right;
        }
        return result;
    }
};