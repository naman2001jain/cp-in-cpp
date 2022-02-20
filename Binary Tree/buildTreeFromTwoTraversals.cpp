#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
    public:
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};

int find(vector<int> inorder, int start, int end, int e){
    for(int i=start; i<=end;i++){
        if(inorder[i]==e){
            return i;
        }
    }
    return -1;
}

TreeNode* buildTree(vector<int> preorder, vector<int> inorder, int start, int end, int &curr){
    if(start>end){
        return NULL;
    }
    TreeNode* newnode = new TreeNode(preorder[curr]);
    curr++;
    
    if(start==end){
        return newnode;
    }
    else{
        int idx = find(inorder, start, end, newnode->val);
        newnode->left = buildTree(preorder, inorder, start, idx-1, curr);
        newnode->right = buildTree(preorder, inorder, idx+1, end, curr);
    }
    return NULL;
}
TreeNode* buildTree(vector<int> preorder, vector<int> inorder){
    int start = 0, end = preorder.size()-1;
    int curr=0;
    return buildTree(preorder,inorder, start, end, curr);
}

int main(){
    
}