#include<iostream>
using namespace std;

class Queue {
    public:
        int size = 5;
        int arr[5];  
        int rear, front;

        Queue() {
            rear = -1;
            front = -1;
        }

        void empty() {
            if (front == rear) {
                cout << "The queue is empty" << endl;
            } else {
                cout << "The queue is not empty" << endl;
            }
        }

        void full() {
            if (rear == size - 1) {
                cout << "The queue is full" << endl;
            } else {
                cout << "The queue is not full" << endl;
            }
        }

        void enqueue(int value) {
            if (rear == size - 1) {
                cout << "The queue is full" << endl;
            } else {
                cout << "Inserting value: " << value << endl;
                arr[++rear] = value;
            }
        }

        void dequeue() {
            if (front == rear) {
                cout << "The queue is empty" << endl;
            } else {
                cout << "Removing value: " << arr[++front] << endl;
            }
        }

        void display() {
            if (front == rear) {
                cout << "The queue is empty" << endl;
            } else {
                cout << "Queue elements: ";
                for (int i = front + 1; i <= rear; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
};


int main(){

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
  q.full();
     q.empty();

    return 0;
}