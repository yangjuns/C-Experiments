#include<iostream>
#include<map>
using namespace std;

/* start of Enclosing class declaration */
class Enclosing {

std::map<int,int> x;

/* start of Nested class declaration */
class Nested {
	int y;
	void NestedFun(Enclosing *e) {
		cout<<e-; // works fine: nested class can access
					// private members of Enclosing class
	}
}; // declaration Nested class ends here
}; // declaration Enclosing class ends here

int main()
{

}
