
class Solution {
public:
    int dfs(TreeNode* root,int& ans)
    {
        if(!root)
        {
            return 0;
        }
        int left=max(0,dfs(root->left,ans));
        int right=max(0,dfs(root->right,ans));
        ans=max(ans,root->val+left+right);
        return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
       dfs(root,ans);
       return ans;

        
    }
};
