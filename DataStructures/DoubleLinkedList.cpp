#include <iostream>
using namespace std;

//Double Linked List Implementation

template<class T>               
class List {

	class Node {
	public:
		Node* next;
		Node* prev;
		T data;

	};
	Node* head;
	Node* tail;
	int size;
public:
	class iterator {
	public:
		Node* cur;
		iterator(Node* n = nullptr) {
			cur = n;
		}
		iterator(iterator& rhs) {
			cur = rhs.cur;
		}

		//OPERATOR OVERLOADING FOR ITERATOR

		T operator*() {
			return cur->data;
		}

		void operator=(const iterator& obj) {
			cur = obj.cur;
		}
		bool operator==(const iterator& obj)const {
			if (cur == obj.curr) {
				return true;
			}
			else {
				return false;
			}
		}

		iterator& operator ++() {
			cur = cur->next;
			return *this;
		}

		iterator& operator --() {
			cur = cur->prev;
			return *this;
		}

		bool operator !=(const iterator& rhs)const {
			if (cur == rhs.cur) {
				return false;
			}
			else {
				return true;
			}
		}



	};


	List() {

		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
		tail->next = nullptr;
		head->prev = nullptr;
		size = 0;

	}

	List(List& obj) {
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
		tail->next = nullptr;
		head->prev = nullptr;
		List<T>::iterator itr;
		itr = obj.begin();
		while (itr != obj.end()) {
			insertatend(itr.cur->data);
			++itr;
		}

	}

	List& operator=(List& obj) {
		while (head->next != tail) {
			DeleteAtEnd();
		}
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
		tail->next = nullptr;
		head->prev = nullptr;
		List<T>::iterator itr;
		itr = obj.begin();
		while (itr != obj.end()) {
			insertatend(itr.cur->data);
			++itr;
		}
		return *this;
	}

	void DeleteAtEnd() {
		Node* node = tail->prev;
		tail->prev->prev->next = tail;
		tail->prev = tail->prev->prev;
		delete node;
		size--;
	}

	void insertatstart(T const element) {        //INSERT AT THE START OF THE LIST
		Node* p = head->next;
		Node* temp = new Node;
		temp->data = element;
		temp->prev = p->prev;
		temp->next = p;
		p->prev->next = temp;
		p->prev = temp;

	}
	void insertatend(T const element) {             //INSERT AT THE END OF THE LIST
		Node* p = tail;
		Node* temp = new Node;
		temp->data = element;
		temp->prev = p->prev;
		temp->next = p;
		p->prev->next = temp;
		p->prev = temp;
		size++;

	}


	void printt() {                     //PRINT THE CONTENTS OF THE LIST
		Node* temp = head->next;
		while (temp != tail) {
			cout << temp->data << "  ";
			temp = temp->next;

		}
	}


	void deleteelement(Node*& ele) {
		Node* p = ele;
		p->prev->next = p->next;
		p->next->prev = p->prev;
	}

	iterator begin() {
		iterator itr(head->next);
		return itr;
	}

	iterator end() {
		iterator itr(tail);
		return itr;
	}


	void insert(Node* cur, T const V1) {
		Node* p = cur;
		Node* t = new Node;
		t->data = V1;
		t->prev = p->prev;
		t->next = p;
		p->prev->next = t;
		p->prev = t;
	}


	bool insertbefore(T const v1, T const v2) {
		Node* current = head->next;
		bool flag = false;

		while (current != tail) {
			if (current->data == v2) {
				insert(current, v1);
				flag = true;
			}
			current = current->next;

		}
		return flag;
	}

	bool deletebefore(T const v2) {
		Node* current = head->next;
		bool flag = false;

		while (current != tail) {
			if (current->next->data == v2) {
				deleteelement(current);
				flag = true;
			}
			current = current->next;

		}
		return flag;
	}

	friend ostream& operator<<(ostream& out, List  a) {
		a.printt();
		return out;
	}

	Node* returnhead() {
		return head;
	}

	Node* returntail() {
		return tail;
	}



	int returnsize() {
		return size;
	}
	Node* returnprev(Node* x) {
		return x->prev;
	}

	//DESTRUCTOR
	~List() {
		Node* current = head->next;
		while (current != tail) {
			Node* temp = current;
			current = current->next;
			delete temp;
		}
		if (head != nullptr) delete head;
		if (tail != nullptr) delete tail;
	}

};

//Simple Testing
int main() {
	List<int> test;
	test.insertatstart(21);
	test.insertatstart(22);
	test.insertatstart(23);
	test.insertatend(30);
	test.insertbefore(10, 30);
	test.deletebefore(30);
	test.printt();


}