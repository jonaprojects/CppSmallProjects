#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
using std::cout;
using std::endl;
using std::string;

int main(){
     if (__cplusplus == 201703L) std::cout << "C++17\n";
    else if (__cplusplus == 201402L) std::cout << "C++14\n";
    else if (__cplusplus == 201103L) std::cout << "C++11\n";
    else if (__cplusplus == 199711L) std::cout << "C++98\n";
    else std::cout << "pre-standard C++\n";
    int collection[]{1,3,5,7,4};
    auto is_even = [](int num)->bool{return num % 2 == 0;};
    if(std::any_of(std::begin(collection),std::end(collection),is_even)){
        printf("Yep\n");
    }else{
        printf("Nope");
    }
    return 0;
}