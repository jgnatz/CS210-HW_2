/*
*	Jacob Gnatz, Brad Quid, Leo Caballero, Patrick Harper
*	LeftistHeap.hpp
*	Implements a generic, node based, binary, min-heap structure that favors left child skewing for optimal
*	merge capabilites. Stores shortest-path-lengths within each node and makes swaps accordingly.
*
*	Includes functions: merge, insert, deleteRoot, showLH and showSPL.
*
*	Credit to Young Park for core implementations.
*/

#include <vector>

//Node class
template <class DT>
class LeftistNode
{
	DT element;
	LeftistNode *left;
	LeftistNode *right;
	int spl;
	LeftistNode(const DT & theElement, LeftistNode *lt = NULL,
		LeftistNode *rt = NULL, int np = 1)
		: element(theElement), left(lt), right(rt), spl(np) { }
	friend class LeftistHeap<DT>;
};

//Heap class
template <class DT>
class LeftistHeap
{
public:
	/*Constructors & Destructor*/
	//Default Constructor
	LeftistHeap();

	//Parameterized Constructor
	LeftistHeap(const LeftistHeap & rhs)
	{
		//TODO
	}

	//Destructor
	~LeftistHeap();
	{
		delete this;
	}

	/*Operator & Public Methods*/
	/**
	* Sets this heap's values to a parameter heap via construction and root re-allocation.
	*/
	const LeftistHeap & operator=(const LeftistHeap & rhs)
	{
		//TODO
	}

	//Inserts a new value into the heap via merging a newly constructed heap
	void insert(const DT & x)
	{
		root = merge1(new LeftistNode<DT>(x), root);
	}

	//Deletes the minimum value (root)
	void deleteMin(DT & minItem)
	{
		minItem = findMin();
		LeftistNode<DT> *oldRoot = root;
		root = merge1(root->left, root->right);
		delete oldRoot;
	}

	/**
	* Merge rhs into the priority queue.
	* rhs becomes empty.
	*/
	void merge(LeftistHeap & rhs)
	{
		if (this == &rhs) // Avoid aliasing problems
			return;
		root = merge1(root, rhs.root);
		rhs.root = NULL;
	}

	//Two additional methods specified for assignment
	/**
	* Public method for printing a reverse in-order representation of this heap's data.
	* Calls private recursive method for printing.
	*/
	void showLH()
	{
		showLH(root);
	}

	/**
	* Public method for printing a reverse in-order representation of this heap's SPLs for each node.
	* Calls private recursive method for printing.
	*/
	void showSPL()
	{
		showSPL(root);
	}

private:
	//Root pointer
	LeftistNode<DT> *root;

	/*Private Methods*/
	/**
	* Internal method for printing a reverse in-order representation of this heap's data.
	*/
	void showLH(LeftistNode<DT>* node)
	{
		if (node == NULL)
			return;
		showLH(node->right);
		cout << node->element << " ";
		showLH(node->left);
	}

	/**
	* Internal method for printing a reverse in-order representation of this heap's SPLs for each node.
	*/
	void showSPL(LeftistNode<DT>* node)
	{
		if (node == NULL)
			return;
		showLH(node->right);
		cout << node->spl << " ";
		showLH(node->left);
	}

	/**
	* Internal method to merge two roots h1 and h2.
	*/
	LeftistNode<DT> * merge1(LeftistNode<DT> *h1,
		LeftistNode<DT> *h2) const
	{
		if (h1 == NULL) return h2;
		if (h2 == NULL) return h1;
		if (h1->element < h2->element) return merge2(h1, h2);
		else return merge2(h2, h1);
	}

	/**
	* Internal method to merge two not empty roots.
	* h1's root contains smallest item.
	*/
	LeftistNode<DT> * merge2(LeftistNode<DT> *h1,
		LeftistNode<DT> *h2) const
	{
		// Recursively merge its right subtree and the other tree h2.
		h1->right = merge1(h1->right, h2);
		// Swap if needed.
		if (h1->left->spl < h1->right->spl)
			swapChildren(h1);
		// Update the spl of the merged root.
		h1->spl = h1->right->spl + 1;
		return h1;
	}

	/**
	* Internal method to swap children pointers of a target node.
	*/
	void swapChildren(LeftistNode<DT> * t) const
	{
		LeftistNode* tmp = t->left;
		t->left = t->right;
		t->right = tmp;
	}
};