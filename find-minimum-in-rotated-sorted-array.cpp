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
    int findMin(vector<int> &nums)
    {
        int min = 0;
        int max = nums.size() - 1;

        while (true)
        {
            int mid = (min + max) / 2;
            if (nums[mid] < nums[min])
                max = mid;
            else
                min = mid;

            if (max - min <= 1)
                break;
        }

        if (nums[min] > nums[max])
            min = max;
        else
            min = 0;

        return nums[min];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{3};
    auto result = (new Solution())->findMin(nums);
    cout << result << "\n";
    return 0;
}
