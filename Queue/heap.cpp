#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cassert>

// Implementation of SortKSortedData function
std::vector<int> SortKSortedData(std::vector<int>::const_iterator sbegin, std::vector<int>::const_iterator send, int k) {
    std::vector<int> ret;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (int i = 0; i < k && sbegin != send; i++) {
        pq.push(*sbegin++);
    }

    while (sbegin != send) {
        pq.push(*sbegin++);
        ret.push_back(pq.top());
        pq.pop();
    }

    while (!pq.empty()) {
        ret.push_back(pq.top());
        pq.pop();
    }

    return ret;
}

// Implementation of TopKFrequent function
std::vector<int> TopKFrequent(std::vector<int>& v, int k) {
    std::map<int, int> ct;

    for (const auto& x : v) {
        ct[x]++;
    }

    std::priority_queue<std::pair<int, int>> pq;

    for (const auto& it : ct) {
        pq.push(std::make_pair(it.second, it.first));  
    }

    std::vector<int> ret;

    for (int i = 0; i < k && !pq.empty(); i++) {
        ret.push_back(pq.top().second);
        pq.pop();
    }

    return ret;
}

// Your testing code remains the same



void testSortKSortedData() {
    std::vector<int> data = {3, 2, 1, 4, 6, 5};
    int k = 2;
    std::vector<int> result = SortKSortedData(data.begin(), data.end(), k);

    std::cout << "Sorted K Sorted Data: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void testTopKFrequent() {
    std::vector<int> data = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5};
    int k = 3;
    std::vector<int> result = TopKFrequent(data, k);

    std::cout << "Top K Frequent Elements: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    testSortKSortedData();
    testTopKFrequent();

    return 0;
}