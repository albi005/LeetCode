#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;

        if (root->left != NULL) {
            if (root->right != NULL)
                root->left->next = root->right;
            else
                root->left->next = findNext(root);
        }
        if (root->right != NULL)
            root->right->next = findNext(root);

        connect(root->right);
        connect(root->left);

        return root;
    }

    Node* findNext(Node* parent) {
        Node* head = parent->next;
        while (head != NULL) {
            if (head->left != NULL) return head->left;
            if (head->right != NULL) return head->right;
            head = head->next;
        }
        return NULL;
    }
};

int main(int argc, char const *argv[])
{
    auto result = (new Solution())->connect(nums);
    cout << result.size() << "\n";
    return 0;
}
