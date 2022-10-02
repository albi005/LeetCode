#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

void Explore(int prevDist, int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dists){
    int dist = prevDist + 1;
    if (x < 0 ||
        y < 0 ||
        x == grid.size() ||
        y == grid.size() ||
        grid[y][x] == 1 ||
        dist >= dists[y][x]) return;
    dists[y][x] = dist;
    Explore(dist, x + 1, y, grid, dists);
    Explore(dist, x + 1, y + 1, grid, dists);
    Explore(dist, x, y + 1, grid, dists);
    Explore(dist, x - 1, y + 1, grid, dists);
    Explore(dist, x - 1, y, grid, dists);
    Explore(dist, x - 1, y - 1, grid, dists);
    Explore(dist, x, y - 1, grid, dists);
    Explore(dist, x + 1, y - 1, grid, dists);
}

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> dists(grid.size(), vector<int>(grid.size(), 2147483647));
        Explore(0, 0, 0, grid, dists);
        int result = dists[grid.size() - 1][grid.size() - 1];
        return result == 2147483647 ? -1 : result;
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
