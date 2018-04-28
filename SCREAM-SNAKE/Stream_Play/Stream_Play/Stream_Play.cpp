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
	void set(vector<int> v) {
		vector_ = v;
		left = vector_.begin();
		right = vector_.end();
	};
	//not used
	void set_iterator(vector<int>::iterator l, vector<int>::iterator r) {
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
		cout << *(--right) << endl;
	};
};

int main() {
	vector<int> v = { 1,2,3,4,5,6,7,8,9 };
	IntStream s;
	
	s.set(v);
	s.f([](int x)->int {return (x + 1 )* 2; });
	s.print();

}