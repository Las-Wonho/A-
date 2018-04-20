// Project1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<functional>
#include<vector>

using namespace std;

struct gen
{
	template<typename T>
	T add(T a, T b) {
		return a + b;
	};
};


template<typename f=function<int(void)>>
class IntStream {
public:
	IntStream(f func) {
		this->first_num = 1;
		this->func = func;
	};

	IntStream map(function<int(int)>) {

	};
	IntStream filter(function<bool(int)>) {
	};
	IntStream limit(int number) {

	};
	IntStream foreach(function<void(int)>) {

	};
	IntStream reduce(function<int(int,int)>) {

	};
	IntStream iterator(function<int(int)>) {
	};
	
	int do_it() {
		int num = this->first_num;
		num = func(num);
		return num;
	}
private:
	int first_num;
	int function_num;
	f func;
	PipeLine pipe;
};

template<typename T>
class Monad {
public:
	Monad() {
	}; 
	Monad(T val) {
		this->value = val;
	};
	T get_value() {
		return this - value;
	};
	T cal() {

	};
	Monad operator+(Monad arg) {
		T tmp = this->value + arg.get_value();
		return Monad(tmp);
	}

private:
	T value;
};
int main() {
	auto f = [](int x)->int{return x + 5; };
	IntStream<function<int(int)>> a(f);
	int n = a.do_it();
	cout << n << "wqe";
}