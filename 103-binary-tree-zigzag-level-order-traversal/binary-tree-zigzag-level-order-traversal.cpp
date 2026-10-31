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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        queue<TreeNode*>q;
        if(root==NULL)return res;
        q.push(root);
        while(!q.empty()){
            int lvlsize=q.size();
            vector<int>tmp;
            while(lvlsize--){
                TreeNode* t=q.front();
                q.pop();
                tmp.push_back(t->val);
                if(t->left!=NULL){
                    q.push(t->left);
                }
                if(t->right!=NULL){
                    q.push(t->right);
                }
            }
            res.push_back(tmp);
        }
        vector<vector<int>>res_z;
        for(int i=0;i<res.size();i++){
            vector<int>v;
            v=res[i];
            if(i%2!=0){
                std::reverse(v.begin(),v.end());
                res_z.push_back(v);
            }else{
                res_z.push_back(v);
            }
        }
        return res_z;
    }
};