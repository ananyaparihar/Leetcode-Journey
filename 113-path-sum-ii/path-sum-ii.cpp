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
    vector<vector<int>>final;
    void fun(TreeNode* root,int target,int sum,vector<int>res){
        if(root==NULL) return;
        sum=sum+=root->val;
        res.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(sum==target){
                final.push_back(res);
            }
            res.pop_back(); //backtracking
            return;
        }
        fun(root->left,target,sum,res);
        fun(root->right,target,sum,res);
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>res;
        fun(root,targetSum,0,res);
        return final;
    }
};