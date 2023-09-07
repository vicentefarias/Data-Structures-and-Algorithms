#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


bool palindromeCheck(string s){
    int n ; s.size();
    for(int i=0; i<n/2; i++){
        if (s[i]!=s[n-1-i])  return false;
    }
    return true;
}

int stringToInt(string s){
    int n ; n = stoi(s);
    return n;
}

int anagramCheck(string s1, string s2){
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1==s2;
}


 int main(){
    return 0;
 }
