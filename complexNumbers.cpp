
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

const double PI  = 3.141592653589;

double toDegrees(double radians){
    return radians * 180 / PI;
}
double toRadians(double degrees){
    return degrees / 180 * PI;
}

class complex
{
    private:
        double real;
        double imaginary;
        double radius;
        double theta;
        
        
        int getQuarterByAlgebric(){
            if (real > 0 && imaginary > 0) 
                return 1;
            if (real < 0 && imaginary > 0) 
                return 2;
            if (real < 0 && imaginary < 0) 
                return 3;
            return 4;
        }
        int getQuarterByPolar(){
            if(theta >= 0 && theta <= 90)
                return 1;
            if(theta > 90 && theta <= 180)
                return 2;
            if(theta > 180 && theta <= 270)
                return 3;
            return 4;
        }
        void correctTheta(){
            if(theta>=360){
                while(theta>=360)
                    theta -= 360;
            }
            else while(theta<0){
                theta+=360;
            }
        }
        
        void determineTheta(){
            int desiredQuarter = getQuarterByAlgebric();
            int currentQuarter = getQuarterByPolar();
            theta += (desiredQuarter-currentQuarter)*90;
        }
        void updateTheta(){
            this->theta =toDegrees(atan(imaginary / real));
            correctTheta();
            determineTheta();
        }
        
        void setByPolar(){
            double radiansTheta = toRadians(this->theta);
            this->real = this->radius*cos(radiansTheta);
            if(real < 0.0000001)
                real = 0;
            this->imaginary = this->radius*sin(radiansTheta);
            if(imaginary < 0.0000001){
                imaginary = 0;
            }
        }
        
    public:
    // CONSTRUCTOR 
        complex(double real, double imaginary=0){
            this->real = real;
            this->imaginary = imaginary;
            this->radius = sqrt(real*real + imaginary*imaginary);
            this->theta =toDegrees(atan(imaginary / real));
            updateTheta();
        }
        complex(double radius, double theta,bool fromPolar){
            this->radius = radius;
            this->theta = theta;
            correctTheta();
            setByPolar();
        }
       
        // GETS
        double getReal(){
            return this->real;
        }
        double getImaginary(){
            return this->imaginary;
        }
        double getRadius(){
            return this->radius;
        }
        double getTheta(){
            return this->theta;
        }
        
        
        
        //OPERATOR OVERLOADING
        complex operator + (complex const c1){
            return complex(real+c1.real,imaginary+c1.imaginary);
        }
        complex& operator += (complex const c1){
            this->real += c1.real;
            this->imaginary += c1.imaginary;
            updateTheta();
            return *this;
        }
        complex operator - (complex const c1){
            return complex(real-c1.real,imaginary-c1.imaginary);
        }
        complex& operator -= (complex const c1) {
            this->real -= c1.real;
            this->imaginary -= c1.imaginary;
            updateTheta();
            return *this;
        }
        complex operator * (complex const c1){
            double newRadius = this->radius * c1.radius;
            cout << "the new radius is " << newRadius << endl;
            double newTheta = this->theta + c1.theta;
            cout << "the new theta is " << newTheta << endl;
            return complex(newRadius,newTheta,true);
        }
        complex& operator *= (complex const c1){
            this->radius *= c1.radius;
            this->theta *= c1.theta;
            correctTheta();
            determineTheta();
            setByPolar();
            return *this;
        }
        
        bool operator == (complex const c1){
            return real == c1.real && imaginary == c1.imaginary;
        }
        bool operator != (complex const c1){
            return real != c1.real || imaginary != c1.imaginary;
        }
};

int main()
{
   complex c1(1,1),c2(1,1);
   complex result = c1 * c2;

   cout << result.getReal() << "+" <<result.getImaginary() << "i" << endl;
   cout << result.getTheta() << endl;

    return 0;
}
