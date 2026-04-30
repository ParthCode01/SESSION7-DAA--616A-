#include <iostream>
#include <climits>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* node = new Node(value);
        if (rear) {
            rear->next = node;
        } else {
            front = node;
        }
        rear = node;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return INT_MIN;
        }

        Node* temp = front;
        int value = temp->data;
        front = front->next;
        if (!front) {
            rear = nullptr;
        }
        delete temp;
        return value;
    }

    int peek() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return INT_MIN;
        }
        return front->data;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        for (Node* current = front; current != nullptr; current = current->next) {
            cout << current->data;
            if (current->next) {
                cout << " -> ";
            }
        }
        cout << "\n";
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue after enqueue: ";
    q.display();

    cout << "Dequeued: " << q.dequeue() << "\n";
    cout << "Front value: " << q.peek() << "\n";

    cout << "Queue now: ";
    q.display();

    return 0;
}
