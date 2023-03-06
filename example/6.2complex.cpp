class Complex {
public:
   Complex();                 // default
   Complex( double );         // real given
   Complex( double, double ); // both given

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

// default constructor
Complex::Complex() {
   real = imag = 0.0;
}

// constructor -- real given but not imag
Complex::Complex( double re ) {
   real = re;
   imag = 0.0;
}

// constructor -- real and imag given
Complex::Complex( double re, double im ) {
   real = re;
   imag = im;
}

void Complex::write() const {
   cout << real << " + " << imag << 'i';
}

// Complex + as binary operator
Complex Complex::operator+( const Complex& u ) const {
   Complex v( real + u.real,
              imag + u.imag );
   return v;
}

// Complex - as binary operator
Complex Complex::operator-( const Complex& u ) const {
   Complex v( real - u.real,
              imag - u.imag );
   return v;
}

// Complex * as binary operator
Complex Complex::operator*( const Complex& u ) const {
   Complex v( real * u.real - imag * u.imag,
              imag * u.real + real * u.imag );
   return v;
}

// Complex / as binary operator
Complex Complex::operator/( const Complex& u ) const {
   double abs_sq = u.real * u.real + u.imag * u.imag;
   Complex v( ( real * u.real + imag * u.imag ) / abs_sq,
              ( imag * u.real - real * u.imag ) / abs_sq );
   return v;
}
