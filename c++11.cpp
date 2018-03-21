#include <iostream>
#include <vector>
#include <random>
using namespace std;

int main()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.emplace_back(6);      //c++11에 추가된 기능
	
	for(auto iter : v)      //c++11에 추가된 기능
		cout<<"auto For문 : "<<iter<<endl;

	std::random_device rng; // c++11에 추가된 기능
	auto result = rng();
	cout<<"난수값 생성 : "<<result<<endl;


	//lamda표현   c++11에 추가된 기능
	auto sum = [](auto a, auto b)
	{
		return a+b;
	};

	cout<<"lamda Sum : "<<sum(3,4)<<endl;
}
