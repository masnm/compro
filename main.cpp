
#include <iostream> 
#include <thread> 
using namespace std; 

void foo(int Z) 
{ 
	for (int i = 0; i < Z; i++) { 
		cout << "Thread using function"
			   " pointer as callable\n"; 
	} 
}
  
int main() 
{ 
	cout << "Threads 1 and 2 and 3 "
		 "operating independently" << endl; 

	thread th1(foo, 3);
  
	// Define a Lambda Expression 
	auto f = [](int x) { 
		for (int i = 0; i < x; i++) 
			cout << "Thread using lambda"
			 " expression as callable\n"; 
	}; 

	thread th3(f, 3); 

	th1.join();

	th3.join(); 
  
	return 0; 
} 