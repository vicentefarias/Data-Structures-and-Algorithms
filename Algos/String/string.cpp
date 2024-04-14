#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool palindromeCheck(string s){
    int n = s.size();
    for(int i = 0; i < n/2; i++){
        if (s[i] != s[n-1-i])  
            return false;
    }
    return true;
}

int stringToInt(string s){
    return stoi(s);
}

bool anagramCheck(string s1, string s2){
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

// Function to test palindromeCheck
void testPalindromeCheck(const string& input){
    bool isPalindrome = palindromeCheck(input);
    cout << "Is \"" << input << "\" a palindrome? " << (isPalindrome ? "Yes" : "No") << endl;
}

// Function to test stringToInt
void testStringToInt(const string& input){
    int convertedInt = stringToInt(input);
    cout << "Converted integer from string \"" << input << "\": " << convertedInt << endl;
}

// Function to test anagramCheck
void testAnagramCheck(const string& input1, const string& input2){
    bool areAnagrams = anagramCheck(input1, input2);
    cout << "\"" << input1 << "\" and \"" << input2 << "\" are " << (areAnagrams ? "anagrams" : "not anagrams") << endl;
}

int main(){
    // Test palindromeCheck
    testPalindromeCheck("madam");
    testPalindromeCheck("hello");

    // Test stringToInt
    testStringToInt("123");
    testStringToInt("-456");

    // Test anagramCheck
    testAnagramCheck("listen", "silent");
    testAnagramCheck("abc", "xyz");

    return 0;
}

