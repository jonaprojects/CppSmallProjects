#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <complex>
#include <map>
#include <ctype.h>
#include <algorithm>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::complex;
using std::map;
const int PI = 3.141592653589793;
int first_letter_index(string& letters){
    for(int i = 0; i<letters.length(); ++i){
        if(isalpha(letters[i])){
            return i;
        }
    }
    return -1;
}
template <typename Map>
bool map_compare (Map const &lhs, Map const &rhs) {
    // No predicate needed because there is operator== for pairs already.
    return lhs.size() == rhs.size()
        && std::equal(lhs.begin(), lhs.end(),
                      rhs.begin());
}
bool pair_exists(map<char,float>& values, std::pair<char,float>& pair){
    for(std::pair<char,float> current_pair : values){
        if(current_pair.first == pair.first && current_pair.second == pair.second){
            return true;
        }
    }
    return false;
}
map<char,float> union_maps(map<char,float> first, map<char,float>& second){
    for(std::pair<char,float> pair : second){
        if(!pair_exists(first,pair)){
            first.insert(pair);
        }
    }
    return first;
}

string custom_strip(string letters){
    string without_spaces = "";
    for(char& letter : letters){
        if(letter != ' '){
            without_spaces += letter;
        }
    }
    return without_spaces;
}

class BaseExpression{

};
class PolyExpr;
class MonoExpr:public BaseExpression{
    private:
        float coefficient;
        map<char,float> variables{};

        void initialize_by_string(string expression){
            string cleaned_expression = custom_strip(expression);
            int first_letter = first_letter_index(cleaned_expression);
            if(first_letter == -1){
                this->coefficient = std::stof(cleaned_expression);
                return;
            }
            string temp{""};
            for(int i = 0; i<first_letter ; ++i){
                temp += cleaned_expression[i];
            }
            this->coefficient = std::stof(temp);
            temp.clear();
            for(int i = first_letter; i < cleaned_expression.length(); ++i){  // starting after the coefficient
                if(cleaned_expression[i] == '*'){
                   string power{std::find(temp.begin(), temp.end(), '^')+1,temp.end()};
                   if(power.length() == 0){ // this part doesn't have a power, i.e, doesn't contain the '^' symbol 
                        this->variables.insert(std::pair<char,float>{temp[0],1});
                    }
                    else{
                        this->variables.insert(std::pair<char,float>{temp[0],std::stof(power)}); // e.g, x^2, y^3
                    }
                    temp.clear();
                }
                else{
                    temp += cleaned_expression[i]; // accumulates the letters otherwise
                }
            }
            string power{std::find(temp.begin(), temp.end(), '^')+1,temp.end()};
            if(power.length() == 0){ // this part doesn't have a power, i.e, doesn't contain the '^' symbol 
                        this->variables.insert(std::pair<char,float>{temp[0],1});
                }
            else{
                        this->variables.insert(std::pair<char,float>{temp[0],std::stof(power)}); // e.g, x^2, y^3
                }

            
        }
    public:
    MonoExpr(string expression){
        this->initialize_by_string(expression); // extracts the data from the string
    }
    MonoExpr(float coefficient, map<char,float> variables){
        this->coefficient = coefficient;
        this->variables = variables;
    }
    MonoExpr(float coefficient){
        this->coefficient = coefficient;
    }
    // GET methods
    float get_coefficient(){return this->coefficient;};
    map<char,float> get_variables(){return this->variables;};

