#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int min = 0;
        int max = nums.size() - 1;

        while (true) {
            int mid = (min + max) / 2;
            int midVal = nums[mid];
            if ((mid == 0 || nums[mid-1] < midVal) && (mid == nums.size()-1 || nums[mid+1] < midVal))
                return mid;
            else if (mid != 0 && nums[mid-1] > midVal)
                max = mid - 1;
            else
                min = mid + 1;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{5,4};
    auto result = (new Solution())->findPeakElement(nums);
    cout << result << "\n";
    return 0;
}
