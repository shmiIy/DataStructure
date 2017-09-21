#include <iostream>

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

int main(void) {
    Stack<int> myStack;
    for(int i = 0; i < 10; ++i)
        myStack.push(i);

    cout << "Size of the stack: " << myStack.nodeNum() << endl;

    while(!myStack.empty()) {
        cout << myStack.top();
        myStack.pop();
    }
    return 0;
}
