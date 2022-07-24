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
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> result{-1, -1};

        if (nums.size() == 0) return result;

        // FIRST
        int min = 0;
        int max = nums.size() - 1;

        if (nums[0] == target)
            result[0] = 0;
        else if (nums[0] > target)
            return result;
        else while (true)
        {
            int mid = (min + max) / 2;
            if (nums[mid] >= target)
                max = mid;
            else
                min = mid;

            if (max - min <= 1)
            {
                if (nums[max] == target)
                {
                    result[0] = max;
                    break;
                }
                else
                    return result;
            }
        }

        // LAST
        min = 0;
        max = nums.size() - 1;

        if (nums[max] == target)
            result[1] = max;
        else if (nums[max] < target)
            return result;
        else while (true)
        {
            int mid = (min + max) / 2;
            if (nums[mid] <= target)
                min = mid;
            else
                max = mid;

            if (max - min <= 1)
            {
                if (nums[min] == target)
                {
                    result[1] = min;
                    break;
                }
                else
                    return result;
            }
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{-1, 0, 3, 5, 9, 12};
    auto result = (new Solution())->searchRange(nums, -1);
    cout << result[0] << ", " << result[1] << "\n";
    return 0;
}
