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
	//Constructors & Destructor
	LeftistHeap();
	LeftistHeap(const LeftistHeap & rhs);
	~LeftistHeap();

	//Operator & Public Methods
		//Implementation TO-DO
	const LeftistHeap & operator=(const LeftistHeap & rhs);

	void insert(const DT & x);

	void deleteMin(DT & minItem);

	void merge(LeftistHeap & rhs);

	void printLHeap() const;

	//Two additional methods specified for assignment
		//Implementation TO-DO
	void showLH();

	void showSPL();

private:
	//Root pointer
	LeftistNode<DT> *root;

	//Private Methods
		//Implementation TO-DO
	LeftistNode<DT> * merge1(LeftistNode<DT> *h1,
		LeftistNode<DT> *h2) const;

	LeftistNode<DT> * merge2(LeftistNode<DT> *h1,
		LeftistNode<DT> *h2) const;

	void swapChildren(LeftistNode<DT> * t) const;
};