#include <stack>
using namespace std;

 class Queue{
    public:
        void Enqueue(int x){
            enqueue_.emplace(x);
        }
        int Dequeue(){
            if (dequeue_.empty()){
                while (!enqueue_.empty()){
                    dequeue_.emplace(enqueue_.top());
                    enqueue_.pop();
                }
            }
            int ret = dequeue_.top();
            dequeue_.pop();
            return ret;
        }
    private:
        stack<int> enqueue_, dequeue_;
 };