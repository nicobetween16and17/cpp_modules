#include <iostream>
#include <algorithm>

using namespace std;
int main(int ac, char **av)
{
	int i = 0;
	if (ac == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (++i < ac){
		string s = av[i];
		transform(s.begin(), s.end(), s.begin(), ::toupper);
		cout << s;

	}
	std::cout << "\n";
	return (0);
}