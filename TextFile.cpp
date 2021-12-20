#include "TextFile.h"
#include <iostream>
#include <cstring>

TextFile::TextFile(const char* path, const char* mode) {
	this->path = path;
	this->mode = mode;
	this->ptr = new FILE{ nullptr };
	this->buffer = new char[255];
}
//getters
const char* TextFile::get_path() { return this->path; }
bool TextFile::get_is_open() { return this->is_open; }
const char* TextFile::get_mode() { return this->mode; }

// setters
void TextFile::set_path(const char* path) {
	this->path = path;
}
void TextFile::set_mode(const char* mode) {
	this->mode = mode;
}

bool TextFile::open() {
	this->ptr = fopen(this->path, this->mode);
	if (this->ptr == nullptr) {
		throw std::exception("Couldn't open the file");
	}
}

const char* TextFile::read_line()
{
	if (this->mode != "r") {
		throw std::exception("Invalid operation to a file ");
	}
	auto result = fgets(this->buffer, 255, this->ptr);
	if (result == NULL) {
		return NULL;
	}
	return this->buffer;
}
const char* TextFile::read() {
	char* accumulator{};
	while (fgets(this->buffer, 255, this->ptr)) {
		strcat(accumulator, buffer);
	}
	return accumulator;
}

bool TextFile::write()
{
	throw std::exception("not implemented yet !");
}

bool TextFile::append()
{
	throw std::exception("not implemented yet !");
}

void TextFile::close() {
	fclose(this->ptr);
}

TextFile::~TextFile() { // free memory allocated, to avoid memory leaks !
	delete this->ptr;
	delete this->buffer;
}
// ToString()
std::string TextFile::to_string() {
	return this->path;
}

