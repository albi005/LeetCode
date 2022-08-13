#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return areEqual(root, subRoot) || (root->left != NULL && isSubtree(root->left, subRoot)) || (root->right != NULL && isSubtree(root->right, subRoot));
    }

    bool areEqual(TreeNode* root, TreeNode* subRoot){
        if ((subRoot == NULL) && (root == NULL)) return true;
        if ((subRoot == NULL) || (root == NULL)) return false;
        if (root->val != subRoot->val) return false;
        return areEqual(root->left, subRoot->left) && areEqual(root->right, subRoot->right);
    }
};

int main(int argc, char const *argv[])
{
    auto result = (new Solution())->isSubtree();
    cout << result << "\n";
    return 0;
}
