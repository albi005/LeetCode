#include <vector>
#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int length = 1;
        ListNode* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
            length++;
        }
        curr = head;
        for (int i = 0; i < length / 2; i++)
        {
            curr = curr->next;
        }
        return curr;
    }
};

int main(int argc, char const *argv[])
{
    string hello = "Hewwo, Worwd!";
    // (new Solution())->reverseWords(hello);
    return 0;
}
