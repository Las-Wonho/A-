// Project1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<functional>
#include<vector>
#include<experimental\coroutine>

using namespace std;


struct intS
{
	vector<int>::iterator left;
	vector<int>::iterator right;
	intS makeStream(vector<int>::iterator l, vector<int>::iterator r) {
		return intS{l,r};
	};
	void print() noexcept {
		for (auto i = left; i != right; ++i)
		{
			cout << *i << ",";
		}
	};
};





int main() {
	auto f = [](int x, int y)->int{return x +y+69; };
	vector<int> v = {1,2,3,4,5,6,7,8,95,21};
	intS s;
	s.left = v.begin();
	s.right = v.end();
	s.print();
}