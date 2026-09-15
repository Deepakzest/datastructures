
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>Q;
        vector<vector<int>>result;
        if(root==NULL)
        {
            return result;
        }
        Q.push(root);
        while(!Q.empty())
        {
            vector<int>level;
            int size=Q.size();
            for(int i=0;i<size;i++)
            {
            TreeNode* node=Q.front();
            Q.pop();
            if(node->left!=NULL)
            {
                Q.push(node->left);
            }
            if(node->right!=NULL)
            {
                Q.push(node->right);
            }
            level.push_back(node->val);
            }
            result.push_back(level);
        }
        return result;
    }
};
