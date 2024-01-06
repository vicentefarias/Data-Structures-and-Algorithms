#include <map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int findJudge(int N, vector<vector<int>>& v){
    vector<vector<bool>> trust(N, vector<bool>(N,false));
    for(auto x: v){
        trust[x[0]-1][x[1]-1]=true;
    }

    map<int, int> ct;
    for(int i=0; i<N; i++){
        int curTrusts = 0;
        int curTrustedBy = 0;

        for(int j=0; j<N; j++){
            if (i==j) continue;
            
            // Check if i trusts j
            if (trust[i][j]) {
                curTrusts++;
            }

            // Check if j trusts i
            if (trust[j][i]) {
                curTrustedBy++;
            }
        }

        // Update counts in ct
        if (curTrusts == 0 && curTrustedBy == N - 1) {
            ct[i]++;
        }
    }

    vector<int> ret;
    for(int i=0; i<N; i++){
        if (ct[i]==1) {
            ret.push_back(i+1);
        }
    }

    if (ret.size()!=1) {
        return -1;
    }

    return ret[0];
}

int countServers(vector<vector<int>>& grid){
    int n = grid.size(), m = grid[0].size();
    vector<int> row(n, 0), col(m, 0);

    // Count the number of servers in each row and column
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (grid[i][j]) {
                row[i]++;
                col[j]++;
            }
        }
    }

    int ret = 0;

    // Count servers in rows or columns with at least one more server
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (grid[i][j] && (row[i] > 1 || col[j] > 1)) {
                ret++;
            }
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

// Function to test findJudge
void testFindJudge() {
    int N1 = 4;
    vector<vector<int>> trust1 = {{1,3},{1,4},{2,3},{2,4},{4,3}};
    int result1 = findJudge(N1, trust1);
    // Expected output: 3
    cout << "Judge for N=" << N1 << ": " << result1 << endl;

    int N2 = 3;
    vector<vector<int>> trust2 = {{1,3},{2,3},{3,1}};
    int result2 = findJudge(N2, trust2);
    // Expected output: -1
    cout << "Judge for N=" << N2 << ": " << result2 << endl;
}

// Function to test countServers
void testCountServers() {
    vector<vector<int>> grid1 = {{1, 0, 1}, {0, 1, 0}, {1, 1, 1}};
    int result1 = countServers(grid1);
    // Expected output: 6
    cout << "Count of Servers: " << result1 << endl;

    vector<vector<int>> grid2 = {{1, 0}, {1, 1}, {0, 1}, {0, 0}};
    int result2 = countServers(grid2);
    // Expected output: 4
    cout << "Count of Servers: " << result2 << endl;

    vector<vector<int>> grid3 = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
    int result3 = countServers(grid3);
    // Expected output: 0
    cout << "Count of Servers: " << result3 << endl;

    vector<vector<int>> grid4 = {{1, 0, 0}, {0, 0, 1}, {0, 1, 1}, {1, 1, 0}};
    int result4 = countServers(grid4);
    // Expected output: 6
    cout << "Count of Servers: " << result4 << endl;
}

// Function to test isBipartite
void testIsBipartite() {
    vector<vector<int>> graph1 = {{1,3},{0,2},{1,3},{0,2}};
    bool result1 = isBipartite(graph1);
    // Expected output: true
    cout << "Is Bipartite: " << (result1 ? "true" : "false") << endl;

    vector<vector<int>> graph2 = {{1,2,3},{0,2},{0,1,3},{0,2}};
    bool result2 = isBipartite(graph2);
    // Expected output: false
    cout << "Is Bipartite: " << (result2 ? "true" : "false") << endl;
}

int main() {
    testFindJudge();
    testCountServers();
    testIsBipartite();

    return 0;
}