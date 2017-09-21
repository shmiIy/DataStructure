#include <iostream>
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
class Stack	{
  private:
	Node<T> *head;
	int nodeNumber;

  public:
	Stack() : head(NULL), nodeNumber(0) {}
	~Stack() {
        clear();
    }

	bool empty() const {
		if(head) {
		    return false;
		} else {
	   	    return true;
	   }
	}
	void clear() {
		while(head) {
			Node<T> *delNode = head;
			head = delNode->next;
			delete delNode;
		}
	}

	const T& top() const {
		return head->data;
	}
	void pop() {
		if(head) {
			Node<T> *pnode = head;
			head = pnode->next;
			delete pnode;
			--nodeNumber;
		}
	}
	void push(const T& inp) {
		Node<T> *newNode = new Node<T>(inp);
		newNode->next = head;
		head = newNode;
		++nodeNumber;
	}

	const int& nodeNum() const {
        return nodeNumber;
    }
};

void printStack(Stack<int> stack) {
    cout << "Now the stack is: ";
    if (stack.empty()) {
        cout << "empty" << endl;
    }
    while(!stack.empty()) {
		cout << stack.top() << '\t';
		stack.pop();
	}
	cout << endl;
}

void printTable() {
    cout << "Operate: " << endl;
    cout << "Enter 'push' to push a new data into stack" << endl;
    cout << "Enter 'top' to get the top data of stack" << endl;
    cout << "Enter 'pop' to delet the top data of stack" << endl;
    cout << "Enter 'quit' to quit the program" << endl;
}

int main(void) {
    string inp;
    int data;
    
	Stack<int> testStack;
	for(int i = 0; i < 10; ++i) {
	    testStack.push(i);
	}
	cout << "Size of the stack: " << testStack.nodeNum() << endl;
	printStack(testStack);

    Stack<int> myStack;
    printStack(myStack);
    printTable();
    cout << "Please enter your operation: ";
    cin >> inp;
    while (inp != "quit") {
        if (inp == "push") {
            cout << "Please enter the number to push: ";
            cin >> data;
            myStack.push(data);
            cout << endl << "Push successful!" << endl;
        } else if (inp == "top") {
            if (myStack.empty()) {
                cout << endl << "The stack is empty!" << endl;
            } else {
                cout << endl << myStack.top() << endl;
            }
        } else if (inp == "pop") {
            if (myStack.empty()) {
                cout << endl << "The stack is empty!" << endl;
            } else {
                myStack.pop();
                cout << endl << "Pop successful!" << endl;
            }
        } else {
            cout << "Invalid input! Please try again." << endl;
        }
        printStack(myStack);
        cout << "Please enter your operation: ";
        cin >> inp;
    }
	return 0;
}
