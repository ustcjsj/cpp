#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

class Film {
public:
   Film() {
      store_title();
      store_director();
      store_time();
      store_quality();
   }
   void store_title( const string& t ) { 
      title = t; 
   }
   void store_title( const char* t = "" ) {
      title = t;
   }
   void store_director( const string& d ) { 
      director = d; 
   }
   void store_director( const char* d = "" ) {
      director = d;
   }
   void store_time( int t = 0 ) { time = t; }
   void store_quality( int q = 0 ) { quality = q; }
   virtual void output();
   virtual void input( ifstream& );
   static bool read_input( const char* fname, Film*[ ], int );
private:
   string title;
   string director;
   int time;   // in minutes
   int quality; // 0 (bad) to 4 (tops)
};

// Reads title, director, time, and quality.
void Film::input( ifstream& fin ) {
   string inbuff;
   getline( fin, inbuff );
   store_title( inbuff );
   getline( fin, inbuff );
   store_director( inbuff );
   getline( fin, inbuff );
   store_time( atoi( inbuff.c_str() ) );
   getline( fin, inbuff);
   store_quality( atoi( inbuff.c_str() ) );
}

// Writes title, director, time, and quality.
void Film::output() {
   cout << "Title: " << title << endl;
   cout << "Director: " << director << endl;
   cout << "Time: " << time << " mins" << endl;
   cout << "Quality: ";
   for ( int i = 0; i < quality; i++ )
      cout << '*';
   cout << endl;
}

class DirectorCut : public Film {
public:
   DirectorCut() {
      store_rev_time();
      store_changes();
   }
   void store_rev_time( int t = 0 ) { rev_time = t; }
   void store_changes( const string& c ) { changes = c; }
   void store_changes( const char* c = "" ) { changes = c; }
   virtual void output();
   virtual void input( ifstream& );
private:
   int rev_time;
   string changes;
};

// Reads revised time and changes.
void DirectorCut::input( ifstream& fin ) {
   Film::input( fin );
   string inbuff;
   getline( fin, inbuff );
   store_rev_time( atoi( inbuff.c_str() ) );
   getline( fin, inbuff );
   store_changes( inbuff );
}

// Writes revised time and changes.
void DirectorCut::output() {
   Film::output();
   cout << "Revised time: " << rev_time << endl;
   cout << "Changes: " << changes << endl;
}

class ForeignFilm : public Film {
public:
   ForeignFilm() { store_language(); }
   void store_language( const string& l ) { language = l; }
   void store_language( const char* l = "" ) { language = l; }
   virtual void output();
   virtual void input( ifstream& );
private:
   string language;
};

// Reads language.
void ForeignFilm::input( ifstream& fin ) {
   Film::input( fin );
   string inbuff;
   getline( fin, inbuff );
   store_language( inbuff );
}

// Writes language.
void ForeignFilm::output() {
   Film::output();
   cout << "Language: " << language << endl;
}

// class method: Film::read_input
// Reads data from an input file, dynamically creating the
// appropriate Film object for each record group. For instance,
// a ForeignFilm object is dynamically created if the data 
// represent a foreign film rather than a regular film or a 
// director's cut. Pointers to dynamically created objects are 
// stored in the array films of size n. Returns true to signal success 
// and false to signal failure.
bool Film::read_input( const char* file, Film* films[ ], int n ) {
   string inbuff;
   ifstream fin( file );
   if ( !fin )  // opened successfully?
     return false; // if not, return false

   // Read until end-of-file. Records fall into
   // groups. 1st record in each group is a string
   // that represents a Film type:
   //   "Film", "ForeignFilm", "DirectorCut", etc.
   // After reading type record, dynamically create
   // an object of the type (e.g., a ForeignFilm object),
   // place it in the array films, and invoke its
   // input method.
   int next = 0;
   while ( getline( fin, inbuff ) && next < n ) {
      if ( inbuff == "Film" ) 
        films[ next ] = new Film();        // regular film
      else if ( inbuff == "ForeignFilm" ) 
        films[ next ] = new ForeignFilm(); // foreign film
      else if ( inbuff == "DirectorCut" ) 
        films[ next ] = new DirectorCut(); // director's cut
      else //**** error condition: unrecognized film type
        continue;
      films[ next++ ]->input( fin ); // polymorphic method
   }
   fin.close();
   return true;
}