    // Additional methods
    unsigned int num_of_vars(){
        return variables.size();
    }
    BaseExpression operator + (MonoExpr other){
        if(map_compare(this->variables,other.variables)){ // same variables, therefore can be subtracted !
            MonoExpr result{this->coefficient+other.coefficient,other.variables};       
        }
        else{
            MonoExpr copy{*this};
            //return PolyExpr{vector<MonoExpr>{copy,other}};
        }
    }
    BaseExpression operator  + (float number){
        if(this->variables.empty()){
           return MonoExpr{this->coefficient+number, this->variables};
        }else{
            MonoExpr copy{*this},freeNumber{number};
            //return PolyExpr(vector<MonoExpr>{copy,freeNumber});
        }
    }
    BaseExpression& operator += (MonoExpr other){
        if(map_compare(this->variables,other.variables)){ // same variables, therefore can be subtracted !
            this->coefficient += other.coefficient;       
        }
        else{
            throw std::logic_error("NotImplementedException");
        }
    }
    MonoExpr operator - (MonoExpr other){
        if(map_compare(this->variables,other.variables)){ // same variables, therefore can be subtracted !
            MonoExpr result{this->coefficient-other.coefficient,other.variables};   
            return *this;    
        }
        else{
            throw std::logic_error("NotImplementedException");
        }
    }
    MonoExpr& operator -= (MonoExpr other){
        if(map_compare(this->variables,other.variables)){ // same variables, therefore can be subtracted !
               this->coefficient -= other.coefficient;
               return *this;
        }
        else{
            throw std::logic_error("NotImplementedException");
        }
    }
    MonoExpr operator * (float number){
        MonoExpr result{this->coefficient*number,variables};
        return result;
    }
    MonoExpr operator * (MonoExpr other){
        MonoExpr result{this->coefficient * other.coefficient, union_maps(this->variables,other.variables)};
        return result;
    }
    MonoExpr& operator *= (float number){
        this->coefficient *= number;
        return *this;
    }
    MonoExpr operator / (float number){
        if(number == 0){
            throw std::invalid_argument("Cannot divide a monomial expression by 0");
        }
        MonoExpr result{this->coefficient/number,this->variables};
        return result;
    }


    string to_string()
    {
       if(this->coefficient == 0){
           return "0";
       }
       string accumulator = "";
       accumulator = this->coefficient == 1 ? "" : std::to_string(this->coefficient);
       cout << "Checking if the variables are empty : " << variables.empty() << endl;
        for(auto pair:this->variables){
            cout << "iterating on the variables" << endl;
            accumulator += pair.first; // add the variable first
            accumulator += '^';
            accumulator.append(std::to_string(pair.second));
        }
        return accumulator;
    }
        
        
};
class PolyExpr:public BaseExpression{
    private:
        vector<MonoExpr> expressions;
        void initialize_from_string(string initial_expression){
            string cleaned_expression = custom_strip(initial_expression);
            string temp{""};
            for(size_t i = 0 ; i<cleaned_expression.length() ; ++i){
                if(cleaned_expression[i] == '+' || cleaned_expression[i] == '-'){
                    this->expressions.push_back(MonoExpr(temp));
                    temp.clear();
                }else{
                    temp += cleaned_expression[i];
                }
            }
            if(!temp.empty()){
                this->expressions.push_back(MonoExpr(temp));
            }

        }
    public:
    // Constructors
        PolyExpr(vector<MonoExpr> expressions){
            this->expressions = expressions;
        }
        PolyExpr(MonoExpr* expressions, unsigned int size){
            for(size_t i = 0 ; i < size ; ++i){
                this->expressions.push_back(expressions[i]);
            }
        }
        PolyExpr(string expression){
            initialize_from_string(expression);
        }
        // get method
        vector<MonoExpr> get_expressions(){return this->expressions;};

        // Operators overloading 

        MonoExpr operator [](size_t i){
            if(i>=0 && i<this->expressions.size()){
                return this->expressions[i];
            }
            throw std::out_of_range("Index out of range");
        }

