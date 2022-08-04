#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> target;
        for (int i = 0; i < p.size(); i++)
        {
            char c = p[i];
            if (target.count(c) == 0)
                target[c] = 1;
            else
                target[c]++;
        }

        unordered_map<char, int> counter;
        vector<int> results;
        int i = 0, j = -1;
        while (true)
        {
            if ((j - i) < ((int)p.size() - 1))
            {
                j++;
                if (j == s.size()) return results;
                char c = s[j];
                if (target.count(c) == 0)
                {
                    counter.clear();
                    i = j + 1;
                }
                else if (counter.count(c) == 0)
                    counter[c] = 1;
                else {
                    counter[c]++;
                    if (counter[c] > target[c]){
                        while (s[i] != c) {
                            counter[s[i]]--;
                            i++;
                        }
                        counter[s[i]]--;
                        i++;
                    } 
                }
            }
            else {
                results.push_back(i);
                counter[s[i]]--;
                i++;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    auto result = (new Solution())->findAnagrams("abacbabc", "abc");
    cout << result.size() << "\n";
    return 0;
}
