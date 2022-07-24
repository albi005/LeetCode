#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++)
        {
            int complement = target - numbers[i];
            auto it = lower_bound(numbers.begin() + i + 1, numbers.end(), complement);
            if (it != numbers.end() && *it == complement) {
                vector<int> result {i+1, (int)(it - numbers.begin()) + 1};
                return result;
            }
        }
        
        throw;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums {1,3,4,4};
    (new Solution())->twoSum(nums, 8);
    return 0;
}
