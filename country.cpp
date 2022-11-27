#include "country.h"
#include <iostream>
using namespace std;

Country::Country() {
	this->name = "";
	this->pop = 0;
}

string Country::getName() {
	return this->name;
}

long Country::getPop() {
	return this->pop;
}

ostream& operator<<(ostream& output, const Country& ct) {
	output << ct.name << " " << ct.pop;
	return output;
}

istream& operator>>(istream& input, Country& ct) {
	char sink;
	input >> ct.name >> ct.pop;
	return input;
}


// Overloaded > operator
bool Country::operator>(const Country& ct) {
    if (pop > ct.pop) {
        return true;
    }
    else {
        return false;
    }
}


// Overloaded < operator
bool Country::operator<(const Country& ct) {
    if (pop < ct.pop) {
        return true;
    }
    else {
        return false;
    }
}


// Overloaded == operator
bool Country::operator==(const Country& ct) {
    return this->pop == ct.pop;
}



