#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	ios state(nullptr);

	cout << "The answer in decimal is: " << 42 << endl;

	state.copyfmt(cout); // save current formatting
	cout << setw(10) << setfill('0') << "Bonjour" << uppercase << setw(10) << setfill('0') << "" << endl;
	cout.copyfmt(state); // restore previous formatting
}