#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *prevGood = nullptr;
        if (head->val != head->next->val)
        {
            prev = head;
            prevGood = head;
            curr = head->next;
        }
        else
        {
            prev = head->next;
            curr = prev->next;
            while (true)
            {
                if (curr == nullptr) return nullptr;
                if (curr->val != prev->val && (curr->next == nullptr || curr->next->val != curr->val))
                {
                    if (curr->next == nullptr) return curr;
                    head = curr;
                    prev = curr;
                    prevGood = curr;
                    curr = curr->next;
                    break;
                }
                prev = curr;
                curr = curr->next;
            }
        }

        while (true)
        {
            if (curr->val != prev->val)
            {
                if (curr->next == nullptr)
                {
                    prevGood->next = curr;
                    return head;
                }
                else if (curr->next->val != curr->val)
                {
                    prevGood->next = curr;
                    prevGood = curr;
                }
            }
            prev = curr;
            curr = curr->next;
            if (curr == nullptr)
            {
                prevGood->next = nullptr;
                return head;
            }
        }

        return head;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(2))));
    auto result = (new Solution())->deleteDuplicates(head);
    cout << result << "\n";
    return 0;
}
