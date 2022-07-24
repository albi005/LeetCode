#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (true)
        {
            int middleIndex = (end + start) / 2;
            int middle = nums[middleIndex];
            if (middle < target) start = middleIndex + 1;
            else if (middle > target) end = middleIndex - 1;
            else return middleIndex;
            if (start == end && nums[start] == target) return start;
            if (start >= end) return -1;
            
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vector1 = {2,5};
    (new Solution())->searchInsert(vector1, 5);
    return 0;
}
