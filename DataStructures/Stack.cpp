#include <iostream>
#include <fstream>
#include<cstring>
using namespace std;

template<class T>
class Stack {
	class Node {
	public:
		T data;
		Node* next;
	};
	Node* head;
	Node* tail;
	int size1;

public:
	Stack() {
		size1 = 0;
		head = nullptr;
		tail = nullptr;
	}
	Stack(Stack& obj) {          //copy constructor
		head = nullptr;
		tail = nullptr;
		Node* curr = obj.head;
		while (curr != nullptr) {
			insertatend(curr->data);
			curr = curr->next;
		}
	}
	Stack<T>& operator=(Stack& obj) {    //assignment operator
		while (size != 0) {
			deleteatend();
		}
		head = nullptr;
		tail = nullptr;
		Node* curr = obj.head;
		while (curr != nullptr) {
			insertatstart(curr->data);
			curr = curr->next;
		}
		return *this;
	}
	void insertatstart(T const d) {
		Node* temp = new Node;
		temp->data = d;
		if (head == nullptr) {
			head = tail = temp;
		}
		temp->next = head;
		head = temp;
		size1++;
	}

	void insertatend(T d) {
		Node* temp = new Node;
		temp->data = d;
		temp->next = nullptr;
		if (tail == nullptr) {
			head = temp;
			tail = temp;
		}
		else {
			if (tail != nullptr) {
				tail->next = temp;
				tail = temp;
			}
		}
		size1++;
	}
	void deleteatend() {
		if (head != nullptr) {
			if (head == tail) {
				delete tail;
				head = tail = nullptr;
				size1--;
			}
			else {
				Node* temp = head;
				while (temp->next != tail) {
					temp = temp->next;

				}
				delete tail;
				size1--;
				temp->next = nullptr;
				tail = temp;
			}
		}
	}
	void push(T& d) {                //pushing elements in stack
		insertatend(d);

	}
	void pop() {    //deleting an element from stack
		deleteatend();

	}
	T& top() {
		return tail->data;
	}
	bool isempty() {
		if (size1 == 0) {
			return true;
		}
		return false;

	}
	void Printt()const {
		Node* current = head;
		tail->next = nullptr;
		while (current != tail->next) {
			cout << current->data;

			if (current != tail) {
				cout << "->";
			}
			current = current->next;

		}

	}

	int size() {     //return size of stack
		return size1;
	}

	~Stack() {
		while (!isempty())
			pop();
	}

};
