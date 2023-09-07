#include<vector>
#include<queue>
#include <map>
using namespace std;

vector<int> SortKSortedData(vector<int>::const_iterator sbegin, vector<int>::const_iterator send, int k){
    vector<int> ret;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<k && sbegin!=send; i++){
        pq.push(*sbegin++);
    while(sbegin!=send){
            pq.push(*sbegin++);
            ret.push_back(pq.top());
            pq.pop();
        }
    while(!pq.empty()){
        ret.push_back(pq.top());
        pq.pop();
        }
    }
    return ret;
}

vector<int> TopKFrequent(vector<int> &v, int k){
    map<int, int> ct;
    for (const auto &x: v){
        ct[x]++;
    }
    priority_queue<pair<int, int>> pq;
    for(const auto &it: ct){
        pq.push(pair(it.first, it.second));
    }
    vector<int> ret(k);
    for(int i=0; i<k; i++){
        ret[i]=pq.top().second;
        pq.pop();
    }
}

int main(){
    return 0;
}