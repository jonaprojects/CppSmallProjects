#pragma once
#include <iostream>
class TextFile
{
private:
	const char* path;
	const char* mode;
	bool is_open = false;
	FILE* ptr{ nullptr };
	char* buffer;
public:
	// constructor
	TextFile() = default;
	TextFile(const char* path, const char* mode = "r");

	// getters
	const char* get_path();
	const char* get_mode();
	bool get_is_open();

	// setters
	void set_path(const char* path);
	void set_mode(const char* mode);
	// to_string()
	std::string to_string();

	bool open();
	const char* read();
	const char* read_line();
	bool write();
	bool append();
	void close();
	~TextFile();

};

