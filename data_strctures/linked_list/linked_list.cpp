#include "linked_list.h"


//Functions !

//Push
void RD::LinkedList::InsertAtBeginning(std::unique_ptr<Node> n)
{
	//Novi node pokazje na head sto ce biti sledeci u nizu
	n->pr = std::move(head);
	//Sada ce novi node da ownuje head.
	head = std::move(n);

};
//Append
void RD::LinkedList::InsertAtEnd(std::unique_ptr<Node> n) {};
//Index
void RD::LinkedList::InsertAtPosition(int64_t index, std::unique_ptr<Node> n)
{
	assert(index <= this->size());

	int64_t x = 0;

	if (index == 0) {
		n->pr = std::move(head);
		head = std::move(n);
		return;
	}

	Node* temp = head.get();

	for (int64_t i = 0; i < index - 1; i++) {
		temp = temp->pr.get();
	}

	n->pr = std::move(temp->pr);
	temp->pr = std::move(n);

};
//After pushed
void RD::LinkedList::InsertAfter(std::unique_ptr<Node> n) {};

//Traverse/Search
//print all
void RD::LinkedList::Traverse()const
{
	//traverse
	RD::Node* temp = head.get();
	while (temp) {
		Node* curr = temp;
		std::println("Print value : {},  Print Value of next node pointer:  {} ",
			curr->data,
			static_cast<const void*>(curr->pr.get()));
		temp = curr->pr.get();
	}
};
//Print that one
RD::Node* RD::LinkedList::Find(std::unique_ptr<Node> n) { return n.get(); };
//Util.
bool RD::LinkedList::isEmpty() { return head == nullptr; };
int32_t RD::LinkedList::size() {
	int32_t count = 0;
	RD::Node* temp = head.get();

	while (temp) {
		count++;
		temp = temp->pr.get();
	}

	return count;
};
RD::Node* RD::LinkedList::getHead() { return head.get(); };
void RD::LinkedList::reverse() {};