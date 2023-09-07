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
            a[i][j] = a[i][j-1] + a[i-1][j-1];
        }
    }
    return a[n][m];
}

int main(){
    return 0;
}