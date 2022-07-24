#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            temp[(i + k) % nums.size()] = nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = temp[i];
        }
        
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums {-1,-100,3,99};
    (new Solution())->rotate(nums, 2);
    return 0;
}
