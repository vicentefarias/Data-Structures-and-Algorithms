#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortByBits(vector<int> &v){
    sort(v.begin(), v.end()), [&](int x, int y) {
        int a=__builtin_popcount(x),b=__builtin_popcount(y);
        if (a==b) return x<y;
        return a<b;
    };
    return v;
}

int main(){
    return 0;
}