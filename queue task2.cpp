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

class Queue {
    public:
        Node* rear;
        Node* front;
        
        Queue() {
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
                cout << "Inserting value: " << value << endl;
                return;
            }
            rear->next = newNode; 
            rear = newNode;  
            cout << "Inserting value: " << value << endl;
        }

        void dequeue() {
            if (front == NULL) {
                cout << "The queue is empty" << endl;
                return;
            }
            Node* temp = front;
            front = front->next; 
            cout << "Removing value: " << temp->data << endl;
            delete temp;  

            if (front == NULL) {
                rear = NULL;
            }
        }

        void display() {
            if (front == NULL) {
                cout << "The queue is empty" << endl;
            } else {
                cout << "Queue elements: ";
                Node* temp = front;
                while (temp != NULL) {
                    cout << temp->data << " ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
};

int main() 
{
    Queue q;

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