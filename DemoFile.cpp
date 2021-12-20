#include "DemoFile.h"
#include <iostream>

DemoFile::DemoFile(std::string file_name, std::string file_suffix, std::string content, unsigned int file_size, DateTime creation_date, bool is_open)
{

}

std::string DemoFile::get_file_name()
{
	return this->file_name;
}

std::string DemoFile::get_file_suffix()
{
	return this->file_suffix;
}

std::string DemoFile::get_content()
{
	return this->content;
}

unsigned int DemoFile::get_file_size()
{
	return this->file_size;
}

DateTime DemoFile::get_creation_date()
{
	return this->creation_date;
}
bool DemoFile::get_is_open() {
	return this->is_open;
}

void DemoFile::set_file_name(std::string file_name)
{
	this->file_name = file_name;
}

void DemoFile::set_file_suffix(std::string file_suffix)
{
	this->file_suffix = file_suffix;
}

void DemoFile::set_file_content(std::string content)
{
	this->content = content;
}

void DemoFile::set_file_size(unsigned int file_size)
{
	this->file_size = file_size;
}

void DemoFile::set_creation_date(DateTime creation_date)
{
	this->creation_date = creation_date;
}

void DemoFile::set_is_open(bool is_open)
{
	this->is_open = is_open;
}

