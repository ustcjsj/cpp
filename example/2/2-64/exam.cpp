#include <iostream>
#include <string>
using namespace std;
struct Elephant {
	string name;
	Elephant* next;
};
void print_elephants( const Elephant* ptr );
Elephant* get_elephants();
void free_list( const Elephant* ptr );
int main() {
Elephant* start;
start = get_elephants();
print_elephants( start );
free_list( start );
return 0;
}
// get_elephants dynamically allocates storage for nodes. 
// It builds the linked list and stores user-supplied names in the 
// name member of the nodes. It returns a pointer
// to the first such node.
Elephant* get_elephants() {
Elephant *current, *first;
int response;
// allocate first node
current = first = new Elephant;
// store name of first Elephant
cout << "\nNAME: ";
cin >> current -> name;
// prompt user about another Elephant
cout << "\nAdd another? (1 == yes, 0 == no): ";
cin >> response;
// Add Elephants to list until user signals halt.
while ( response == 1 ) {
// allocate another Elephant node
current = current -> next = new Elephant;
// store name of next Elephant
cout << "\nNAME: ";
cin >> current -> name;
// prompt user about another Elephant
cout << "\nAdd another? (1 == yes, 0 == no): ";
cin >> response;
}
// set link field in last node to 0
current -> next = 0;
return first;
}
// print_elephants steps through the linked
// list pointed to by ptr and prints the name
// member in each node as well as the position
// of the node in the list
void print_elephants( const Elephant* ptr ) {
int count = 1;
cout << "\n\n\n";
while ( ptr != 0 ) {
cout << "Elephant number " << count++
<< " is " << ptr -> name << '\n';
ptr = ptr -> next;
}
}
// free_list steps through the linked list pointed
// to by ptr and frees each node in the list
void free_list( const Elephant* ptr ) {
const Elephant* temp_ptr;
while ( ptr != 0 ) {
temp_ptr = ptr -> next;
delete ptr;
ptr = temp_ptr;
}
}
