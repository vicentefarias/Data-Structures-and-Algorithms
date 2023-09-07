#include <map>
#include <vector>
#include <queue>
using namespace std;

int findJudge(int N, vector<vector<int>>& v){
    vector<vector<bool>> trust(N, vector<bool>(N,false));
    for(auto x: v){
        trust[x[0]-1][x[1]-1]=true;
    }

    map<int, int> ct;
    for(int i=0; i<N; i++){
        int cur=0;
        for(int j=0; j<N; j++){
            if (i==j) continue;
            if (trust[j][i]) cur++;
        }
        if (cur==N-1) ct[i]++; 
    }

    vector<int> ret;
    for(int i=0; i<N; i++){
        if (ct[i]==2) ret.push_back(i+1);
    }
    if (ret.size()!=1) return -1;
    return ret[0];
}

int countServers(vector<vector<int>>& grid){
    int n=grid.size(), m=grid[0].size();
    map<int, int> row, col;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (grid[i][j]) row[i]++, col[i]++;
        }
    }

    int ret=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (!grid[i][j]) continue;
            if (row[i]>1 || col[j]>1) ret++;
        }
    }
    return ret;
}

bool isBipartite(vector<vector<int>>& graph){
    vector<int> col(graph.size(),-1);
    for(int i=0; i<graph.size(); i++){
        if (col[i]!=-1) continue;
        queue<int> q; q.push(i); col[i]=0;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(const auto& nxt: graph[cur]){
                if(col[nxt]==-1) col[nxt]=1-col[cur], q.push(nxt);
                if(col[cur]==col[nxt]) return false;
            }
        }
    }
    return true;
}

int main(){
    return 0;
}