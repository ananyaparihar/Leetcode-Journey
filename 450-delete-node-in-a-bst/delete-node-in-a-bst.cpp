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
    TreeNode* remove(TreeNode* root,int key){
        if(root==NULL){
            return NULL;
        }
        else if(root->val<key){
            root->right=remove(root->right,key);
        }
        else if(root->val>key){
            root->left=remove(root->left,key);
        }
        else{
            if(root->left==NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            else{
                TreeNode* temp=root->right;
                while(temp->left!=NULL){
                    temp=temp->left;
                }
                root->val=temp->val;
                root->right = remove(root->right, temp->val);
            }

        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode*ans=remove(root,key);
        return ans;
    }
};