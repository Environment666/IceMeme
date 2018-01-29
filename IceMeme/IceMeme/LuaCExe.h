#pragma once

std::vector<std::string> LuaCSplit(std::string s)
{
	std::vector<std::string> elems;
	std::stringstream ss(s);
	std::istream_iterator<std::string> begin(ss);
	std::istream_iterator<std::string> end;
	std::vector<std::string> vstrings(begin, end);
	return vstrings;
}

void LuaCExe(std::string input) {
	try {
		std::vector<std::string> In = LuaCSplit(input);

		if (In.at(0) == "getfield") {
			std::string field;
			for (size_t i = 2; i < In.size(); i++) {
				if (i < (In.size() - 1)) {
					field.append(In.at(i) + ' ');
				}
				if (i == (In.size() - 1)) {
					field.append(In.at(i));
				}
			}
			Rlua::rlua_getfield(luaState, stoi(In.at(1)), field.c_str());
		}

		else if (In.at(0) == "getglobal") {
			rlua_getglobal(luaState, In.at(1).c_str());
		}

		else if (In.at(0) == "setfield") {
			rlua_setfield(luaState, stoi(In.at(1)), In.at(2).c_str());
		}

		else if (In.at(0) == "pushvalue") {
			Rlua::rlua_pushvalue(luaState, stoi(In.at(1)));
		}

		else if (In.at(0) == "pushstring") {
			std::string string;
			for (size_t i = 1; i < In.size(); i++) {
				if (i < (In.size() - 1)) {
					string.append(In.at(i) + ' ');
				}
				if (i == (In.size() - 1)) {
					string.append(In.at(i));
				}
			}
			Rlua::rlua_pushstring(luaState, string.c_str());
		}

		else if (In.at(0) == "pushnumber") {
			Rlua::rlua_pushnumber(luaState, stoi(In.at(1)));
		}

		else if (In.at(0) == "pcall") {
			rlua_bpcall(luaState, stoi(In.at(1)), stoi(In.at(2)), stoi(In.at(3)));
		}

		else if (In.at(0) == "emptystack") {
			Rlua::rlua_settop(luaState, 0);
		}

		else if (In.at(0) == "settop") {
			Rlua::rlua_settop(luaState, stoi(In.at(1)));
		}

		else if (In.at(0) == "getservice") {
			rlua_getService(In.at(1).c_str());
		}

		else if (In.at(0) == "pushboolean") {
			if (In.at(1) == "false") {
				Rlua::rlua_pushboolean(luaState, false);
			}
			else if (In.at(1) == "true") {
				Rlua::rlua_pushboolean(luaState, true);
			}
		}

	}
	catch (...) {

	}
}