#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size()-1, j = t.size()-1;
        char a, b;
        int backsies = 0;
        while (true)
        {
            while (i >= 0)
            {
                if (s[i] != '#' && backsies == 0) break;
                if (s[i] == '#'){
                    backsies += 2;
                }
                i--;
                backsies--;
            }
            backsies = 0;

            while (j >= 0)
            {
                if (t[j] != '#' && backsies == 0) break;
                if (t[j] == '#'){
                    backsies += 2;
                }
                j--;
                backsies--;
            }
            backsies = 0;

            if (i < 0 || j < 0) break;

            a = s[i];
            b = t[j];
            
            if (a != b) return false;
            i--;
            j--;
        }
        
        return i < 0 && j < 0;
    }
};

int main(int argc, char const *argv[])
{
    auto result = (new Solution())->backspaceCompare("a#c###", "ad#c");
    cout << result << "\n";
    return 0;
}
