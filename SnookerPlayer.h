#pragma once
#include <iostream>
class SnookerPlayer
{
private:
	std::string id;
	std::string father_id;
	std::string mother_id;
	int born_year;
	std::string phone;

public:
	SnookerPlayer(std::string id, std::string father_id, std::string mother_id, int born_year, std::string phone);
	bool family(SnookerPlayer p);
	std::string to_string();
	std::string get_id();
	std::string get_father_id();
	int get_born_year();
	int get_age(const int& current_year);
	std::string get_phone();
};

