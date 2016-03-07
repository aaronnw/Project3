# include <iostream>
using namespace std;

class incorrectInputError {};

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
	DT* toArray();
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
	Cell(DT* v); //Initializer
	Cell(const Cell<DT>& c);//Copy constructor
	~Cell();//Destructor
	void operator= (const Cell<DT>& c);//Overloaded assignment operator
	Cell<DT>* getRight();
	void setRight(Cell<DT>* cellPointer);
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
	DT1* getInfo();
	void operator= (const CellNode<DT1, DT2>& c);//Overloaded assignment operator
};

///////////////////////////////////////////////////////////////////////////////////////

template <class	DT1, class	DT2>
class MasterCell {
	template<class T1, class T2>
	friend ostream& operator<< (ostream& s, MasterCell<T1, T2>& mc); //Overloaded ostream operator
protected:
	CellNode<DT1, DT2>*	_myCellNodes;
	int numNodes;
public:
	//All	required	methods
	MasterCell();//Default constructor
	MasterCell(CellNode<DT1, DT2>* cn);//Initializer
	MasterCell(vector<CellNode<DT1, DT2>> cn);//Initializer
	MasterCell(const MasterCell<DT1, DT2>& mc);//Copy constructor
	~MasterCell();//Destructor
	void addCellNode(DT1* info, Cell<DT2>* cell);
	void operator= (const MasterCell<DT1, DT2>& mc);//Overloaded assignment operator
	CellNode<DT1, DT2>* getCellNodes();
	int getNumNodes();
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
template<class DT>
DT * vector<DT>::toArray() {
	return arrayOfDT;
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
	DT* _value = nullptr;
	Cell<DT>* _right = nullptr;
}

template<class DT>
Cell<DT>::Cell(DT* v) {
	_value = v;
	_right = nullptr;
}

template<class DT>
Cell<DT>::Cell(const Cell<DT>& c) {
	_value = c._value;
	_right = c._right;
}

template<class DT>
Cell<DT>::~Cell() {
}

template<class DT>
void Cell<DT>::operator=(const Cell<DT>& c) {
	_value = c._value;
	_right = c._right;
}

template<class DT>
Cell<DT>* Cell<DT>::getRight() {
	return _right;
}

template<class DT>
void Cell<DT>::setRight(Cell<DT>* cellPointer) {
	_right = cellPointer;
}

///////////////////////////////////////////////////////////////////////////////////////
//Cell Node Methods

///Default constructor
template<class DT1, class DT2>
CellNode<DT1, DT2>::CellNode() {
	DT1* _info = nullptr; //The info for the cell node
	Cell<DT2>* _myCell = nullptr;  //Pointer to the first cell
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
	_info = cn._info;
	_myCell = cn._myCell;
}
///Destructor
template<class DT1, class DT2>
CellNode<DT1, DT2>::~CellNode() {
}

template<class DT1, class DT2>
Cell<DT2>* CellNode<DT1, DT2>::getFirstCell() {
	return _myCell;
}
template<class DT1, class DT2>
DT1 * CellNode<DT1, DT2>::getInfo() {
	return _info;
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
	numNodes = 0;
	CellNode<DT1, DT2>*	_myCellNodes = nullptr;
}

template<class DT1, class DT2>
MasterCell<DT1, DT2>::MasterCell(CellNode<DT1, DT2>* cn) {
	_myCellNodes = cn;
}

template<class DT1, class DT2>
MasterCell<DT1, DT2>::MasterCell(vector<CellNode<DT1, DT2>> cn) {
	numNodes = cn.getSize();
	_myCellNodes = cn.toArray();
}

template<class DT1, class DT2>
MasterCell<DT1, DT2>::MasterCell(const MasterCell<DT1, DT2>& mc) {
	_myCellNodes = *mc._myCellNodes;
}
template<class DT1, class DT2>
MasterCell<DT1, DT2>::~MasterCell() {
}

template<class DT1, class DT2>
void MasterCell<DT1, DT2>::addCellNode(DT1* info, Cell<DT2>* cell) {
	CellNode<DT1, DT2>* tmp = _myCellNodes;
	_myCellNodes = new CellNode<DT1, DT2>[numNodes + 1];
	for (int i = 0; i < numNodes; ++i) {
		_myCellNodes[i] = tmp[i];
	}
	_myCellNodes[numNodes] = CellNode<vector<char>, vector<char>>(info, cell);
	numNodes++;
	delete[] tmp;
}

template<class DT1, class DT2>
void MasterCell<DT1, DT2>::operator=(const MasterCell<DT1, DT2>& mc) {
}

template<class DT1, class DT2>
CellNode<DT1, DT2>* MasterCell<DT1, DT2>::getCellNodes() {
	return _myCellNodes;
}
template<class DT1, class DT2>
int MasterCell<DT1, DT2>::getNumNodes() {
	return numNodes;
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
	s << *cn.getInfo() << ',' << ' ';
	for(Cell<vector<char>>* cell = (cn.getFirstCell()) ; cell != nullptr; cell = ((*cell).getRight())){
		s << *cell << ' ';
	}
	s << endl;
	return s;
}

template<class T1, class T2>
ostream& operator<< (ostream& s, MasterCell<T1, T2>& mc) {
	CellNode<T1, T2>* nodeList = mc.getCellNodes();
	for (int i = 0; i < mc.getNumNodes(); i++) {
		cout << nodeList[i];
	}
	return s;

}

///////////////////////////////////////////////////////////////////////////////////////

int main() {
	char blank = ' ';
	int noItems;
	char c;
	int count = 0;
	MasterCell<vector<char>, vector<char>> masterCell; 
	while (!cin.eof()) {
		Cell<vector<char>>* previousCell = new Cell<vector<char>>();
		vector<char>* info = new vector<char>;
		count = 0;
		//Read in the first values
		cin.get(c);
		while (c != ',' && !cin.eof()) {
			(*info).add(c);
			cin.get(c);
		}
		cin.get(blank);
		cin >> noItems;
		cin.get(blank);
		//Read in the values
		do {
			bool b = (bool)cin;
			vector<char>* value = new vector<char>();
			cin.get(c);
			//While there is a valid character read it in
			while ((c != ' ') && (c != '\n') && (!cin.eof())) {
				(*value).add(c);
				cin.get(c);
			}
			//If there is a space and a value has been read
			if ((*value).getSize() >= 1) {
				Cell<vector<char>>* cell = new Cell<vector<char>>(value);
				if (count == 0) {
					masterCell.addCellNode(info, cell);
					previousCell = cell;
					count++;
				}
				else{
					(*previousCell).setRight(cell);
					previousCell = cell;
				}
			}
			else {
				break;
			}
		} while ((c != '\n') && (!cin.eof()));
		//End of line
		if (cin.eof()) break;
	}
	//End of file
 	cout << masterCell;
	///Call the methods for each class to demonstrate that they work
	//	Demonstrate	the	working	of the classes with	two	different data types: int and character strings.
	//Cell
	/*
		friend ostream& operator<< (ostream& s, Cell<T>& c); //Overloaded ostream operator
		Cell(); //Default constructor
		Cell(DT* v, Cell<DT>* r);//Initializer
		Cell(DT* v, int i);//Initializer
		Cell(DT* v); //Initializer
		Cell(const Cell<DT>& c);//Copy constructor
		~Cell();//Destructor
		void operator= (const Cell<DT>& c);//Overloaded assignment operator
		Cell<DT>* getRight();
		void setRight(Cell<DT>* cellPointer);
	*/
//	Cell emptyCell = Cell();
	
	//CellNode
	/*
		friend ostream& operator<< (ostream& s, CellNode<DT1, DT2>& cn); //Overloaded ostream operator
		CellNode();//Default constructor
		CellNode(DT1* i, Cell<DT2>* c);//Initializer
		CellNode(const CellNode<DT1, DT2>& cn);//Copy constructor
		~CellNode();//Destructor
		Cell<DT2>* getFirstCell();
		DT1* getInfo();
		void operator= (const CellNode<DT1, DT2>& c);//Overloaded assignment operator
	*/

	// MasterCell
	/*
		friend ostream& operator<< (ostream& s, MasterCell<T1, T2>& mc); //Overloaded ostream operator
		MasterCell();//Default constructor
		MasterCell(CellNode<DT1, DT2>* cn);//Initializer
		MasterCell(vector<CellNode<DT1, DT2>> cn);//Initializer
		MasterCell(const MasterCell<DT1, DT2>& mc);//Copy constructor
		~MasterCell();//Destructor
		void addCellNode(DT1* info, Cell<DT2>* cell);
		void operator= (const MasterCell<DT1, DT2>& mc);//Overloaded assignment operator
		CellNode<DT1, DT2>* getCellNodes();
		int getNumNodes();
	*/
	return 0;
}