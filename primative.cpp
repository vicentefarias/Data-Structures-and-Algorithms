#include <iostream>
#include <vector>

using namespace std;

// Generate Power Set
void generatePowerSet(const vector<int>& st) {
    int n = st.size();
    for (int i = 0; i < (1 << n); i++) {
        cout << "{ ";
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cout << st[j] << " ";
            }
        }
        cout << "}" << endl;
    }
}

// Reverse Integer
int reverseInt(int n) {
    int ret = 0;
    while (n) {
        ret = ret * 10 + n % 10;
        n /= 10;
    }
    return ret;
}

// Testing function for generatePowerSet
void testGeneratePowerSet() {
    cout << "Testing generatePowerSet:" << endl;

    vector<int> testSet1 = {1, 2, 3};
    cout << "Power Set of {1, 2, 3}:" << endl;
    generatePowerSet(testSet1);
    cout << endl;

    vector<int> testSet2 = {4, 5};
    cout << "Power Set of {4, 5}:" << endl;
    generatePowerSet(testSet2);
    cout << endl;
}

// Testing function for reverseInt
void testReverseInt() {
    cout << "Testing reverseInt:" << endl;

    int originalNumber1 = 12345;
    int reversedNumber1 = reverseInt(originalNumber1);

    cout << "Original Number: " << originalNumber1 << endl;
    cout << "Reversed Number: " << reversedNumber1 << endl;
    cout << endl;

    int originalNumber2 = 9876;
    int reversedNumber2 = reverseInt(originalNumber2);

    cout << "Original Number: " << originalNumber2 << endl;
    cout << "Reversed Number: " << reversedNumber2 << endl;
    cout << endl;
}

int main() {
    // Run individual testing functions
    testGeneratePowerSet();
    testReverseInt();

    return 0;
}
