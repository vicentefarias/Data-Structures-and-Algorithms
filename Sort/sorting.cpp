#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

vector<int> sortByBits(vector<int> &v) {
    sort(v.begin(), v.end(), [&](int x, int y) {
        int a = __builtin_popcount(x), b = __builtin_popcount(y);
        if (a == b) return x < y;
        return a < b;
    });
    return v;
}


int main() {
    // Test sortByBits
    vector<int> testVector1 = {3, 8, 7, 6, 5, 4, 9, 1, 2, 0};
    vector<int> sortedVector1 = sortByBits(testVector1);
    vector<int> expectedVector1 = {0, 1, 2, 4, 8, 3, 5, 6, 9, 7};
    assert(sortedVector1 == expectedVector1);

    vector<int> testVector2 = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
    vector<int> sortedVector2 = sortByBits(testVector2);
    vector<int> expectedVector2 = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

    assert(sortedVector2 == expectedVector2);

    cout << "All test cases passed!" << endl;

    return 0;
}
