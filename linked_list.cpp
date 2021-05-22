#include<bits/stdc++.h>
using namespace std;

struct Node {
	int value;
	Node *next = NULL;
};

class SinglyLinkedList {
	private:
	Node *head;
	public:
	SinglyLinkedList() {head=NULL;}
	void insert(int value) {
		Node *newNode = (struct Node *) malloc(sizeof(struct Node));
		newNode->value = value;
		newNode->next = head;
		head = newNode;
	}
	void print() {
		Node *ptr = head;
		while(ptr) {
			cout << ptr->value << "  ";
			ptr = ptr->next;
		}
		cout<<"\n";
	}
	void removeHead() {
		if(head) {
			Node *toDelete = head, *newHead=head->next;
			free(toDelete);
			head = newHead;
		} else {
			cout << "Underflow!\n";
		}
	}
	~SinglyLinkedList() {
		Node *toDelete = head;
		while(toDelete) {
			Node *node = toDelete->next;
			free(toDelete);
			toDelete = node;
		}
	}
};

int main() {
	int choice;
	cout<<"(1)Insert\n(2)Delete\n(3)Print\n(0)Exit\nChoice: ";
	cin>>choice;
	SinglyLinkedList list = SinglyLinkedList();
	
	while(choice<=3 && choice>=0) {
		int value;
		switch(choice) {
			case 1: 
			cout<<"Value: ";
			cin>>value;
			list.insert(value);
			break;
			
			case 2:
			list.removeHead();
			break;
			
			case 3:
			list.print();
			break;
			
			default: break;
		}
		cin.sync();
		cout << "Choice: ";
		cin >> choice;
	}
	
	return 0;
}
