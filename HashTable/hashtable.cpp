#include <iostream>
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
    // Test FindAnagrams
    vector<string> anagrams_input = {"listen", "silent", "enlist", "hello", "world", "dlrow"};
    vector<vector<string>> anagrams_result = FindAnagrams(anagrams_input);

    cout << "Anagrams in the input vector:" << endl;
    for (const auto &group : anagrams_result) {
        for (const auto &word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    // Test MaximumCount
    string max_count_input = "hello";
    int max_count_result = MaximumCount(max_count_input);

    cout << "Maximum count of a character in \"" << max_count_input << "\": " << max_count_result << endl;

    return 0;
}
