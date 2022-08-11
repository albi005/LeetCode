#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size());

        int count = 0;
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (visited[i]) continue;

            count++;
            visit(isConnected, visited, i);
        }

        return count;
    }

    void visit(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
        if (visited[i]) return;
        visited[i] = true;
        for (int j = 0; j < isConnected.size(); j++)
        {
            if (isConnected[i][j]) {
                visit(isConnected, visited, j);
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> isConnected{{1,1,0},{1,1,0},{0,0,1}};
    auto result = (new Solution())->findCircleNum(isConnected);
    cout << result << "\n";
    return 0;
}
