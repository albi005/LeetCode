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
        int backsies;
        while (i != 0 && j != 0)
        {
            while (i >= 0 && s[i] == '#'){
                backsies = 0;
                while (i >= 0)
                {
                    a = s[i];
                    if (a != '#') break;
                    i--;
                    backsies++;
                }
                while (backsies > 0 && i > 0)
                {
                    i--;
                    if (s[i] != '#') i--;
                }                
            }

            while (j >= 0 && t[j] == '#'){
                backsies = 0;
                while (j >= 0)
                {
                    b = t[j];
                    if (b != '#') break;
                    j--;
                    backsies++;
                }
                while (backsies > 0 && j > 0)
                {
                    j--;
                    if (t[j] != '#') j--;
                }
                
            }

            if (i < 0 || j < 0) break;

            a = s[i];
            b = t[j];
            
            if (a != b) return false;
            i--;
            j--;
        }
        
        return i <= 0 && j <= 0;
    }
};

int main(int argc, char const *argv[])
{
    auto result = (new Solution())->backspaceCompare("xywrrmp", "xywrrmu#p");
    cout << result << "\n";
    return 0;
}
