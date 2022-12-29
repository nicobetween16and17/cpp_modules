#include <iostream>

using namespace std;

class Contact{
	int index;
	string first_name;
	string last_name;
	string secret;
	string phone_number;
	string nickname;
public:
	void setindex(int index){
		this->index = index;
	}

	int getindex(){
		return (this->index);
	}

	void setfirst_name(string first_name){
		this->first_name = first_name;
	}

	string getfirst_name(){
		return (this->first_name);
	}

	void setlast_name(string last_name){
		this->last_name = last_name;
	}

	string getlast_name(){
		return (this->last_name);
	}

	void setsecret(string secret){
		this->secret = secret;
	}

	string getsecret(){
		return (this->secret);
	}

	void setphone_number(string phone_number){
		this->phone_number = phone_number;
	}

	string getphone_number(){
		return (this->phone_number);
	}

	void setnickname(string nickname){
		this->nickname = nickname;
	}

	string getnickname(){
		return (this->nickname);
	}

	Contact(){
	}

	Contact(int index, string first_name, string last_name, string secret, string phone_number, string nickname){
		this->index = index;
		this->first_name = first_name;
		this->last_name = last_name;
		this->secret = secret;
		this->phone_number = phone_number;
		this->nickname = nickname;
	}
};
