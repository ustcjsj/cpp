#include <iostream>
using namespace std;
#include "Complex2.h"
namespace sz 
{
	// default constructor
	Complex2::Complex2() {
	   real = imag = 0.0;
	}
	// constructor -- real given but not imag
	Complex2::Complex2( double re ) {
	   real = re;
	   imag = 0.0;
	}
	// constructor -- real and imag given
	Complex2::Complex2( double re, double im ) {
	   real = re;
	   imag = im;
	}

	void Complex2::write() const {
	   cout << real << " + " << imag << 'i';
	}

	Complex2 operator + (const Complex2& t, const Complex2& u)
	{	return Complex2( t.get_real() + u.get_real(),
								  t.get_imag() + u.get_imag() );
	}
	Complex2 operator - (const Complex2& t, const Complex2& u)
	{	return Complex2( t.get_real() - u.get_real(),
								  t.get_imag() - u.get_imag() );
	}
	Complex2 operator * (const Complex2& t, const Complex2& u)
	{		return  Complex2( t.get_real() * u.get_real()
			 - t.get_imag() * u.get_imag(),  
			t.get_imag() * u.get_real() + t.get_real() * u.get_imag() );
	}
	Complex2 operator / (const Complex2& t, const Complex2& u)
	{  double abs_sq = u.get_real() * u.get_real()
			+ u.get_imag() * u.get_imag();

		return Complex2( (t.get_real() * u.get_real()
			+ t.get_imag() * u.get_imag()) / abs_sq,
			(t.get_imag() * u.get_real()
			- t.get_real() * u.get_imag()) / abs_sq );
	}
}