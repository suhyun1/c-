#include<iostream>
using namespace std;

class complex {

	float real;
	float imag;

public:
	complex();
	complex(float a, float b);
	complex(const complex &c);

	complex operator+(const complex &c);
	complex operator-(const complex &c);
	complex operator*(const complex &c);
	complex operator/(const complex &c);
	void print();

};
complex::complex() {
	real = 0;
	imag = 0;
}
complex::complex(float a, float b) {
	real = a;
	imag = b;
}
complex::complex(const complex &c) {
	real = c.real;
	imag = c.imag;
}
complex complex::operator+(const complex &c) {
	complex comp(real + c.real, imag + c.imag);
	
	//동작 같음 
//	complex comp;
//	comp.real = real+c.real;
//	comp.imag=imag+c.imag;
	return comp;
}

complex complex::operator-(const complex &c) {
	complex comp(real - c.real, imag - c.imag);
	return comp;
}

complex complex::operator*(const complex &c) {
	complex comp(real*c.real - imag*c.imag, real*c.imag + imag*c.real);
	return comp;
}

complex complex::operator/(const complex &c) {
	complex comp((real * c.real + imag * c.imag) / (c.real * c.real + c.imag * c.imag),
		(imag * c.real - real * c.imag) / (c.real * c.real + c.imag * c.imag));

	return comp;
}


void complex::print() {

	if (imag<0)
		cout << real << "-" << -imag << "i" << endl;
	else
		cout << real << "+" << imag << "i" << endl;
}

int main(){
	complex a(2,3);
	complex b(-1, 4);
	
	complex c = a+b;
	c.print();
}
