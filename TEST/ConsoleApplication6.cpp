// ConsoleApplication6.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
/*
내부가 아직 구현되지 않은 더미 클래스
*/
namespace Units {
	class Unit {
	public:
		Unit() {};
		Unit(short health_, short stemina_, short see_range_, std::pair<short, short> position) {
			health = health_;
			stemina = stemina_;
			see_range = see_range_;
			position_x = position.first;
			position_y = position.second;
		};
		[[nodiscard]]std::pair<short, short> getPosition() {
			return { position_x, position_y };
		};
		[[nodiscard]]std::tuple<short, short, short> getinfomations() {
			return { health, stemina, see_range };
		};
		[[nodiscard]]std::pair<short, short> move_to(std::pair<short, short> objective_tile) {
			auto[x, y] = objective_tile;
			std::cout << x << y << std::endl;

			return { x, y };
		};
	protected:
		void set_state(short state_) {
			state = state_;
		};
	private:

		short see_range;
		short health;
		short stemina;
		short position_x;
		short position_y;
		short state;
	};
	class Battle_Unit : Unit{
	public:
		Battle_Unit() {};
		Battle_Unit(short health_, short stemina_, short see_range_, std::pair<short, short> position) : Unit(health_,stemina_,see_range_,position){

		};
		[[noreturn]]void attack(Battle_Unit& enemy) {
			enemy.set_state(3);
			set_state(3);
		};
	private:

	};
}
int main() {

	Units::Unit A(1, 2, 3, {4, 5});
	Units::Unit B(45, 87, 64, {85,45});

	auto[a, b, c] = A.getinfomations();
	auto[d, e] = B.getPosition();

	std::cout << a << b << c << d << e<<std::endl;
	A.move_to({ 5,6 });

	Units::Battle_Unit C;
	Units::Battle_Unit D;

	C.attack(D);
	auto[a, b, c] = C.getinfomations();
	std::cout << a << b << c << std::endl;
	auto[a, b, c] = D.getinfomations();
	std::cout << a << b << c  << std::endl;
}