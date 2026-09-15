
class Solution {
public:
    string serialize(TreeNode* root)
    {
        if(!root)return "NULL";
        return "(" + to_string(root->val)+serialize(root->left)+serialize(root->right)+")";
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string ROOT=serialize(root);
        string SUBROOT=serialize(subRoot);
        return ROOT.find(SUBROOT)!=string::npos;
    }
};
