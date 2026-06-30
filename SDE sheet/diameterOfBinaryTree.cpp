#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    pair<int,int>diameterFast(TreeNode* root){
        pair<int,int> ans = {0,0};

        if(root == NULL){
            return ans;
        }

        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second;

        int diameter = max(op1,max(op2,op3));
        int height = max(left.second,right.second) +1 ;

        ans = {diameter,height};
        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return diameterFast(root).first;
    }
};