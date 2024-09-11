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
    void f(TreeNode* root, vector<int>& res, int level){
        if(root==NULL) return;
        if(res.size()==level) res.push_back(root->val);
        f(root->right, res, level+1);
        f(root->left, res, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        f(root, res, 0);
        return res;
    }
};