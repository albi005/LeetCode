#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct Triplet
{
    int a;
    int b;
    int c;

    Triplet(int a, int b, int c) : a(a), b(b), c(c){};

    Triplet(Triplet* t) {
        a = t->a;
        b = t->b;
        c = t->c;
    }

    bool operator==(Triplet other) const {
        return other.a == a && other.b == b && other.c == c;
    }
};

namespace std {
    template<>
    struct hash<Triplet> {
        const size_t operator()(const Triplet& c) const
        {
            return std::hash<int>()(c.a) ^ std::hash<int>()(c.b) ^ std::hash<int>()(c.c);   
        }
    };
}

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        unordered_set<Triplet> candidates;
        for (int i = 0; i < nums.size()-2; i++)
        {
            for (int j = i+1; j < nums.size()-1; j++)
            {
                for (int k = j+1; k < nums.size(); k++)
                {
                    if ((nums[i] + nums[j] + nums[k]) == 0)
                        candidates.emplace(new Triplet(nums[i], nums[j], nums[k]));
                }
            }
        }

        vector<vector<int>> results;

        for (auto &&i : candidates)
        {
            results.push_back({i.a, i.b, i.c});
        }
        
        return results;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{0,0,0,0};
    auto result = (new Solution())->threeSum(nums);
    cout << result.size() << "\n";
    return 0;
}
