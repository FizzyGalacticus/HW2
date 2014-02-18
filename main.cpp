// Dustin Dodson
// Software Construction
// HW #2
// 2-13-14

/* Just messing around with some C++11 features! */

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <future>
using std::async;
using std::future;

#include <mutex>
using std::mutex;

#include <memory> // brings in TEMPLATE macros.

template <typename T>
void Print(const T &thing)
{
	mutex coutLock;
	std::unique_lock<mutex> m(coutLock);
	cout << thing << endl;
}

int main(int argc, const char * argv[])
{
	auto NUMBEROFVARIABLES = 0;
	
	//Sets number of times things will happen
	if(argc > 1) NUMBEROFVARIABLES = (argv[1][0]-47);
	else NUMBEROFVARIABLES = 101;
	//Messing with 'auto' keyword
	auto myInt = 21;
	auto myStr = "Hello, world!";
	auto name = "Dustin Dodson";
	auto myFloat = (9.0/12.0);
	auto age = myInt + myFloat;
	
	//Printing objects created with 'auto' keyword
	cout << myStr << " My name is " << name
		<< " and I am " << age << " years old!" << endl;
	
	//Playing with shared_pointer
	vector<int> myNums;
	vector<std::shared_ptr<int>> myPtrs;
	
	for(int i = 1; i < NUMBEROFVARIABLES; i++) myNums.push_back(i);
	
	//Print things and create smart pointers
	for(auto num : myNums)
	{
		Print(num); //print out regular objects
		auto _ptr = std::make_shared<int>(num);
		myPtrs.push_back(_ptr);
	}
	
	//Fibonocci lambda function
	std::function<int(int)> fibo = [&fibo](int n) {return n < 2 ? 1 : fibo(n-1) + fibo(n-2);};
	
	//Printing out fibo numbers from shared_ptr values
	for(auto num : myPtrs) Print(fibo(*num));
	
	//Compiles, but does not run.
	//for(auto num : myNums) async(std::launch::async,Print,num);
	
	
	
	return 0;
}
