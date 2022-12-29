#include "phonebook.hpp"
#include <iomanip>

using namespace std;

void add(Phonebook *phonebook){
	string str;
	Contact c = Contact();
	cout << "Please give the following informations:";
	cout << "\nfirst name\n:";
	getline(cin, str);
	c.setfirst_name(str);
	cout << "\nlast name\n:";
	getline(cin, str);
	c.setlast_name(str);
	cout << "\nnickname\n:";
	getline(cin, str);
	c.setnickname(str);
	cout << "\nphone number\n:";
	getline(cin, str);
	c.setphone_number(str);
	cout << "\ndarkest secret\n:";
	getline(cin, str);
	c.setsecret(str);
	phonebook->setcontacts(c);
	cout << phonebook->get_index();
}

void search(Phonebook *phonebook){
	int n;
	int i;
	string cpy_name;
	string cpy_lastname;
	string cpy_nickname;
	i = -1;
	n = phonebook->get_index();
	if (phonebook->get_full())
		n = 7;
	if (!n) {
		cout << "no contacts in the phonebook\n";
		return;
	}

	do {
		while (++i < n) {
			cpy_name = phonebook->getcontact()[i].getfirst_name().substr(0, 9);
			cpy_lastname = phonebook->getcontact()[i].getlast_name().substr(0, 9);
			cpy_nickname = phonebook->getcontact()[i].getnickname().substr(0, 9);
			if (cpy_name.length() == 9)
				cpy_name.insert(cpy_name.end(), '.');
			if (cpy_lastname.length() == 9)
				cpy_lastname.insert(cpy_lastname.end(), '.');
			if (cpy_nickname.length() == 9)
				cpy_nickname.insert(cpy_nickname.end(), '.');
			cout << setw(10) << setfill(' ') << phonebook->getcontact()[i].getindex() << "|";
			cout << setw(10) << setfill(' ') << cpy_name << "|";
			cout << setw(10) << setfill(' ') << cpy_lastname << "|";
			cout << setw(10) << setfill(' ') << cpy_nickname << endl;
		}
		cout << "Type the index of the one you want to see\n:";
		string s;
		i = -1;
		getline(cin, s);
		for (unsigned long j = 0; j < s.length(); j++)
			if (isdigit(s[j]))
				i = stoi(s);
		if (i < 0 || (!phonebook->get_full() && phonebook->get_index() < i + 1) || (phonebook->get_full() && i > 7))
			cout << "wrong input\n";
		else {
			cout <<endl<< setw(10) << setfill(' ') << "name: " << phonebook->getcontact()[i].getfirst_name() << endl
				 << setw(10) << setfill(' ') << "lastname: " << phonebook->getcontact()[i].getlast_name() << setw(10)<< endl
				 << setfill(' ') << "nickmame: " << phonebook->getcontact()[i].getnickname() << setw(10)<< endl
				 << setfill(' ') << "number: " << phonebook->getcontact()[i].getphone_number()<< endl
				 << setw(10) << setfill(' ') << "secret: " << phonebook->getcontact()[i].getsecret() << endl;
			break;
		}
	} while (1);
}

#include <stdio.h>

int main(void){
	Phonebook p = Phonebook();

	while (1) {
		string str;
		cout << "choose one:\n\tADD(1)\n\tSEARCH(2)\n\tEXIT(3)\n:";
		getline(cin, str);
		if (!str.compare("ADD") || !str.compare("1"))
			add(&p);
		else if (!str.compare("SEARCH") || !str.compare("2"))
			search(&p);
		else if (!str.compare("EXIT") || !str.compare("3"))
			exit(0);
		else
			cout << "\nwrong input";
		cout << endl;
	}
}