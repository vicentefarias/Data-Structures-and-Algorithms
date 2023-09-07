#include <vector>
#include <unordered_map>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<string>> FindAnagrams(const vector<string> &v){
    unordered_map<string, vector<string>> umap;
    for(const string &s: v){
        string t=s;
        sort(t.begin(), t.end());
        umap[t].emplace_back(s);
    }

    vector<vector<string>> ret;
    for(const auto & [key,val]: umap){
        if (val.size()>1) ret.emplace_back(val);
    }
    return ret;
}

int MaximumCount(const string &s){
    int ret=0;
    map<char, int> mp;
    for(char ch: s){
        ret = max(ret, ++mp[ch]);
    }
    return ret;
}

int main(){
    return 0;
}