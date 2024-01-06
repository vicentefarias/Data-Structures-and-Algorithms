#include <iostream>
using namespace std;

// Pascal's Triangle - Compute binomial coefficient (n, m), for n,m less than 51

int binomialCoefficient(int n, int m){
    const int SIZE = 55;
    if (n<m) return -1;
    long long a[SIZE][SIZE];
    for(int i=0; i<SIZE; i++){
        a[i][0] = a[i][i] = 1;
        for(int j=1; j<i; j++){
            a[i][j] = a[i-1][j] + a[i-1][j-1];
        }
    }
    return a[n][m];
}

int main(){
    // Test cases
    int test1 = binomialCoefficient(5, 2);  // Expecting 10
    int test2 = binomialCoefficient(10, 3);  // Expecting 120
    int test3 = binomialCoefficient(0, 0);   // Expecting 1
    int test4 = binomialCoefficient(7, 7);   // Expecting 1
    int test5 = binomialCoefficient(8, 3);   // Expecting 56

    // Display results
    cout << "Test 1: " << test1 << " (Expecting 10)" << endl;
    cout << "Test 2: " << test2 << " (Expecting 120)" << endl;
    cout << "Test 3: " << test3 << " (Expecting 1)" << endl;
    cout << "Test 4: " << test4 << " (Expecting 1)" << endl;
    cout << "Test 5: " << test5 << " (Expecting 56)" << endl;

    return 0;
}
