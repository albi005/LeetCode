#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int offset = 0;
        for (int i = 0; i < nums.size() - offset; i++)
        {
            while (i+offset < nums.size() && nums[i + offset] == 0) offset++;
            if (i+offset == nums.size()) break;
            nums[i] = nums[i + offset];
        }
        for (int i = 0; i < offset; i++)
        {
            nums[nums.size()-i-1] = 0;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums {0,0,1,0};
    (new Solution())->moveZeroes(nums);
    return 0;
}
