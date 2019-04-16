#include <iostream>
#include <string>

using namespace std;

int main () {
	string x = "hey/pocholo";
	cout << x << endl;
	string a = x.substr (0, x.find('/'));
	x.erase(0,x.find('/'));
	cout  << a << endl << x <<endl;
}