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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        for (int i = 0; i < n; i++)
        {
            if (fast->next == nullptr) return head->next;
            fast = fast->next;
        }
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

int main(int argc, char const *argv[])
{
    string hello = "Hewwo, Worwd!";
    // (new Solution())->reverseWords(hello);
    return 0;
}
