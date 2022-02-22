#include<iostream>
#include<queue>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//level wise input
TreeNode* takeInput(){
    cout<<"enter data"<<endl;
    int temp;
    cin>>temp;
    TreeNode* root = new TreeNode(temp);
    queue<TreeNode* > q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        int leftchild, rightchild;
        cout<<"enter left and right child of "<<temp->val<<endl;
        cin>>leftchild>>rightchild;
        if(leftchild!=-1){
            TreeNode* leftnode = new TreeNode(leftchild);
            q.push(leftnode);
            temp->left = leftnode;
        }
        if(rightchild!=-1){
            TreeNode* rightnode = new TreeNode(rightchild);
            q.push(rightnode);
            temp->right = rightnode;
        }
         
    }
    return root;
}
//recursive approach
// TreeNode* takeInput(){
//     int rootData;
//     cout<<"enter data\n";
//     cin>>rootData;
//     if(rootData==-1){
//         return NULL;
//     }
//     TreeNode* root = new TreeNode(rootData);
//     TreeNode* left = takeInput();
//     TreeNode* right = takeInput();
//     root->left = left;
//     root->right = right;
//     return root;
// }

void printInorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<":";
    if(root->left!=NULL){
        cout<<"L"<<root->left->val;
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->val;
    }
    cout<<endl;
    printInorder(root->left);
    printInorder(root->right);
}

int main(){

    TreeNode* root = takeInput();
    printInorder(root);
}