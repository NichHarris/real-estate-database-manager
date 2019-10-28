#include<stdint.h>
#include<string>
#include"Client.h"

Client::Client() : Person() {
	socialinsurancenumber = " ";
}

Client::Client(std::string n, std::string adr, std::string sin) : Person(){
	socialinsurancenumber = sin;
}

Client::Client(const Client& client) {
	socialinsurancenumber = client.socialinsurancenumber;
}
Client::~Client() {
	std::cout << "Client destructor called" << std::endl;
}

void Client::print() {
	Person::print();
	std::cout << "Client SIN: " << socialinsurancenumber << std::endl;
}

void Client::setSIN(std::string sin) {
	socialinsurancenumber = sin;
}

std::string Client::getSIN() const{
	return socialinsurancenumber;
}

