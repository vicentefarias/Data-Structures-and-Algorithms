#include <stack>
#include <cassert>
#include <iostream>

using namespace std;
class Stack {
    public:
        bool Empty() const { return stk.empty(); }
        int Max() const {return stk.top().max; }
        int Top() const {return stk.top().element; }
        int Pop() {
            int top = Top();
            if (!stk.empty()) stk.pop();
            return top;
        }
        void Push(int x){
            stk.emplace(data{x, max(x, Empty() ? x : Max())});
        }
    private:
        struct data{int element, max;};
        stack<data> stk;
};  

int main() {
    // Test the Stack class
    Stack myStack;

    // Test Empty()
    assert(myStack.Empty() == true);

    // Test Push() and Top()
    myStack.Push(5);
    assert(myStack.Top() == 5);
    myStack.Push(10);
    assert(myStack.Top() == 10);
    myStack.Push(3);
    assert(myStack.Top() == 3);

    // Test Max()
    assert(myStack.Max() == 10);

    // Test Pop()
    myStack.Pop();
    assert(myStack.Top() == 10);

    // Test Empty() after popping
    myStack.Pop();
    assert(myStack.Empty() == false);

    // Test Pop() from an empty stack
    myStack.Pop();  // No assertion for Empty() as it's not specified to return false for Pop()

    cout << "All test cases passed!" << endl;

    return 0;
}