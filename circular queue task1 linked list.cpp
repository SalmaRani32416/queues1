#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = NULL;
        }
};

class CircularQueue {
    public:
        Node* rear;
        Node* front;
        
        CircularQueue() {
            rear = NULL;
            front = NULL;
        }

        void empty() {
            if (front == NULL) {
                cout << "The queue is empty" << endl;
            } else {
                cout << "The queue is not empty" << endl;
            }
        }

        void enqueue(int value) {
            Node* newNode = new Node(value);
            if (rear == NULL) {
                front = rear = newNode;
                rear->next = front; 
                cout << "Inserting value: " << value << endl;
                return;
            }
            rear->next = newNode;
            rear = newNode;
            rear->next = front;  
            cout << "Inserting value: " << value << endl;
        }

        void dequeue() {
            if (front == NULL) {
                cout << "The queue is empty" << endl;
                return;
            }
            if (front == rear) { 
                cout << "Removing value: " << front->data << endl;
                delete front;
                front = rear = NULL;
            } else {
                Node* temp = front;
                front = front->next;
                rear->next = front;  
                cout << "Removing value: " << temp->data << endl;
                delete temp;
            }
        }

        void display() {
            if (front == NULL) {
                cout << "The queue is empty" << endl;
                return;
            }
            cout << "Queue elements: ";
            Node* temp = front;
            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != front);
            cout << endl;
        }
};

int main() 
{
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.enqueue(60);

    q.dequeue();
    q.dequeue();

    q.display();

    q.empty();

    return 0;
}