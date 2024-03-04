#include<iostream>
using namespace std;


class Node{
    public:
    	int data;
    	Node *next;
    	~Node();
};

class List{
	public:
		Node *root;
		int size;
		void show();
		void append(int);
		void insert(int,int);
		void remove(int);
};

Node::~Node(){
    cout << data << " was deleted.\n";
}

void List::insert(int d,int idx){	
	Node *n = new Node;
	n->data = d;
	
	if(idx == 0){
		n->next = root;
		root = n;
		return;
	}
	Node *current = root;
	for(int i = 0; i < idx-1;i++){
		current = current->next;
	}
	n->next = current->next;
	current->next = n;		
}

void List::show(){
	Node *current = root;
	cout << current->data << " ";	
	while(current->next){
		current = current->next;
		cout << current->data << " ";
	}	
}

void List::append(int d){	
	Node *n = new Node;
	n->data = d; n->next = NULL;
	if(root == NULL) root = n;
	else{
		Node *current = root;
		while(current->next){
			current = current->next;
		}
		current->next = n;
	}
	size++;
}

void List::remove(int idx){
    if(root == NULL) return; // List is empty, nothing to remove

    Node *temp;
    if(idx == 0){
        temp = root; // Store the node to be deleted
        root = root->next; // Update the root
    } else {
        Node *current = root;
        for(int i = 0; i < idx-1; i++){
            if(current->next == NULL) return; // Index out of bounds
            current = current->next;
        }
        temp = current->next; // Node to be deleted
        if(temp == NULL) return; // Index out of bounds
        current->next = temp->next; // Unlink the node from the list
    }
    
    delete temp; // Delete the node and free memory
    size--; // Decrement the size of the list
}