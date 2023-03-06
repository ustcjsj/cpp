class Complex2 {
public:
	Complex2();                 // default
	Complex2(double);         // real given
	Complex2(double,double); // both given

	void write() const;

	double get_real() const { return real;}
	double get_imag() const { return imag;}
private:
	double real;
	double imag;
};
Complex2 operator+ (const Complex2&, const Complex2&);
Complex2 operator- (const Complex2&, const Complex2&);
Complex2 operator* (const Complex2&, const Complex2&);
Complex2 operator/ (const Complex2&, const Complex2&);

//6.5 输入输出操作符的重载:例6-12 
ostream& operator<<(ostream& out,Complex2& c);