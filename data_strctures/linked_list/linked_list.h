#include <memory>
#include <print>
#include <cstdint>
#include <cassert>

//Basic Nodes
namespace RD {

typedef struct Node {
	int32_t data{};
	//goes to nullptr by default
	std::unique_ptr<Node> pr;

}Node;

class LinkedList
{
public:
	//data
	std::unique_ptr<Node> head;
	//default
	LinkedList() = default;
	//Move sematics it and move assigment
	LinkedList(LinkedList&&) noexcept = default;
	LinkedList& operator=(LinkedList&&) noexcept = default;


	//Can't copy unique_ptr!
	//copy 
	LinkedList(const LinkedList&) = delete;
	//copy assignment
	LinkedList& operator=(const LinkedList&) = delete;

	//Inserting functions 
	//Push
	void InsertAtBeginning(std::unique_ptr<Node> n);
	//Append
	void InsertAtEnd(std::unique_ptr<Node> n);
	//Index
	void InsertAtPosition(int64_t x, std::unique_ptr<Node> n);
	//After pushed
	void InsertAfter(std::unique_ptr<Node> n);

	//Deleting functions
	//Push
	void DeleteAtBeginning(std::unique_ptr<Node> n) {};
	//Append
	void DeleteAtEnd(std::unique_ptr<Node> n) {};
	//Index
	void DeleteAtPosition(int64_t x, std::unique_ptr<Node> n) {};
	//After pushed
	void DeleteAfter(std::unique_ptr<Node> n) {};


	//Traverse/Search
	//print all
	void Traverse() const;
	//Print that one
	Node* Find(std::unique_ptr<Node> n);

	//Util.
	bool isEmpty();
	int32_t size();
	Node* getHead();
	void reverse();

};
}

