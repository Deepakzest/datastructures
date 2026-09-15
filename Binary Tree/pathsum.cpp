
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
        {
            return false;
        }
        stack<int>sum_at_each_level;
        stack<TreeNode*>node_at_each_level;
        sum_at_each_level.push(root->val);
        node_at_each_level.push(root);
        while(!node_at_each_level.empty())
        {
            int sum=sum_at_each_level.top();
            sum_at_each_level.pop();
            TreeNode* node=node_at_each_level.top();
            node_at_each_level.pop();
            if(sum==targetSum&&node->left==nullptr&&node->right==nullptr)
            {
                return true;
            }
            if(node->left!=NULL)
            {
                node_at_each_level.push(node->left);
                sum_at_each_level.push(sum+node->left->val);
            }
            if(node->right!=NULL)
            {
                sum_at_each_level.push(sum+node->right->val);
                node_at_each_level.push(node->right);
            }
        }
        return false;
        
    }
};



