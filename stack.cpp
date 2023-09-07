#include <stack>
using namespace std;

class Stack {
    public:
        bool Empty() const { return stk.empty(); }
        int Max() const {return stk.top().max; }
        int Top() const {return stk.top().element; }
        int Pop() {
            if (!stk.empty()) stk.pop();
        }
        void Push(int x){
            stk.emplace(data{x, max(x, Empty() ? x : Max())});
        }
    private:
        struct data{int element, max;};
        stack<data> stk;
};  