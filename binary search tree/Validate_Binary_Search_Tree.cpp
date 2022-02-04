//problem link:- https://leetcode.com/problems/validate-binary-search-tree/

class Solution {
public:
    
//     TreeNode* prev = NULL;
//     bool isValidBST(TreeNode* root) {
//         if(root!=NULL){
//             if(!isValidBST(root->left)) return false;
//             if(prev!=NULL and prev->val>=root->val) return false;
//             prev = root;
//             return isValidBST(root->right);
//         }
//         return true;
//     }
    
    void inorder(TreeNode* root, vector<int> &inorderTraversal){
        if(root==NULL){
            return;
        }
        inorder(root->left,inorderTraversal);
        inorderTraversal.push_back(root->val);
        inorder(root->right, inorderTraversal);
    }
    
    bool isValidBST(TreeNode* root) {
        
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        vector<int> inorderTraversal;
        inorder(root, inorderTraversal);
        for(int i=1;i<inorderTraversal.size(); i++){
            if(inorderTraversal[i-1]>=inorderTraversal[i]){
                return false;
            }else{
                continue;
            }
        }
        return true;
    }
};
