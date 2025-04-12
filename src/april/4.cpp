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
#include <utility>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    constexpr TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto dfs = [](TreeNode* node, auto&& self) -> std::pair<int, TreeNode*> {
            if (!node) {
                return {0, nullptr};
            }
            auto left = self(node->left, self);
            auto right = self(node->right, self);
            if (left.first > right.first) {
                return {left.first + 1, left.second};
            }
            if (left.first < right.first) {
                return {right.first + 1, right.second};
            }
            return {left.first + 1, node};
        };

        return dfs(root, dfs).second;
    }
};
