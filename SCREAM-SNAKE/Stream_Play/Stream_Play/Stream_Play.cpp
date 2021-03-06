// Stream_Play.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<iostream>
#include<functional>
#include"Stream.h"
#include<vector>
namespace Stream_la {
	using namespace std;
	class St {
	public:
		[[noreturn]]void set(vector<int> v) {
			left = v.begin();
			right = v.end();
		};
		void iterator(std::function<int(int)> f) {
			iterator_ = f;
		};
	private:
		vector<int>::iterator left;
		vector<int>::iterator right;
		function<int(int)> iterator_;
		function<int(int)> map_;
		function<int(int)> reduce_;
		function<int(bool)> fillter;
	};
};

int main() {
}