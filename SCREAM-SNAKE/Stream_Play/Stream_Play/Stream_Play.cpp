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
	void set(vector<int> v) {
		left = v.begin();
		right = v.end();
	};
	void f(function<int(int)> g) {
		for (; left != right; left++)
		{
			*left = g(*left);
		}
	};
	void print() {
		for (; left != right; left++)
		{
			cout << *left << " ";
		}
	};
};

int main() {
	vector<int> v = { 1,2,3,4,5,6,7,8,9 };
	IntStream s;
	s.set(v);
	s.print();
}