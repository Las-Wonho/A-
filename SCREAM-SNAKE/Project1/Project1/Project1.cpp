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

};





int main() {
	auto f = [](int x, int y)->int{return x +y+69; };
}