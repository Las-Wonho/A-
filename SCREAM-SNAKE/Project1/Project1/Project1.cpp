// Project1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<functional>
#include<vector>
#include<experimental\coroutine>

using namespace std;

template<typename f=function<int(void)>>
class IntStream {
public:
	IntStream(f func) {
		this->first_num = 1;
		this->func = func;
	};
	IntStream(int val) {
		this->value = val;
	};
	IntStream map(function<int(int)>f) {
		this->value = f(this->value);
	};
	IntStream filter(function<bool(int)>f) {

	};
	IntStream limit(int number) {

	};
	IntStream foreach(function<void(int)>f) {

	};
	IntStream reduce(function<int(int,int)>f) {
		
	};
	IntStream iterator(function<int(int)>) {

	};
	
	int do_it() {
		int num = this->first_num;
		num = func(num);
		return num;
	}
private:
	int value;
	int first_num;
	int function_num;
	f func;
};

template<typename T>
class Monad {
public:
	Monad() {
		this->none = true;
	};
	Monad(T val, bool is_none = false) {
		this->value = val;
		this->none = is_none;
	}; 
	Monad(bool is_none) {
		this->none = is_none;
	};
	T get_value() {
		if (none) {
			return 0;
		}
		return this -> value;
	};
	Monad<T> operator+(Monad<T> a) {
		if (this->none || a.none) {
			return Monad<T>(true);
		}
		return Monad<T>(this->value + a.get_value());
	};
	Monad<T> operator -(Monad<T> a) {
		if (this->none || a.none) {
			return Monad<T>(true);
		}
		return Monad(this->value - a.get_value());
	};
	Monad<T> operator/(Monad<T> a) {
		if (this->none || a.none) {
			return Monad<T>(true);
		}
		T val;
		try
		{
			val = this->value / a.get_value();
		}
		catch (...) {
			return Monad<T>(true);
		}
		return Monad<T>(val);
	};
	Monad unit(function<T(T,T)>f,Monad val) {

	};
	bool is_null() {
		return this->none;
	};

private:
	T value;
	bool none;
};
int main() {
	auto f = [](int x, int y)->int{return x +y+69; };
	Monad<int> m;
	m = 5;
	Monad<int> o;
	o = 0;
	
	cout << (m/o).is_null() << "wqe";
}