#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

template <class T>
class Node {
  public:
    Node() {
        next = NULL;
    }
    Node(T inp) {
        data = inp;
        next = NULL;
    }
    Node *next;
    T data;
};

template <class T>
class Queue {
  private:
    Node<T> *head;
    Node<T> *tail;
    int nodeNumber;
    
  public:
    Queue() : head(NULL), tail(NULL), nodeNumber(0) {}
    ~Queue() {
        clear();
    }
    bool empty() const {
        if(tail) {
		    return false;
        } else {
	   	    return true;
	    }
    }
    const int& nodeNum() const {
        return nodeNumber;
    }
    void clear() {
        head = head->next;
        while(head) {
            Node<T> *delNode = head;
            head = delNode->next;
            delete delNode;
        }
        nodeNumber = 0;
        cout << "Clear queue successfully!" << endl;
    }
    void add(const T& inp) {
        Node<T> *newNode = new Node<T>(inp);
        if (empty()) {
            head->next = newNode;
        }
        tail->next = newNode;
        tail = newNode;
        nodeNumber++;
        cout << "Add data successfully!" << endl;
    }
    void top() {
        if (head == tail) {
            cout << "The queue is empty!" << endl;
        } else {
            cout << "The top element is: " << head->next->data << endl;
        }
    }
    void delTop(){
        if (head == tail) {
            cout << "The queue is empty!" << endl;
        } else {
            head = head->next;
            Node<T> *delNode = head;
            head = delNode->next;
            delete delNode;
            --nodeNumber;
            cout << "Delet node successfully!" << endl;
        }
    }
    void print() {
        Node<T> *newNode = head;
        cout << "Now the queue is: ";
        if (empty()) {
            cout << "empty" << endl;
        }
        while(newNode != tail) {
    		cout << newNode->data << '\t';
    		newNode = newNode->next;
    	}
    	cout << endl;
    }
};

void printTable() {
    cout << "Operate: " << endl;
    cout << "Enter 'add' to add a new data into queue" << endl;
    cout << "Enter 'top' to get the top data of queue" << endl;
    cout << "Enter 'deltop' to delet the top data of queue" << endl;
    cout << "Enter 'print' to print the queue" << endl;
    cout << "Enter 'quit' to quit the program" << endl;
}

int main(void) {
    string inp;
    int data;
	Queue<int> testQueue;
	for(int i = 0; i < 10; ++i) {
	    testQueue.add(i);
	}
	cout << "Size of the stack: " << testQueue.nodeNum() << endl;
	testQueue.print();
	testQueue.clear();

    Queue<int> myQueue;
    myQueue.print();
    printTable();
    cout << "Please enter your operation: ";
    cin >> inp;
    while (inp != "quit") {
        if (inp == "add") {
            cout << "Please enter the number to push: ";
            cin >> data;
            myQueue.add(data);
        } else if (inp == "top") {
            myQueue.top();
        } else if (inp == "deltop") {
            myQueue.delTop();
        } else if (inp == "print") {
            myQueue.print();
        } else {
            cout << "Invalid input! Please try again." << endl;
        }
        myQueue.print();
        cout << "Please enter your operation: ";
        cin >> inp;
    }
	return 0;
}
