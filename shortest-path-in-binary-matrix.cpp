#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

// Inspired by https://leetcode.com/problems/shortest-path-in-binary-matrix/solutions/2641379/bfs-crystal-clear-explanation-with-comments/

vector<pair<int, int>> directions{
    {1,0},
    {1,1},
    {0,1},
    {-1,1},
    {-1,0},
    {-1,-1},
    {0,-1},
    {1,-1}
};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;

        queue<pair<int, int>> queue;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size()));
        int dist = 0;

        queue.push({0,0});
        while (queue.size() > 0)
        {
            dist++;
            int size = queue.size();

            while (size--) {
                pair<int, int> curr = queue.front();
                queue.pop();

                int curX = curr.first;
                int curY = curr.second;
                if (curX == grid.size() - 1 && curY == grid.size() - 1){
                    return dist;
                }

                for (int i = 0; i < directions.size(); i++)
                {
                    pair<int, int> dir = directions[i];
                    int x = curr.first + dir.first;
                    int y = curr.second + dir.second;
                    if (x >= 0 && y >= 0 && x < grid.size() && y < grid.size() && grid[y][x] == 0 && visited[y][x] == 0) {
                        queue.push({x, y});
                        visited[y][x] = 1;
                    }
                }
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid{
        {0,1},
        {1,0}
    };
    auto result = (new Solution())->shortestPathBinaryMatrix(grid);
    return 0;
}
