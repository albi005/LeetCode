#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0) return;
        int ind = 0, val, nextVal, nextInd;
        val = nums[ind];
        while (true)
        {
            nextInd = (ind + 1) % nums.size();
            nextVal = nums[nextInd];
            nums[nextInd] = val;
            val = nextVal;
            ind = nextInd;
            if (ind == 0) 
                break;
        }
        rotate(nums, k-1);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums {-1,-100,3,99};
    (new Solution())->rotate(nums, 2);
    return 0;
}
