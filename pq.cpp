#include <iostream>
#include <stack>
#include <algorithm> // for std::max

template <typename T>
class PriorityQueue {
public:
    bool Empty() const { return stk.empty(); }
    T Max() const { return stk.top().max; }
    T Top() const { return stk.top().element; }

    void Pop() {
        if (!stk.empty()) stk.pop();
    }

    void Push(const T& x) {
        stk.emplace(data{x, Empty() ? x : std::max(x, Max())});
    }

private:
    struct data { T element, max; };
    std::stack<data> stk;
};

int main() {
    PriorityQueue<int> pq;
    pq.Push(3);
    pq.Push(5);
    pq.Push(2);

    std::cout << "Max: " << pq.Max() << std::endl;
    std::cout << "Top: " << pq.Top() << std::endl;

    pq.Pop();
    std::cout << "After Pop:" << std::endl;
    std::cout << "Max: " << pq.Max() << std::endl;
    std::cout << "Top: " << pq.Top() << std::endl;

    return 0;
}

