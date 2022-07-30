#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int first = 0;
        int last = height.size() - 1;

        long long max = 0;
        while (first < last)
        {
            long long area = (last-first) * min(height[first], height[last]);
            if (area > max) max = area;

            if (height[first] < height[last])
                first++;
            else
                last--;
        }
        return max;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{1,8,6,2,5,4,8,3,7};
    auto result = (new Solution())->maxArea(nums);
    cout << result << "\n";
    return 0;
}
