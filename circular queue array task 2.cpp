#include<iostream>
using namespace std;
const int q_cap=128;
class queue
{
	private:
		int myArray[q_cap];
		int front;
		int rear;

		public:
			queue()
			{
				front=rear=-1;
			}

			bool isfull()
			{
				if(rear==q_cap-1)
				{


					return true;

				}
				else{

					return false;
	}
			}

			bool isempty()
			{
				if(front==rear)
				{
					return true;
				}
				else
				{
					return false;
				}
			}


	void enqueue(int value)
	{
		if(isfull())
		{
			cout<<"Queue is full"<<endl;

		}
		else
		{
			myArray [q_cap]=value;
		}
	}

	int dequeue()
	{
		if(isempty())
		{
		cout<<"Queue is empty"<<endl;
		return -1;
	}
	else
	{
		return myArray[++front];
	}

    }

    int getfront()
    {
    	if(isempty())
    	{
    		cout<<"queue is empty"<<endl;
    		return -1;
		}
		else
		{
			return myArray[front+1];
		}
	}


		int display()
	{
		if(isempty())
		{
			cout<<"Queue is empty"<<endl;

		}
		else
		{
			cout<<"Display elements"<<endl;
			for(int i=front;i<rear;i++)
			{
				cout<<myArray[i]<<endl;
			}
		}
	}

};

int main()
{
	queue q;
	cout<<"Elements of array"<<endl;
	q.enqueue(4);
	q.enqueue(6);
	q.enqueue(7);
	q.enqueue(8);
	q.dequeue();
	q.dequeue();
	q.display();
	cout<<"QUEUE :"<<endl;

	q.enqueue(9);
	q.enqueue(2);
	q.dequeue();
	q.display();

}