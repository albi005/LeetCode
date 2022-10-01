#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> nums;
    unordered_map<int, vector<int>> oneSum;
    unordered_map<int, vector<vector<int>>> twoSumMemo;

    vector<vector<int>> twoSum(int sum){
        if (twoSumMemo.count(sum) != 0)
            return twoSumMemo[sum];

        vector<vector<int>> results;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            if (oneSum.count(sum - num) != 0){
                vector<int>& complements = oneSum[sum - num];
                for (int j = 0; j < complements.size(); j++)
                {
                    int complement = complements[j];
                    if (complement < i) {
                        vector<int> result{complement, i};
                        results.push_back(result);
                    }
                }
                
            }
        }
        
        twoSumMemo[sum] = results;
        return results;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> filteredNums;
        for (int i = 0; i < nums.size(); i++)
        {
            if (filteredNums.size() < 3 || filteredNums[filteredNums.size() - 3] != nums[i])
                filteredNums.push_back(nums[i]);
        }
        nums = filteredNums;

        this->nums = nums;

        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            oneSum[num].push_back(i);
        }

        set<vector<int>> results;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            vector<vector<int>> complements = twoSum(-num);

            for (int j = 0; j < complements.size(); j++)
            {
                vector<int> complement = complements[j];
                if (i < complement[0]){
                    vector<int> result {num, nums[complement[0]], nums[complement[1]]};
                    results.insert(result);
                }
            }
        }

        vector<vector<int>> vectorResults(results.begin(), results.end());
        return vectorResults;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{-1,0,1,2,-1,-4};
    auto result = (new Solution())->threeSum(nums);
    return 0;
}
