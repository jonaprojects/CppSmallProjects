#pragma once
#include <iostream>
struct DateTime {
	unsigned int day, month, year;
} typedef DateTime;

class DemoFile
{
private:
	std::string file_name, file_suffix, content;
	 unsigned int file_size;
	 DateTime creation_date;
	 bool is_open;
public:
	// constructor
	DemoFile(std::string file_name, std::string file_suffix, std::string content, unsigned int file_size, DateTime creation_date, bool is_open);
	// getters
	std::string get_file_name();
	std::string get_file_suffix();
	std::string get_content();
	unsigned int get_file_size();
	DateTime get_creation_date();
	bool get_is_open();
	// setters
	void set_file_name(std::string file_name);
	void set_file_suffix(std::string file_suffix);
	void set_file_content(std::string content);
	void set_file_size(unsigned int file_size);
	void set_creation_date(DateTime creation_date);
	void set_is_open(bool is_open);
};

