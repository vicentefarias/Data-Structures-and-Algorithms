#include <iostream>
#include <vector>
using namespace std;

// Generate Power Set

int gereratePowerSet(vector<int>& st){
    int n=st.size();
    for(int i=0; i<(1<<n); i++){
        for(int j=0; j<n; j++) {
            if (i&(1<<j)) cout << st[j] << ",";
            }
    }
}

int reverseInt(int n){
    int ret = 0;
    while(n){
        ret = ret*10 + n%10;
        n /= 10;
    }    
    return 0;
}

int main(){
    return 0;
}