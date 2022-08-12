#include<iostream>
using namespace std;
class Node
{
public:
	Node* next;
	int data;
};

class Queue
{
	int* array;
	int length;
	int front;
	int rear;

public:
	Queue(int s)
	{
		front = -1;
		rear = -1;
		length = s;
		array = new int[s];
	}

	void insert(int element)
	{
		if ((rear - front == length - 1) || (front - rear == 1))
		{
			cout << "\nOVERFLOW\n";
			return;
		}

		else if (rear == -1 && front == -1)
		{
			front = 0;
			rear = 0;
			array[rear] = element;
			return;
		}

		else
		{
			rear++;
			array[rear % length] = element;
			return;
		}
	}

	int deleteF()
	{
		if (front == -1)
		{
			cout << "\nUNDERFLOW\n";
			return -1;
		}

		else if (rear == front)
		{
			int temp = array[front];
			front = -1;
			rear = -1;
			return temp;
		}

		else
		{
			int temp = array[front % length];
			front++;
			return temp;
		}
	}

	//Print Function for The Queue
	void print()
	{
		int i = front;
		int m = 0;

		int size = rear - front;
		while (m <= size)
		{
			cout << array[i % length] << "\t";
			i++;
			m++;
		}
		cout << endl;
	}
};

void main()
{
	Queue Q(5);
	Q.insert(1);
	Q.insert(2);
	Q.insert(3);
	Q.insert(4);
	Q.insert(5);
	Q.print();
	Q.insert(6);	//Overflow Error -> Queue has max capacity
	cout << "1 : " << Q.deleteF() << endl;
	cout << "2 : " << Q.deleteF() << endl;
	Q.print();
	Q.insert(6);
	Q.print();

	system("PAUSE");
}