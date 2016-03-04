# include <iostream>
using namespace std;
template <class	DT>
class	Cell {
protected:
	DT* _value;
	Cell<DT>* _right;
public:
	//All	required	methods	
	//Default constructor
	//Initializer
	//Copy constructor
	//Destructor
	//Overloaded assignment operator
	//Overloaded ostream operator
};

///////////////////////////////////////////////////////////////////////////////////////

template <class	DT1, class	DT2>
class CellNode {
protected:
	DT1*	_info;
	Cell<DT2>*	_myCell;
public:
	//All	required	methods	
	//Default constructor
	//Initializer
	//Copy constructor
	//Destructor
	//Overloaded assignment operator
	//Overloaded ostream operator
};


///////////////////////////////////////////////////////////////////////////////////////

template <class	DT1, class	DT2>
class MasterCell {
protected:
	CellNode<DT1, DT2>*	_myCellNodes;
public:
	//All	required	methods
	//Default constructor
	//Initializer
	//Copy constructor
	//Destructor
	//Overloaded assignment operator
	//Overloaded ostream operator
};

///////////////////////////////////////////////////////////////////////////////////////

int main() {
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