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

// Function to test divisorGame
void testDivisorGame() {
    int testValue1 = 4;
    bool result1 = divisorGame(testValue1);
    // Expected output: true
    cout << "Divisor Game for N=" << testValue1 << ": " << (result1 ? "true" : "false") << endl;

    int testValue2 = 7;
    bool result2 = divisorGame(testValue2);
    // Expected output: false
    cout << "Divisor Game for N=" << testValue2 << ": " << (result2 ? "true" : "false") << endl;
}

// Function to test longestCommonSubSequence
void testLongestCommonSubSequence() {
    string testString1 = "abcde";
    string testString2 = "ace";
    int result1 = longestCommonSubSequence(testString1, testString2);
    // Expected output: 3
    cout << "Longest Common Subsequence for \"" << testString1 << "\" and \"" << testString2 << "\": " << result1 << endl;

    string testString3 = "abc";
    string testString4 = "def";
    int result2 = longestCommonSubSequence(testString3, testString4);
    // Expected output: 0
    cout << "Longest Common Subsequence for \"" << testString3 << "\" and \"" << testString4 << "\": " << result2 << endl;
}

int main() {
    // Run the testing functions
    testDivisorGame();
    testLongestCommonSubSequence();

    return 0;
}