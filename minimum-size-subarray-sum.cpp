#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = 0;
        int left = 0;
        int right = -1;
        int sum = 0;

        while (true) {
            if (sum >= target){
                if (result == 0 || ((right - left + 1) < result))
                    result = right - left + 1;
                sum -= nums[left];
                left++;
                continue;
            }
            right++;
            if (right == nums.size()) return result;
            sum += nums[right];
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{2,3,1,2,4,3};
    auto result = (new Solution())->minSubArrayLen(7, nums);
    cout << result << "\n";
    return 0;
}
