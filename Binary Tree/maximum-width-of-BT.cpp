class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        unsigned long long ans = 0;

        queue<pair<TreeNode*, unsigned long long>> Q;
        Q.push({root, 0});

        while (!Q.empty()) {
            int size = Q.size();

            unsigned long long first = Q.front().second;
            unsigned long long last = Q.back().second;

            ans = max(ans, last - first + 1);

            for (int i = 0; i < size; i++) {

                TreeNode* node = Q.front().first;
                unsigned long long curr_id = Q.front().second;

                Q.pop();

                // Only change: make index relative to first node
                curr_id = curr_id - first;

                if (node->left)
                    Q.push({node->left, 2 * curr_id + 1});

                if (node->right)
                    Q.push({node->right, 2 * curr_id + 2});
            }
        }

        return ans;
    }
};
