#include <iostream>
using namespace std;

template <typename T>
struct ListNode {
    T data;
    shared_ptr<ListNode<T>> next;
};

void insert_after(shared_ptr<ListNode<int>> node){
    shared_ptr<ListNode<int>> new_node;
    new_node->next = node->next;
    node->next = new_node;
}

shared_ptr<ListNode<int>> search(shared_ptr<ListNode<int>> L, int key){
    while(L && L->data!=key){
        L = L->next;
    }
    return L;
}

int main(){
    return 0;
}