// Stream_Play.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<iostream>
#include<xfunctional>
#include<functional>
#include"Stream.h"
#include<vector>
namespace Stream_la {
	using namespace std;
	class St {

	};
};

int main() {
	std::vector<int> v = { 7,8,9, 1, 2, 3, 4,5,6,10 };
	Stream::IntStream s;

	s.iterator([](auto x)->auto {return x + 1; }, 0, 5)
		.sum();
	
}