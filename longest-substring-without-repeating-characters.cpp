#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <queue>


using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;
        queue<char> q;
        int max = 0;
        int curr = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (us.count(c) == 1) {
                while (true) {
                    char removed = q.front();
                    q.pop();
                    us.erase(removed);
                    curr--;
                    if (removed == c) break;
                }
            }
            q.push(c);
            us.insert(c);
            curr++;
            if (curr > max) max = curr;
        }
        return max;
    }
};

int main(int argc, char const *argv[])
{
    string hello = "abba";
    (new Solution())->lengthOfLongestSubstring(hello);
    return 0;
}
