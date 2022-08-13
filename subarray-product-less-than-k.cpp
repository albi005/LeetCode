#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

long subarrayCount(const int n)
{
    if (n < 1) return 0;
    return (n * (n + 1)) / 2;
}

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int first = 0;
        int last = 0;
        long long product;
        int lastChecked = -1;
        long long result = 0;

        while (true) {
            while (nums[first] >= k) {
                first++;
                if (first == nums.size()) return result;
            }
            last = first;
            product = nums[first];

            while ((last < (nums.size() - 1)) && product * nums[last + 1] < k) {
                last++;
                product *= nums[last];
            } 

            result += subarrayCount(last - first + 1);
            result -= subarrayCount(lastChecked - first + 1);

            lastChecked = last;
            product /= nums[first];
            first++;
            if (last == (nums.size() - 1)) break;

        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{29,76,8,75,22};
    auto result = (new Solution())->numSubarrayProductLessThanK(nums, 18);
    cout << result << "\n";
    return 0;
}
