#include <iostream>
#include <string>
#include <algorithm>
#include "contact.hpp"
using namespace std;

class Phonebook{
	Contact	contacts[9];
	int		index;
	int		full;

public:
	void setcontacts(Contact contact){
		if (this->index == 8)
		{
			this->full = 1;
			this->index = 0;
		}
		contact.setindex(this->index);
		this->contacts[this->index] = contact;
		this->index++;
	}
	int get_index(){
		return (this->index);
	}

	int get_full(){
		return (this->full);
	}

	Contact* getcontact(){
		return (this->contacts);
	}

	Phonebook(){
		this->full = 0;
		this->index = 0;
	}
};