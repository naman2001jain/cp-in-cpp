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

vector<vector<int> > printAllPaths(TreeNode* root){
    vector<vector<int> > res;
    vector<int> pathSoFar;
    
} 

int main(){

}