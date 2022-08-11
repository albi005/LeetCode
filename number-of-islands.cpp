#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<bool> visited(grid.size() * grid[0].size());
        int count = 0;
        for (int i = 0; i < grid[0].size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
            {
                if (visit(grid, visited, i, j))
                    count++;
            }
        }
        return count;
    }

    bool visit(vector<vector<char>>& grid, vector<bool>& visited, int i, int j) {
        if ((visited[j*grid[0].size() + i]) || (grid[j][i] == '0')) return false;
        visited[j*grid[0].size() + i] = true;
        if (i < (grid[0].size() - 1)) visit(grid, visited, i+1, j);
        if (j < (grid.size() - 1)) visit(grid, visited, i, j+1);
        if (i != 0) visit(grid, visited, i-1, j);
        if (j != 0) visit(grid, visited, i, j-1);
        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> isConnected{
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    auto result = (new Solution())->numIslands(isConnected);
    std::cout << result << "\n";
    return 0;
}
