# include <iostream>
using namespace std;
template <class	DT>
class	Cell{
	template<class T>
	friend ostream& operator<< (ostream& s, Cell<T>& c); //Overloaded ostream operator
protected:
	DT* _value;	//Value stored in the cell
	Cell<DT>* _right; //Pointer to the next cell
public:
	//All	required	methods	
	Cell(); //Default constructor
	Cell(DT* v);//Initializer
	Cell(const Cell<DT>& c);//Copy constructor
	~Cell();//Destructor
	void operator= (const Cell<DT>& c);//Overloaded assignment operator
};

///////////////////////////////////////////////////////////////////////////////////////

template <class	DT1, class	DT2>
class CellNode {
	template<class T1, class T2>
	friend ostream& operator<< (ostream& s, CellNode<DT1, DT2>& cn); //Overloaded ostream operator
protected:
	DT1* _info; //The info for the cell node
	Cell<DT2>* _myCell;  //Pointer to the first cell
public:
	//All	required	methods	
	CellNode();//Default constructor
	CellNode(DT1* i);//Initializer
	CellNode(const CellNode<DT1, DT2>& cn);//Copy constructor
	~CellNode();//Destructor
	void operator= (const CellNode<DT1, DT2>& c);//Overloaded assignment operator
};


///////////////////////////////////////////////////////////////////////////////////////

template <class	DT1, class	DT2>
class MasterCell {
	template<class T1, class T2>
	friend ostream& operator<< (ostream& s, MasterCell<T1, T2>& mc); //Overloaded ostream operator
protected:
	CellNode<DT1, DT2>*	_myCellNodes;
public:
	//All	required	methods
	MasterCell();//Default constructor
	MasterCell(CellNode<DT1, DT2>* cn);//Initializer
	MasterCell(const MasterCell<DT1, DT2>& mc);//Copy constructor
	~MasterCell();//Destructor
	void operator= (const MasterCell<DT1, DT2>& mc);//Overloaded assignment operator
};

///////////////////////////////////////////////////////////////////////////////////////
//Cell Methods

template<class DT>
Cell<DT>::Cell() {
}

template<class DT>
Cell<DT>::Cell(DT * v) {
}

template<class DT>
Cell<DT>::Cell(const Cell<DT>& c) {
}

template<class DT>
Cell<DT>::~Cell() {
}

template<class DT>
void Cell<DT>::operator=(const Cell<DT>& c) {
}

///////////////////////////////////////////////////////////////////////////////////////
//Cell Node Methods

template<class DT1, class DT2>
CellNode<DT1, DT2>::CellNode() {
}

template<class DT1, class DT2>
CellNode<DT1, DT2>::CellNode(DT1 * i) {
}

template<class DT1, class DT2>
CellNode<DT1, DT2>::CellNode(const CellNode<DT1, DT2>& cn) {
}

template<class DT1, class DT2>
CellNode<DT1, DT2>::~CellNode() {
}

template<class DT1, class DT2>
void CellNode<DT1, DT2>::operator=(const CellNode<DT1, DT2>& c) {
}

///////////////////////////////////////////////////////////////////////////////////////
//Master Cell Methods

template<class DT1, class DT2>
MasterCell<DT1, DT2>::MasterCell() {
}

template<class DT1, class DT2>
MasterCell<DT1, DT2>::MasterCell(CellNode<DT1, DT2>* cn) {
}

template<class DT1, class DT2>
MasterCell<DT1, DT2>::MasterCell(const MasterCell<DT1, DT2>& mc) {
}

template<class DT1, class DT2>
MasterCell<DT1, DT2>::~MasterCell() {
}

template<class DT1, class DT2>
void MasterCell<DT1, DT2>::operator=(const MasterCell<DT1, DT2>& mc) {
}

///////////////////////////////////////////////////////////////////////////////////////
//Overloaded ostream operators
template<class T>
ostream& operator<< (ostream& s, Cell<T>& c) {
	return s;

}
template<class T1, class T2>
ostream& operator<< (ostream& s, CellNode<T1, T2>& cn) {
	return s;

}
template<class T1, class T2>
ostream& operator<< (ostream& s, MasterCell<T1, T2>& mc) {
	return s;

}

///////////////////////////////////////////////////////////////////////////////////////

int main() {
	cout << "test" << endl;
	return 0;
}




/*
Create	all	the	required	data	structures	along	with	the	implementation	of	each	of	the
following	methods	for	all	classes. You	are	required	to	demonstrate	the	working	of	the	following
methods	for	each	of	the	methods	by	invoking	them	from	a	main	program.
a. empty	constructor
b. non-empty	constructor (sets	the	initial	size	of	the	vector)
c. destructor
d. copy	constructor
e. overloaded	equal	to	operator
f. ostream operator
*/
/*
Read	the	redirected	input	and	create	all	the	data	structures.
Demonstrate	the	working	of	the	classes	with	two	different	data	types:	int	and	character
strings.
*/