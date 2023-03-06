namespace sz 
{
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
}