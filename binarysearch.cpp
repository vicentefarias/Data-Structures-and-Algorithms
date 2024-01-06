#include<iostream>
#include <vector>
#include <cassert>
using namespace std;

int binary_search(int t, const vector<int> &v){
    int low = 0, high = v.size()-1;
    while (low <= high){
        int mid = low + (high-low)/2;
        if (v[mid]==t) return mid;
        if (v[mid]<t) low=mid+1;
        else high = mid-1;
    }
    return -1;
}

int SearchFirstoOfK(const vector<int> &v, int k){
    int low=0, high=v.size(), ret= -1;
    while (low <= high) {
        int mid = low + (high-low)/2;
        if (v[mid]==k) ret = mid, high = mid-1;
        else if (v[mid]>k) high = mid-1;
        else low = mid + 1;
    }
    return ret;
}

double SquareRoot(double x){
    const double EPS = 1e-9;
    double low, high;
    if (x<1) low=0, high=1;
    else low=0, high=x;
    while(abs(low-high)>EPS){
        double mid=(low+high)/2;
        double val = mid*mid;
        if (val<x) low = mid;
        else high = mid;
    }
    return high;

}


// Function to perform binary search
void testBinarySearch() {
    vector<int> sortedVec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(binary_search(5, sortedVec1) == 4);

    vector<int> sortedVec2 = {2, 4, 6, 8, 10};
    assert(binary_search(8, sortedVec2) == 3);

    vector<int> sortedVec3 = {1, 3, 5, 7, 9};
    assert(binary_search(2, sortedVec3) == -1);

    cout << "All binary_search test cases passed!" << endl;
}

// Function to perform search for the first occurrence of k in a sorted array
void testSearchFirstOfK() {
    vector<int> sortedVec1 = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    assert(SearchFirstoOfK(sortedVec1, 4) == 4);

    vector<int> sortedVec2 = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    assert(SearchFirstoOfK(sortedVec2, 3) == 4);

    vector<int> sortedVec3 = {1, 2, 3, 4, 5};
    assert(SearchFirstoOfK(sortedVec3, 6) == -1);

    cout << "All SearchFirstoOfK test cases passed!" << endl;
}

// Function to perform square root calculation
void testSquareRoot() {
    assert(abs(SquareRoot(4) - 2.0) < 1e-6);
    assert(abs(SquareRoot(16) - 4.0) < 1e-6);
    assert(abs(SquareRoot(25) - 5.0) < 1e-6);
    assert(abs(SquareRoot(2) - 1.414213562) < 1e-6);  // Approximate value for square root of 2

    cout << "All SquareRoot test cases passed!" << endl;
}

int main() {
    // Run test cases
    testBinarySearch();
    testSearchFirstOfK();
    testSquareRoot();

    return 0;
}