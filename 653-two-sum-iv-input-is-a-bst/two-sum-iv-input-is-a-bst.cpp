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
    stack<TreeNode*>asc;
    stack<TreeNode*>desc;
    TreeNode*getsmall(){
        if(asc.empty()){
            return NULL;
        }
        TreeNode* small=asc.top();
        asc.pop();
        TreeNode* rightchild=small->right;
        while(rightchild){
            asc.push(rightchild);
            rightchild=rightchild->left;
        }
        return small;
    }
    TreeNode* getlarge(){
        if(desc.empty()){
            return NULL;
        }
        TreeNode* large=desc.top();
        desc.pop();
        TreeNode* leftchild=large->left;
        while(leftchild){
            desc.push(leftchild);
            leftchild=leftchild->right;
        }
        return large;
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL){
            return false;
        }
        TreeNode* t=root;
        while(t){
            asc.push(t);
            t=t->left;
        }
        t=root;
        while(t){
            desc.push(t);
            t=t->right;
        }
        TreeNode* i=getsmall();
        TreeNode* j=getlarge();
        while(i && j && i!=j && i->val <= j->val){
            int sum=i->val+j->val;
            if(sum==k){
                return true;
            }
            if(sum>k){
                j=getlarge();
            }
            else{
                i=getsmall();
            }
        }
        return false;
    }
};