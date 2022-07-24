#include <vector>
#include <iostream>

using namespace std;

bool isBadVersion(int num){
    return num >= 4;
}

uint firstBadVersion(uint n){
    uint min = 0;
    uint max = n;
    while (min < max)
    {
        int mid = min/2 + max/2;
        if (isBadVersion(mid)) max = mid;
        else min = mid + 1;
    }
    return max;
}

int main(int argc, char const *argv[])
{
    cout << firstBadVersion(5) << "\n";
    return 0;
}
