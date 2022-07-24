#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> target;
        for (int i = 0; i < s2.size(); i++)
        {
            char c = s2[i];
            if (target.count(c) == 0) {
                target[c] = 1;
            }
            else target[c]++;
        }
        
        return false;
    }
};

int main(int argc, char const *argv[])
{
    (new Solution())->checkInclusion("ab", "eidbaoo");
    return 0;
}
