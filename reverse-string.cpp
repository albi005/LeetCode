#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        for (int i = 0; i < s.size() / 2; i++)
        {
            temp = s[s.size() - 1 - i];
            s[s.size() - 1 - i] = s[i];
            s[i] = temp;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<char> hello {'H', 'e', 'l', 'l', 'o'};
    (new Solution())->reverseString(hello);
    return 0;
}
