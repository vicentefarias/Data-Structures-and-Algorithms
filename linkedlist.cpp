#include <iostream>
#include <memory>  // Include the header for shared_ptr

using namespace std;

template <typename T>
struct ListNode {
    T data;
    shared_ptr<ListNode<T>> next;
};

// Function to insert a new node after a given node
template <typename T>
void insert_after(shared_ptr<ListNode<T>> node) {
    shared_ptr<ListNode<T>> new_node = make_shared<ListNode<T>>();  // Allocate memory for the new node
    new_node->next = node->next;
    node->next = new_node;
}

// Function to search for a key in the linked list
template <typename T>
shared_ptr<ListNode<T>> search(shared_ptr<ListNode<T>> L, T key) {
    while (L && L->data != key) {
        L = L->next;
    }
    return L;
}

int main() {
    // Example usage
    shared_ptr<ListNode<int>> head = make_shared<ListNode<int>>();  // Create a dummy head node
    head->data = 0;

    // Insert a new node with data 1 after the head
    insert_after(head);
    head->next->data = 1;
    insert_after(head->next);
    head->next->next->data = 3;

    // Search for a node with data 1
    shared_ptr<ListNode<int>> result = search(head, 3);

    // Print the result
    if (result) {
        cout << "Node with key 3 found!" << endl;
    } else {
        cout << "Node with key 3 not found." << endl;
    }

    return 0;
}
