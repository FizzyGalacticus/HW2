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

//template <typename T>
void myPrint(const int &thing)
{
	mutex coutLock;
	std::unique_lock<mutex> m(coutLock);
	cout << thing << endl;
}

int main(int argc, const char * argv[])
{
	auto myInt = 21;
	auto myStr = "Hello, world!";
	auto name = "Dustin Dodson";
	auto myFloat = (9.0/12.0);
	auto age = myInt + myFloat;
	
	cout << myStr << " My name is " << name
		<< " and I am " << age << " years old!" << endl;
	
	vector<int> myNums;
	
	for(int i = 1; i < 101; i++) myNums.push_back(i);
	
	for(auto num : myNums) async(std::launch::async,myPrint,num);
	
	return 0;
}
