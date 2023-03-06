
class Complex {
public:
	Complex();                 // default
	Complex(double);         // real given
	Complex(double,double); // both given

	void write() const;
	// operator methods
	Complex operator+( const Complex& ) const;
	Complex operator-( const Complex& ) const;
	Complex operator*( const Complex& ) const;
	Complex operator/( const Complex& ) const;
private:
	double real;
	double imag;
};