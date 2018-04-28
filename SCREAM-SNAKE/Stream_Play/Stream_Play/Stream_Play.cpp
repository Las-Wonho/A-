// Stream_Play.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<functional>
#include<vector>

using namespace std;

struct IntStream
{
	vector<int>::iterator left, right;
	vector<int> vector_;
	void set_easy(vector<int> v) {
		cout << &v;
		vector_ = v;
		left = vector_.begin();
		right = vector_.end();
	};
	void set(vector<int>::iterator l, vector<int>::iterator r) {
		left = l;
		right = r;
	};
	void f(function<int(int)> g) noexcept {
		for (auto i = left; i != right; ++i)
		{
			*i = g(*i);
		}
	};
	void print() noexcept {
		for (auto i = left; i+1 != right; ++i)
		{
			cout << *i << " ";
		}
	};
};

int main() {
	vector<int> v = { 1,2,3,4,5,6,7,8,9 };
	IntStream s;
	
	s.set_easy(v);
	s.f([](int x)->int {return x * 2; });
	s.print();

	s.set(v.begin(), v.end());
	s.print();
}