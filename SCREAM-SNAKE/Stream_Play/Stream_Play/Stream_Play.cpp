// Stream_Play.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<iostream>
#include<xfunctional>
#include<functional>
#include<vector>

using namespace std;

class wrap{
public:
	int value;
	wrap operator=(int a) {
		value = a;
	};

	bool operator==(int a) {
		return a == value;
	};
	int operator+(wrap a) {
		return value + a.value;
	}
	int operator-(wrap a) {
		return value - a.value;
	}
	int operator*(wrap a) {
		return value * a.value;
	}
	int operator/(wrap a) {
		if (a.value == 0 || value == 0)
			return 0;
		return value / a.value;
	}

	int operator+(int a) {
		return value + a;
	}
	int operator-(int a) {
		return value - a;
	}
	int operator*(int a) {
		return value * a;
	}
	int operator/(int a) {
		if (a == 0 || value == 0)
			return 0;
		return value / a;
	}

	wrap(int a) {
		this->value = a;
	}
};


struct IntStream
{
	vector<int>::iterator left, right;
	vector<int> vector_;
	[[noreturn]]
	void set(vector<int> v) {
		vector_ = v;
		left = vector_.begin();
		right = vector_.end();
	};
	[[deprecated, noreturn]]
	void set_iterator(vector<int>::iterator left_, vector<int>::iterator right_) {
		left = left_;
		right = right_;
	};
	[[noreturn]]
	void function(function<int(int)> f) noexcept {
		for (auto i = left; i != right; ++i)
		{
			*i = f(*i);
		}
	};
	[[noreturn]]
	void print() noexcept {
		for (auto i = left; i+1 != right; ++i)
		{
			cout << *i << ", ";
		}
		cout << *(right-1) << endl;
	};
	[[nodiscard]]
	int sum() noexcept {
		int acc=0;
		for (auto i = left; i != right; ++i)
		{
			acc+=*i;
		}
		return acc;
	};
	//병렬
	[[deprecated, nodiscard]]
	int sum_range(vector<int>::iterator l, vector<int>::iterator r) noexcept {
		int acc = 0;
		for (auto i = l; i != r; ++i)
		{
			acc += *i;
		}
		return acc;
	};
	[[nodiscard]]
	int reduce(std::function<int(int,int)> f) {
		for (auto i = left; i+1 != right; ++i)
		{
			*(i+1)=f(*(i), *(i+1));
		}
		return *(right - 1);
	};
	[[nodiscard]]
	IntStream iterator(std::function<int(int)> f, int initialize, int num) {
		std::vector<int> vec = vector<int>();
		for (size_t i = 0; i < num; i++)
		{
			vec.push_back(initialize);
			initialize = f(initialize);
		}
		IntStream s;
		s.set(vec);
		return s;
	};
	[[deprecated, nodiscard]]
	IntStream map(std::function<int(wrap)> f) noexcept {
		for (auto i = left; i != right; ++i)
		{
			wrap a = *i;

			*i = f(a);
			return *this;
		};
	}; 
	[[nodiscard]]
	IntStream map_(int (*las)(int v)) noexcept {
		for (auto i = left; i != right; ++i)
		{
			wrap a = *i;

			*i = las(a);
			return *this;
		};
	};
};

int main() {
	vector<int> v = { 7,8,9, 1, 2, 3, 4,5,6,10 };
	IntStream s;
	int result = s.iterator([](int x)->int {return x + 1; }, 1 , 5)
		.map_([](auto t)->auto { return t+2; })
		.reduce([](int x, int y)->int { return x + y; });
	cout << result;
	s.print();
}