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
    void solve(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL)
        {
            return;
        }
         solve(root->left,ans);
         ans.push_back(root->val);
         solve(root->right,ans);
    }
    TreeNode* build(vector<int>&ans,int l,int r)
    {
        if(l>r)
        {
            return NULL;
        }
        int mid=l+(r-l)/2;
        
        TreeNode*node= new TreeNode(ans[mid]);
        node->right=build(ans,mid+1,r);
        node->left=build(ans,l,mid-1);
        return node;



    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
        {
            return NULL;
        }
        if(root->right==NULL && root->left==NULL)
        {
            return root;
        }
        solve(root,ans);
        int l=0;
        int r=ans.size()-1;
         TreeNode* newroot= build(ans,l,r);

        return newroot;
    }
};