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
class bstIterator
{
   public:
    bool reverse;
    stack<TreeNode*>s;
    void pushAll(TreeNode* node)
    {
        while(node!=NULL)
       { 
           s.push(node);
            if(reverse)
            {
               node=node->right; 
            }
            else{
                node=node->left;
            }
       }
    }
    bstIterator(TreeNode* node,bool isreverse)
    {
        reverse=isreverse;
        pushAll(node);
    }

   int next()
   {
       TreeNode* a=s.top();
       s.pop();
       if(reverse)
       {
        if(a->left)
       { s.push(a->left);
        pushAll(a->left);
       }
       }
       else
       {
         if(a->right)
          {s.push(a->right);
          pushAll(a->right);
          }
       }
       return a->val;

   
}
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)
        {
            return false;
        }
        bstIterator l(root,false);
        bstIterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j)
        {
            if(i+j==k)
            {
                return true;
            }
            else
            {
                if(i+j>k)
                {
                    j=r.next();
                }
                else
                {
                    i=l.next();
                }
            }
        }
    

        return false;
        
    }
   

};