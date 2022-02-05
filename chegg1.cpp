#include <iostream>
using namespace std;
 
class Complex{
public:
  float real;
  float img;

  Complex(){
    this->real = 0.0;
    this->img = 0.0;
  }
  Complex(float a)
  {
      this->real=a;
      this->img=0.0;
  }
  Complex(float real, float img){
    this->real = real;
    this->img = img;
  }

  //overloading + operator
  Complex operator+(const Complex &obj){
    Complex temp;
    temp.img = this->img + obj.img;
    temp.real = this->real + obj.real;
    return temp;
  }

  //overloading - operator
  
  
  //overloading * operator
  complex operator*(const complex &obj)
  {
      complex temp;
      temp.img=this->img*obj.real+this->real*obj.img;
      temp.real=this->real*obj.real-this->img*obj.img;
      return temp;
  }
  void display(){
    cout << this->real << " + " << this->img << "i" << endl;
  }
};
 Complex operator-(const Complex &obj,const complex &obj2){
    Complex temp;
    temp.img = obj->img - obj2.img;
    temp.real = obj->real - obj2.real;
    return temp;
  }
int main()
{
  Complex a, b, c;

  cout << "Enter real and complex coefficient of the first complex number: " << endl;
  cin >> a.real;
  cin >> a.img;

  cout << "Enter real and complex coefficient of the second complex number: " << endl;
  cin >> b.real;
  cin >> b.img;

  cout << "Addition Result: ";
  c = a+b;
  c.display();

  cout << "Subtraction Result: ";
  c = a-b;
  c.display();

  return 0;
}