#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0, j = 0;
        vector<vector<int>> results;
        while (i < firstList.size() && j < secondList.size()) {
            vector<int> a = firstList[i];
            vector<int> b = secondList[j];
            if (a[0] <= b[1] && a[1] >= b[0]) {
                results.push_back({max(a[0], b[0]), min(a[1], b[1])});
                if (a[1] > b[1])
                    j++;
                else
                    i++;
            }
            else if (a[0] > b[1])
                j++;
            else
                i++;
        }
        return results;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> firstList{{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> secondList{{1,5},{8,12},{15,24},{25,26}};
    auto result = (new Solution())->intervalIntersection(firstList, secondList);
    std::cout << result.size() << "\n";
    return 0;
}
