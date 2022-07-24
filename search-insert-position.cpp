#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int minInd = 0;
        int maxInd = nums.size() - 1;
        if (nums[maxInd] < target) return maxInd + 1;
        if (nums[minInd] > target) return 0;
        while (true)
        {
            int min = nums[minInd];
            int max = nums[maxInd];
            if (min == target) return minInd;
            if (max == target) return maxInd;
            if (minInd+1 == maxInd) return maxInd;
            if (minInd > maxInd) return minInd;
            if (minInd == maxInd) return maxInd;

            int middleInd = (maxInd + minInd) / 2;
            int middle = nums[middleInd];
            if (middle == target) return middleInd;
            if (middle < target) minInd = middleInd;
            else maxInd = middleInd;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vector1 = {3,5,7,9,10};
    cout << (new Solution())->searchInsert(vector1, 8);
    return 0;
}
