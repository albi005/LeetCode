#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int first = 0, last;
        char temp;
        for (int i = 0; i < s.size(); i++)
        {
            if (i == (s.size() - 1) || s[i+1] == ' ') {
                last = i;
                for (int i = 0; i < (last - first + 1) / 2; i++)
                {
                    temp = s[last - i];
                    s[last - i] = s[first + i];
                    s[first + i] = temp;
                }
                first = last + 2;
            }
        }
        return s;
    }
};
int main(int argc, char const *argv[])
{
    string hello = "Hewwo, Worwd!";
    (new Solution())->reverseWords(hello);
    return 0;
}
