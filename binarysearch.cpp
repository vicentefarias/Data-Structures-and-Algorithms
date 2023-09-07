#include<iostream>
#include <vector>
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
}

double SquareRoot(double x){
    const double EPS = 1e-9;
    double low, high;
    if (x<1) low=0, high=1;
    else low=0, high=x;
    while(abs(low-high)<EPS){
        double mid=(low+high)/2;
        double val = mid*mid;
        if (val<x) low = mid;
        else high = mid;
    }
    return high;

}

int main(){
    return 0;
}