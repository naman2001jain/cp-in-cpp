//problem link:- https://leetcode.com/problems/diameter-of-binary-tree/
class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
    
    int diameter(TreeNode* root, int &h){
        if(root==NULL){
            h = 0;
            return 0;
        }
        int lh = 0, rh = 0, ld = 0, rd = 0;
        ld = diameter(root->left, lh);
        rd = diameter(root->right, rh);
        h = max(lh,rh)+1;
        return max(lh+rh,max(ld,rd));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        int h = height(root);
        return diameter(root, h);
        
    }
};
