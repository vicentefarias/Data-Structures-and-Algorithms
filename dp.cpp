#include <iostream>
#include <vector>
using namespace std;

bool divisorGame(int N){
    const int mx=1007;
    vector<bool> dp(mx, false);
    for(int n=2; n<mx; n++){
        bool ok=false;
        for(int x=2; x<n; x++){
            if(n%x==0 && !dp[n-x]) ok = true;
        }
        dp[n] = ok;
    }
    return dp[N];
}

int longestCommonSubSequence(string s, string t){
    int n=s.size(), m=t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (s[i]==t[j]) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
            else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    return dp[n][m];
}

int main(){
    return 0;
}