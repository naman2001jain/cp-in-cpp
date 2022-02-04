//problem link:- https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

class Solution {
public:
    
    void inorder(TreeNode* root, vector<int> &tree){
        if(root==NULL){
            return;
        }
        inorder(root->left, tree);
        tree.push_back(root->val);
        inorder(root->right, tree);
    }
    
    void merge(vector<int> &res, const vector<int> &tree1,const vector<int> &tree2){
        int i=0, j=0, m=tree1.size(), n=tree2.size();
        while(i<m && j<n){
            if(tree1[i]<tree2[j]){
                res.push_back(tree1[i]);
                i++;
            }
            else{
                res.push_back(tree2[j]);
                j++;
            }
        }
        if(i==m){
            while(j<n){
                res.push_back(tree2[j]);
                j++;
            }
        }
        if(j==n){
            while(i<m){
                res.push_back(tree1[i]);
                i++;
            }
        }
        
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        vector<int> tree1,tree2;
        inorder(root1, tree1);
        inorder(root2, tree2);
        merge(res, tree1, tree2);
        return res;
    }
};
