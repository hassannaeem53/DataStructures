//singly
#include <iostream>
using namespace std;

template<class T>
class List {
private:

	class Node {
	public:
		T data;
		Node* next;
	};
	Node* head;
	Node* tail;
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


		bool operator !=(const iterator& rhs)const {
			if (cur == rhs.cur) {
				return false;
			}
			else {
				return true;
			}
		}



	};

public:

	//constructor
	List() {
		head = nullptr;
		tail = nullptr;
	}
	iterator begin() {
		iterator itr(head);
		return itr;
	}

	iterator end() {
		iterator itr(tail->next);
		return itr;
	}

	//Copy Constructor
	List(List& obj) {
		head = nullptr;
		tail = nullptr;
		head = tail;
		Node* cur = obj.head;
		while (cur != nullptr) {
			insertAtEnd(cur->data);
			cur = cur->next;
		}

	}
	// Equal Operator Overload
	List& operator=(List& obj) {
		if (head) {
			while (head != nullptr) {
				DeleteAtEnd();
			}
		}
		head = nullptr;
		tail = nullptr;
		head = tail;
		Node* cur = obj.head;
		while (cur != nullptr) {
			insertAtEnd(cur->data);
			cur = cur->next;
		}
		return *this;
	}

	//Tail Data Getter
	T getTailData() {
		return tail->data;
	}

	//Head Data Getter
	T getHeadData() {
		return head->data;
	}

	//Insert At Head Function
	void insertAtStart(T const element) {
		Node* temp = new Node;
		temp->data = element;
		temp->next = nullptr;
		if (head == nullptr) {
			head = temp;
			tail = temp;
		}
		else {
			temp->next = head;
			head = temp;
		}
	}

	//Insert At Tail Funtion
	void insertAtEnd(T const element) {
		Node* temp = new Node;
		temp->data = element;
		temp->next = nullptr;
		if (head == nullptr && tail == nullptr) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}

	//Insert Before Any Node: V1 is the the Node to be Inserted
	bool insertbefore(T const v1, T const v2) {
		Node* temp = head;
		if (temp->data == v2) {
			insertAtStart(v1);
			return true;

		}
		while (temp->data != v2 && temp != tail) {
			Node* prev = temp;  //10-20-21-22   prev=10
			temp = temp->next;  //temp=20

			if (temp->data == v2) {
				Node* insertion = new Node;
				insertion->data = v1;
				insertion->next = temp;
				prev->next = insertion;
				prev = temp;

			}

		}



	}

	//Linked List Print funtion
	void print()const {
		if (head == nullptr) {
			cout << "LIST IS EMPTY";
		}
		Node* curr;
		curr = head;
		while (curr != nullptr) {
			cout << curr->data;
			if (curr->next != nullptr) {
				cout << "->";
			}
			curr = curr->next;
		}
	}

	//Search Any Node(Value) Function
	bool search(T const& element) const {
		bool found = false;
		Node* curr = head;
		while (curr != nullptr && found == false) {
			if (curr->data == element) {
				found = true;
			}
			curr = curr->next;
		}
		return found;
	}

	//Delete at Head funtion
	void DeleteAtStart() {
		if (head == tail && head != nullptr) {
			delete head;
			head = tail = nullptr;
		}
		else if (head != nullptr) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	//Delete at Tail Function
	void DeleteAtEnd() {
		if (head == tail && tail != nullptr) {
			delete tail;
			head = tail = nullptr;
		}
		else if (tail != nullptr) {
			Node* temp = head;
			while (temp->next->next != nullptr) {
				temp = temp->next;
			}
			delete tail;
			tail = temp;
			tail->next = nullptr;
		}
	}

	//Reversing a Singly Linked List Function
	void reverse() {
		if (head != nullptr) {
			Node* curr = head;
			Node* last = nullptr;
			Node* temp;
			while (curr->next != nullptr) {
				temp = curr->next;
				curr->next = last;
				if (last == nullptr) {
					tail = curr;
				}
				last = curr;
				curr = temp;
			}
			head = curr;
			head->next = last;

		}
	}

	//Destrtuctor
	~List() {
		while (head != nullptr)
			DeleteAtStart();
	}

};

//Simple Test Program
int main() {
	List<int> test;
	test.insertAtStart(10);
	test.insertAtEnd(20);
	test.insertAtEnd(21);
	test.insertAtEnd(22);
	test.insertbefore(50, 22);
	test.reverse();
	test.print();
	List<int> test2;
	test2.insertAtEnd(25);
	test2 = test;
	cout << endl;
	test2.print();


}
