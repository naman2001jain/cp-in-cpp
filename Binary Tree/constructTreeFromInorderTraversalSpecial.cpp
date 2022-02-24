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


int findMax(const vector<int> &inorder, int start, int end){
    int maxind = start;
    for(int i=start+1; i<=end;i++){
        if(inorder[maxind] < inorder[i]){
            maxind = i;
        }
    }
    return maxind;
}

TreeNode* constructTree(vector<int> inorder, int start, int end){
    if(start>end){
        return NULL;
    }
    int maxind = findMax(inorder, start, end);
    TreeNode* root = new TreeNode(inorder[maxind]);
    
    root->left = constructTree(inorder, start, maxind-1);
    root->right = constructTree(inorder, maxind+1, end);
    return root;
}

TreeNode* constructTree(vector<int> inorder){
    int start = 0, end = inorder.size()-1;
    return constructTree(inorder, start, end);
}

void printInorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->val<<",";
    printInorder(root->right);
}

int main(){
    int n;
    cin>>n;
    vector<int> inorder(n);
    for(int i=0;i<n;i++){
        cin>>inorder[i];
    }
    printInorder(constructTree(inorder));
}