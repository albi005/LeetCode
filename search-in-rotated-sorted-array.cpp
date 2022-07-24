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
    int min, max, size, k = 0;
    
    // Get new index
    int rotate(int index) {
        return (index - k + size) % (size);
    }

    int search(vector<int> &nums, int target)
    {
        size = nums.size();

        if (size == 0) return -1;

        min = 0;
        max = size - 1;

        while (true) {
            int mid = (min + max) / 2;
            if (nums[min] > nums[mid])
                max = mid;
            else
                min = mid;

            if (max-min <= 1) {
                break;
            }
        }

        if (nums[min] > nums[max])
            k = nums.size() - max;

        min = 0;
        max = nums.size() - 1;
        while (min <= max) {
            int mid = (min + max) / 2;
            if (nums[rotate(mid)] == target)
                return rotate(mid);
            else if (nums[rotate(mid)] < target)
                min = mid + 1;
            else
                max = mid - 1;
        }

        return -1;        
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{-10,0,1,2}; // 0,1,2
    auto result = (new Solution())->search(nums, -1);
    cout << result << "\n";
    return 0;
}
