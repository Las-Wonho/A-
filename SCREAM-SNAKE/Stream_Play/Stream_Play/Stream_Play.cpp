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
		//반복자를 설정합니다. 
		//함수형태로 만들어집니다. 
		//실제로 계산이 이루어지기 전까지는 계산이 되지 않습니다.
		void iterator(std::function<int(int)> f, int num) {
			iterator_ = f;
			iterator_start = num;
		};
		//얼마나 건너뛸건지 설정합니다. 
		//설정 시간은 계산이 끝난 시점일수도 있고 아닐 수도 있습니다.
		St count(int num) {
			count_num = num;
		}
		//얼마만큼 취할 것인지 정합니다. 설정하지 않으면 무한반복합니다.
		//설정시간은 계산이 끝난 시점일 수도, 아닐 수도 있습니다.
		St limit(int num) {
			limit_num = num;
		}
		//스트림에 있는 내용을 처리합니다.
		//foreach와 다른 점은 반환값이 있다는 것 입니다.
		//스트림의 내용을 변형시키는데 초점이 맞추어진 함수입니다.
		St map(std::function<int(int)> f) {
			map_ = f;
		}
		//f(acc, values) -> values
		//값을 꺼냅니다. 이 이후 스트림을 사용 할 수 없습니다.
		St reduce(std::function<int(int, int)> f, int acc) {

			acc = f(acc, 1);
		}

	private:
		vector<int>::iterator left;
		vector<int>::iterator right;
		function<int(int)> iterator_;
		int iterator_start;
		function<int(int)> map_;
		function<int(int)> reduce_;
		function<int(bool)> fillter;
		int count_num;
		int limit_num;
	};
};

int main() {
}