#pragma once
#include <string>
class Country
{
	std::string name;
	long pop;
public:
	Country(std::string name, long pop) : name(name), pop(pop) {}
	Country();
	std::string getName();
	long getPop();
	
	friend std::ostream& operator<<(std::ostream& output, const Country& ct);
	friend std::istream& operator>>(std::istream& input, Country& ct);
	bool operator>(const Country& ct);
	bool operator<(const Country& ct);
	bool operator==(const Country& ct);
};

