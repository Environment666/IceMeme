#pragma once

std::vector<std::string> Split(std::string str, char Delim) {
	std::vector<std::string> Args;
	std::stringstream ss(str);
	std::string Arg;
	while (getline(ss, Arg, Delim))
		Args.push_back(Arg);
	return Args;
}

std::string tolower(std::string str)
{
	std::string retn("");
	for (size_t i = 0; i < str.length(); i++)
	{
		int ascii = (int)str.at(i);
		if (ascii >= (int)'a' && ascii <= (int)'z')
			retn += (char)ascii;
		else
			retn += (char)(ascii + ((int)'a' - (int)'A'));
	}
	return retn;
}

void rlua_getService(std::string service)
{
	using namespace Rlua;
	rlua_getfield(luaState, LUA_GLOBALSINDEX, "game");
	rlua_getfield(luaState, -1, "GetService");
	rlua_pushvalue(luaState, -2);
	rlua_pushstring(luaState, service.c_str());
	rlua_call(luaState, 2, 1);
}

int *Changecontextlevel() {
	int *Level = Rlua::contextLevel();
	if (*Level == 0)
		*Level = 69;
	return Level;
}
