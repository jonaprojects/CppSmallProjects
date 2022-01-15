#include <cstring>
#include <iomanip>

int main()
{
    // Working with strings in C++ - Practice
    // Creating an std::string
    std::string first_string = "first string";
    const char* c_string{"c string"};
    std::string second_string{c_string};
    // length of the c string
    std::cout << "length with strlen of c string: " << strlen(c_string) << "\n";
    // length of the std::string
    std::cout << "Length of second string: " << second_string.length() << "\n";
    // Access the c string inside the std::string wrapper with the c_str() method.
    std::cout << "Inner c string: " << second_string.c_str() << "\n";

    // using string views instead of copying strings again and again
    std::string my_string = "hello, my world";
    std::cout << my_string << "\n";
    std::string_view my_string_view{my_string};
    std::cout << my_string_view << "\n";
    my_string_view.remove_prefix(7);
    std::cout << my_string_view << "\n";
    my_string_view.remove_suffix(5);
    std::cout << my_string_view << "\n";
    std::cout << "the length: " <<  my_string_view.length() << "\n";
    std::cout << "size of it: " << sizeof(my_string_view) << "\n";
    
    return 0;
}
