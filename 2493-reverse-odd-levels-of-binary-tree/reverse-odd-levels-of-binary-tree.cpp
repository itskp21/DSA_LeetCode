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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0; // root is at level 0

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> nodesAtLevel;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                nodesAtLevel.push_back(node);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Reverse node values at odd levels
            if (level % 2 != 0) {
                int left = 0, right = nodesAtLevel.size() - 1;
                while (left < right) {
                    swap(nodesAtLevel[left]->val, nodesAtLevel[right]->val);
                    ++left;
                    --right;
                }
            }

            ++level; // Move to the next level
        }

        return root;
    }
};