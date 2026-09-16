
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*>Q;
        if(root==NULL)
        {
            return "";
        }
        Q.push(root);
        string s="";
        while(!Q.empty())
        {
            TreeNode* curr=Q.front();
            Q.pop();
            if(curr==nullptr)
            {
                s+="null,";
            }
            else
            {
                s+=to_string(curr->val)+",";
                Q.push(curr->left);
                Q.push(curr->right);
            }
        }
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="")
        {
            return NULL;
        }
        queue<TreeNode*>Q;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode *root=new TreeNode(stoi(str));
        Q.push(root);
        while(!Q.empty())
        {
            TreeNode* node=Q.front();
            Q.pop();
            getline(s,str,',');
            if(str!="null")
            {
                TreeNode* leftnode=new TreeNode(stoi(str));
                node->left=leftnode;
                Q.push(leftnode);
            }
            getline(s,str,',');
            if(str!="null")
            {
                TreeNode* rightnode=new TreeNode(stoi(str));
                node->right=rightnode;
                Q.push(rightnode);
            }
        }
        return root;
    }
};
