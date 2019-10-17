#define SOL_ALL_SAFETIES_ON 1
#include "sol.hpp"
#include <iostream>

struct player {
public:
	int bullets;
	int speed;

	player()
		: player(3, 100) {

	}

	player(int ammo)
		: player(ammo, 100) {

	}

	player(int ammo, int hitpoints)
		: bullets(ammo), hp(hitpoints) {

	}

	void boost() {
		speed += 10;
	}

	bool shoot() {
		if (bullets < 1)
			return false;
		--bullets;
		return true;
	}

	void set_hp(int value) {
		hp = value;
	}

	int get_hp() const {
		return hp;
	}

private:
	int hp;
};

using namespace std;

int main() {
	sol::state lua;

	lua.open_libraries(sol::lib::base);

	// note that you can set a 
	// userdata before you register a usertype,
	// and it will still carry 
	// the right metatable if you register it later

	// set a variable "p2" of type "player" with 0 ammo
	lua["p2"] = player(0);

	// make usertype metatable
	sol::usertype<player> player_type = lua.new_usertype<player>("player",
		// 3 constructors
		sol::constructors<player(), player(int), player(int, int)>());

	// typical member function that returns a variable
	player_type["shoot"] = &player::shoot;
	// typical member function
	player_type["boost"] = &player::boost;

	// gets or set the value using member variable syntax
	player_type["hp"] = sol::property(&player::get_hp, &player::set_hp);

	// read and write variable
	player_type["speed"] = &player::speed;
	// can only read from, not write to
	// .set(foo, bar) is the same as [foo] = bar;
	player_type.set("bullets", sol::readonly(&player::bullets));

	lua.script_file("C:/Users/Liam Tyler/Documents/LuaSolRepro/player.lua");

	return 0;
}