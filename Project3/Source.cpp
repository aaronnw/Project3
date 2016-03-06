# include <iostream>
using namespace std;

template<class DT>
class vector {
	template<class T>
	friend ostream& operator<< (ostream& s, vector<T>& ac); //Overloaded ostream operator
private:
	DT* arrayOfDT;
	int numElements;
	int capacity;
	const int multiplier = 2;
	const int defaultCapacity = 50;
public:
	vector(); //Default constructor
	vector(int c); //Initializer constructor
	vector(const vector<DT>& ac); // Copy constructor
	~vector(); // Destructor
	void operator= (const vector<DT>& ac); //Overloaded assignment operator
	DT& operator[](int i);
	void add(DT& x);
	void insertAt(int i, DT& x);
	void removeAt(int i);
	void expand();
	void empty();
	int getCapacity();
	int getSize();
};

///////////////////////////////////////////////////////////////////////////////////////

template <class	DT>
class Cell{
	template<class T>
	friend ostream& operator<< (ostream& s, Cell<T>& c); //Overloaded ostream operator
protected:
	DT* _value;	//Value stored in the cell
	Cell<DT>* _right; //Pointer to the next cell
public:
	//All	required	methods	
	Cell(); //Default constructor
	Cell(DT* v, Cell<DT>* r);//Initializer
	Cell(DT* v, int i);//Initializer
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
	CellNode(DT1* i, Cell<DT2>* c);//Initializer
	CellNode(const CellNode<DT1, DT2>& cn);//Copy constructor
	~CellNode();//Destructor
	Cell<DT2>* getFirstCell();
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
//Vector methods 

///Default constructor
template<class DT>
vector<DT>::vector() {
	numElements = 0;
	capacity = defaultCapacity;
	arrayOfDT = new DT[capacity];
}
///Initializer constructor
template<class DT>
vector<DT>::vector(int c) {
	numElements = 0;
	capacity = c;
	arrayOfDT = new DT[capacity];
}
///Copy constructor
template<class DT>
vector<DT>::vector(const vector<DT>& ac) {
	numElements = ac.numElements;
	capacity = ac.capacity;
	arrayOfDT = new DT[capacity];
	for (int i = 0; i < capacity; i++) {
		arrayOfDT[i] = ac.arrayOfDT[i];
	}
}
///Destructor
template<class DT>
vector<DT>::~vector() {
	delete[] arrayOfDT;
}
///Overloaded assignment operator
template<class DT>
void vector<DT>::operator= (const vector<DT>& ac) {
	arrayOfDT = new DT[ac.capacity];
	for (int i = 0; i < ac.capacity; i++) {
		arrayOfDT[i] = ac.arrayOfDT[i];
	}
	numElements = ac.numElements;
	capacity = ac.capacity;
}
///Overloaded square bracket operator
template<class DT>
DT & vector<DT>::operator[](int i) {
	//TODO if ((i < 0) || (i >= (capacity - 1))) throw errors;
	return arrayOfDT[i];
}
///Add an element to the end of the array
template<class DT>
void vector<DT>::add(DT & x) {
	//If there is room, add to the end of current array
	if (numElements < capacity) {
		arrayOfDT[numElements] = x;
		numElements++;
	}
	else {
		expand();
		add(x);
	}
}
///Insert an element into the array
template<class DT>
void vector<DT>::insertAt(int i, DT & x) {
	if ((numElements < capacity) && (i < capacity)) {
		for (int k = (numElements + 1); k > i; k--) {
			arrayOfDT[k] = arrayOfDT[k - 1];
		}
		arrayOfDT[i] = x;
		numElements++;
	}
	else {
		expand();
		insertAt(i, x);
	}
}
///Remove an element from a given index
template<class DT>
void vector<DT>::removeAt(int i) {
	for (i; i < (numElements); i++) {
		arrayOfDT[i] = arrayOfDT[i + 1];
	}
	numElements--;
	//error input
}
///Increase the size of the array
template<class DT>
void vector<DT>::expand() {
	//Create a copy of the current array with a larger capacity
	DT* newArray = new DT[capacity * multiplier];
	for (int i = 0; i < capacity; i++) {
		newArray[i] = arrayOfDT[i];
	}
	delete[] arrayOfDT;
	arrayOfDT = newArray;// new DT[capacity];

	capacity = capacity * multiplier;

}
///Show the array as empty
template<class DT>
void vector<DT>::empty() {
	numElements = 0;
}
///Return the capacity
template<class DT>
int vector<DT>::getCapacity() {
	return capacity;
}
///Return the number of elements
template<class DT>
int vector<DT>::getSize() {
	return numElements;
}
///Overloaded ostream operator
template<class T>
ostream& operator<< (ostream& s, vector<T>& ac) {
	for (int i = 0; i < ac.getSize(); i++) {
		s << ac[i];
	}
	return s;

}

///////////////////////////////////////////////////////////////////////////////////////
//Cell Methods

template<class DT>
Cell<DT>::Cell() {
}

template<class DT>
Cell<DT>::Cell(DT* v, Cell<DT>* r) {
	_value = v;
	_right = r;
}

template<class DT>
Cell<DT>::Cell(DT * v, int i) {
	_right = nullptr;
	_value = v;
}

template<class DT>
Cell<DT>::Cell(const Cell<DT>& c) {
	_value = *c._value;
	_right = *c._right;
}

template<class DT>
Cell<DT>::~Cell() {
}

template<class DT>
void Cell<DT>::operator=(const Cell<DT>& c) {
	_value = c._value;
	_right = c._right;
}

///////////////////////////////////////////////////////////////////////////////////////
//Cell Node Methods

///Default constructor
template<class DT1, class DT2>
CellNode<DT1, DT2>::CellNode() {
}
///Initializer
template<class DT1, class DT2>
CellNode<DT1, DT2>::CellNode(DT1* i, Cell<DT2>* c) {
	_info = i;
	_myCell = c;
}
///Copy constructor
template<class DT1, class DT2>
CellNode<DT1, DT2>::CellNode(const CellNode<DT1, DT2>& cn) {
	_info = *cn.info;
	_myCell = *cn._myCell;
}
///Destructor
template<class DT1, class DT2>
CellNode<DT1, DT2>::~CellNode() {
}

template<class DT1, class DT2>
Cell<DT2>* CellNode<DT1, DT2>::getFirstCell() {
	return _myCell;
}
///Overloaded assignment operator
template<class DT1, class DT2>
void CellNode<DT1, DT2>::operator=(const CellNode<DT1, DT2>& cn) {
	_info = cn._info;
	_myCell = cn._myCell;
}


///////////////////////////////////////////////////////////////////////////////////////
//Master Cell Methods

template<class DT1, class DT2>
MasterCell<DT1, DT2>::MasterCell() {
}

template<class DT1, class DT2>
MasterCell<DT1, DT2>::MasterCell(CellNode<DT1, DT2>* cn) {
	_myCellNodes = *cn.getFirstCell();
}

template<class DT1, class DT2>
MasterCell<DT1, DT2>::MasterCell(const MasterCell<DT1, DT2>& mc) {
	_myCellNodes = *mc._myCellNodes;
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
	s << *c._value;
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
	int info;
	char blank = ' ';
	char comma = ',';
	int noItems;
	char c;
	vector<char> value;
	vector<vector<char>> valueList;
	Cell<vector<char>> cell;
	Cell<vector<char>>* cellPointer;
	CellNode<int, vector<char>> cellNode;
	CellNode<int, Cell<vector<char>>> masterCell;
	while (!cin.eof()) {
		//Read in the first values
		cin >> info;
		cin.get(comma);
		cin.get(blank);
		cin >> noItems;
		cin.get(blank);
		//Read in the values
		do {
			value.empty();
			cin.get(c);
			//While there is a valid character read it in
			while ((c != ' ') && (c != '\n') && (!cin.eof())) {
				value.add(c);
				cin.get(c);
			}
			//If there is a space and a value has been read
			if (value.getSize() >= 1) {
				valueList.add(value);
			}
		} while ((c != '\n') && (!cin.eof()));
		//End of line
		//Create a cell node
		cell = Cell<vector<char>>(&valueList[noItems - 1], 0);
		cellPointer = &cell;
		for (int i = noItems-2; i >= 0; i--) {
			cell = Cell<vector<char>>(&valueList[i], cellPointer);
			cellPointer = &cell;
		}
		cellNode = CellNode<int, vector<char>>(&info, cellPointer);
	}
	//End of file
	//Create a master cell
//	cout << valueList[0] << ' ' << valueList[1] << ' ' << valueList[2] << ' ' << valueList[3] << ' ' << endl;
	return 0;
}


/* example
int value = 34;
int* pointerToValue = &value;
Cell<int> newCell(pointerToValue);
cout << newCell << endl;
*/

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