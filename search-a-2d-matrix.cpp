#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int width = matrix[0].size();
        int height = matrix.size();
        int min = 0;
        int max = width*height;
        while (min <= max)
        {
            int mid = (min + max) / 2;
            int y = mid / width;
            int x = mid % width;
            if (y >= height) return false;
            int val = matrix[y][x];
            if (val == target)
                return true;
            else if (val < target)
                min = mid + 1;
            else
                max = mid - 1;
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix {{1}, {3}};
    auto result = (new Solution())->searchMatrix(matrix, 3);
    cout << result << "\n";
    return 0;
}
