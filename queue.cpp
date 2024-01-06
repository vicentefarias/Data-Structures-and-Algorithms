#include <iostream>
#include <cassert>
#include <stack>

class Queue {
public:
    void Enqueue(int x) {
        enqueue_.emplace(x);
    }

    int Dequeue() {
        if (dequeue_.empty()) {
            while (!enqueue_.empty()) {
                dequeue_.emplace(enqueue_.top());
                enqueue_.pop();
            }
        }
        int ret = dequeue_.top();
        dequeue_.pop();
        return ret;
    }

private:
    std::stack<int> enqueue_, dequeue_;
};

// Testing function for Queue class
void testQueue() {
    Queue myQueue;

    // Enqueue elements
    myQueue.Enqueue(1);
    myQueue.Enqueue(2);
    myQueue.Enqueue(3);

    // Dequeue elements
    int result1 = myQueue.Dequeue();
    assert(result1 == 1);

    int result2 = myQueue.Dequeue();
    assert(result2 == 2);

    // Enqueue more elements
    myQueue.Enqueue(4);
    myQueue.Enqueue(5);

    // Dequeue remaining elements
    int result3 = myQueue.Dequeue();
    assert(result3 == 3);

    int result4 = myQueue.Dequeue();
    assert(result4 == 4);

    int result5 = myQueue.Dequeue();
    assert(result5 == 5);

    std::cout << "All test cases passed!" << std::endl;
}

int main() {
    testQueue();

    return 0;
}
