#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr;
    vector<int> arr2 = arr;
    vector<int>& arr3 = arr;

    arr.push_back(0);
    arr2.push_back(2);
    arr3.push_back(3);

    vector<int>* pArr = &arr;
    vector<int>* pArr2 = &arr2;
    vector<int>* pArr3 = &arr3;

    return 0;
}
