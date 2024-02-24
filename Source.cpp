#include <iostream>

using namespace std;


template<typename T>
class List {
public:
	List<T>() {
		size = 0; 
		head = nullptr;
	}
	~List<T>(){}

	int getSize() { 
		return this->size;
	};

	void pushBack(T data) {
		if (this->head == nullptr) {
			head = new Node<T>(data);
		}
		else {
			Node<T>* tmp = head;
			while (tmp->ptrNext != nullptr) {
				tmp = tmp->ptrNext;
			}
			tmp->ptrNext = new Node<T>(data);
		}
		this->size++;
	}

	T& operator [](const int index) {
		int counter = 0;
		Node<T>* tmp = this->head;
		while (tmp != nullptr) {
			if (counter == index) {
				return tmp->data;
			}
			tmp = tmp->ptrNext;
			counter++;
		}
		throw exception("Out of range List");
	};

	void popFront() {
		Node<T>* tmp = this->head;
		this->head = head->ptrNext;
		delete tmp;
		this->size--;
	}

	void clear() {
		while (this->size) {
			popFront();
		}
	};
	
	void pushFront(T data) {
		Node<T>* tmp = this->head;
		this->head = new Node<T>(data, tmp);
		this->size++;
	}

	void popBack() {
		Node<T>* tmp = this->head;
		while (tmp->ptrNext != nullptr) {
			tmp = tmp->ptrNext;
		}
		delete tmp;
		this->size--;
	}

	void insert(T data, const int index) {
		if (index == 0) {
			pushFront(data);
		}
		else {
			int counter = 0;
			Node<T>* tmp = this->head;
			while (tmp != nullptr) {
				if (counter == index - 1) {
					Node<T>* el = new Node<T>(data, tmp->ptrNext);
					tmp->ptrNext = el;
					break;
				}
				tmp = tmp->ptrNext;
				counter++;
			}
		}
		this->size++;
	}

	void removeAt(const int index) {
		int counter = 0;
		Node<T>* tmp = this->head;
		while (tmp != nullptr) {
			if (counter == index-1) {
				Node<T>* el = tmp->ptrNext;
				tmp->ptrNext = el->ptrNext;
				delete el;
				break;
			}
			tmp = tmp->ptrNext;
			counter++;
		}
		this->size--;
	}
private:
	template<typename T>
	class Node{
	public:
		Node(T data = T(), Node* ptrNext = nullptr) {
			this->ptrNext = ptrNext;
			this->data = data;
		};
		Node* ptrNext;
		T data;
	};
	int size;
	Node <T>* head;		//œŒ◊»“¿“‹
};

int main() {
	List<int> ls;
	ls.pushBack(10);
	ls.pushBack(13);
	ls.pushBack(12);

	ls.pushFront(133);
	ls.popBack();
	ls.insert(20, 2);
	ls.removeAt(2);
	for (int i = 0; i < ls.getSize(); ++i) {
		cout << ls[i] << endl;
	}
	return 0;
}