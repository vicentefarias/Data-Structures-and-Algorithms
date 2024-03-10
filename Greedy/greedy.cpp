#include <iostream>
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
 

// Function to test partitionLabels
void testPartitionLabels() {
    string testString1 = "abacdc";
    vector<int> result1 = partitionLabels(testString1);
    // Expected output: {3, 3}
    cout << "Partition Labels for \"" << testString1 << "\": ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    string testString2 = "abcde";
    vector<int> result2 = partitionLabels(testString2);
    // Expected output: {1, 1, 1, 1, 1}
    cout << "Partition Labels for \"" << testString2 << "\": ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;
}

// Function to test balancedStringSplit
void testBalancedStringSplit() {
    string testString1 = "RLRRLLRLRL";
    int result1 = balancedStringSplit(testString1);
    // Expected output: 4
    cout << "Balanced String Splits for \"" << testString1 << "\": " << result1 << endl;

    string testString2 = "RLLLLRRRLR";
    int result2 = balancedStringSplit(testString2);
    // Expected output: 3
    cout << "Balanced String Splits for \"" << testString2 << "\": " << result2 << endl;
}

int main() {
    // Run the testing functions
    testPartitionLabels();
    testBalancedStringSplit();

    return 0;
}
