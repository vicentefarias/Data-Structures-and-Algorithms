#include <vector>
#include <string>
#include <map>
using namespace std;

vector<int> partitionLabels(string S){
    vector<int> ret;
    int prev=-1, mx=0, n=S.size();
    map<char, int> mp;  
    for(int i=0; i<n; i++){
        mp[S[i]]=i;
    }
    for(int i=0;i<n;i++){
        mx = max(mp[S[i]], mx);
        if (i==mx) ret.push_back(i-prev), prev=i;
    }
    return ret;

}

int balancedStringSplit(string s){
    int ret=0, cur=0;
    for(char ch: s){
        if (ch=='R') cur++;
        else cur--;
        if (!cur) ret++;
    }
    return ret;
}
 
int main(){
    return 0;
}