        // ToString() method 
        string to_string(){
            string accumulator{""},temp{""};
            for(MonoExpr expression:this->expressions){
                temp = expression.to_string();
                if(temp[0] != '-' || temp[0] != '+'){
                    accumulator += "+";
                }
                accumulator += temp;
            }
            return accumulator;
        }
};
float newton_raphson(float (*f_0)(float),float (*f_1)(float),float initial_value,float epsilon=0.00001, int nmax = 100000){
    float current_x = initial_value, y,y_tag;
    for(size_t i = 0 ; i<nmax; ++i){
        y = f_0(current_x);
        //printf("(%f,%f)\n",current_x,y);
        if(std::abs(y) < epsilon){
            return current_x;}
        y_tag = f_1(current_x);
        current_x -= y / y_tag;
    }
    cout << "Warning: The solution might not be accurate!" << endl;
    return current_x;
}
vector<complex<float>> initial_approximations(vector<float> coefficients){
    unsigned int n = coefficients.size();
    float radius =  std::sqrt(std::abs(coefficients[n-1] /  coefficients[0]));
    vector<complex<float>> initials;
    float angle;
    for(size_t k=0; k<n-1 ; ++k){
        angle = 2*PI*k /n;
        initials.push_back(complex<float>{radius*std::cos(angle),radius*std::sin(angle)});
    }
    return initials;
}
vector<complex<float>> aberth_method(complex<float>(*f_0)(complex<float>),complex<float> (*f_1)(complex<float>),
                                         vector<float>coefficients,float epsilon=0.00001,int nmax=100000){
    vector<complex<float>> initials = initial_approximations(coefficients);
    unsigned int n = coefficients.size(); // the number of coefficients
    complex<float> offsets[n-1]; // array of complex numbers that represents the differences between the approximations and the solutions
    complex<float> y,y_tag,m,sum;
    complex<float> one = complex<float>{1,0};
    bool all_converged;
    for(size_t iteration = 0; iteration < nmax ; ++iteration){ // Continue with this loop until convergence
        all_converged = true; // assuming that all of the roots have converged
        for(size_t i = 0; i<n-1 && all_converged ; ++i){ // checking if the roots have converged
                y = f_0(initials[i]); 
                if(y.real() > epsilon || y.imag() > epsilon){
                    all_converged = false;}
        }
        if(all_converged){return initials;} // if the roots have converged, return them
        // otherwise, continue with the algorithm.
        for(size_t k = 0 ; k < n-1 ; ++k){ // create n offsets, and subtract each offset from the corresponding approximation.
            y = f_0(initials[k]); // 
            y_tag = f_1(initials[k]);
            m = y/y_tag;
            sum = 0;
            for(size_t j = 0; j < n-1 ; ++j){ // computing the result of the sigma in the denominator of the formula 
            // for computing the offsets
                if(j == k || initials[k] == initials[j]){ // avoid dividing by 0 in later  
                    continue;}
                sum += one/(initials[k]-initials[j]);
            }
            offsets[k] = m / (one - m * sum);
            initials[k] -= offsets[k]; // subtract the current offset from the approximation
        }
        
    }
    printf("WARNING: it's highly likely the initial values haven't converged sufficienly to the solutions\n");
    return initials;

}

int main(){

    MonoExpr monomial{"3x^2"};
    cout << monomial.to_string() << endl;

    auto f_0 = [](complex<float> x)->complex<float>{
        return pow(x,4)+complex<float>{8,0};
    };
    auto f_1 = [](complex<float> x)->complex<float>{
        return pow(x,3)*complex<float>{4,0};
    };
    vector<float> coefficients{1,0,0,0,8};
    vector<complex<float>> solutions = aberth_method(f_0,f_1,coefficients);
    for(size_t i = 0; i<4 ; ++i){
        cout << solutions[i] << endl;
    }
    return 0;
    auto my_function = [](float x)->float{ return x*x-6*x+8;};
    auto my_derivative = [](float x)->float{return 2*x-6;};
    float function_zero = newton_raphson(my_function,my_derivative,-22);
    printf(" x^2 -6x+8 = 0 has a zero at %f\n",function_zero);
    return 0;
}

