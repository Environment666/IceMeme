#pragma once
//All in this file is from MemeHax by tepig
bool game_didGlobal = false;
bool workspace_didGlobal = false;
int arg_size = 1;
std::string typeshit;
int xx, yy, zz;

int Vector3_new(lua_State* L) {
	typeshit = "Vector3";
	xx = lua_tonumber(L, 1);
	yy = lua_tonumber(L, 2);
	zz = lua_tonumber(L, 3);
	return 0;
}

int Color3_new(lua_State* L) {
	typeshit = "Color3";
	xx = lua_tonumber(L, 1);
	yy = lua_tonumber(L, 2);
	zz = lua_tonumber(L, 3);
	return 0;
}

int GameIndex(lua_State* L) {
	if (game_didGlobal == false) {
		rlua_getglobal(luaState, "game");
		game_didGlobal = true;
	}
	lua_getglobal(L, "game");
	rlua_getfield(luaState, -1, lua_tostring(L, -2));
	return 1;
}

int GameNewIndex(lua_State* L) {
	game_didGlobal = true;
	lua_getglobal(L, "game");
	if (typeshit == "Vector3") {
		/*	MsgBox("Vector3", "getglobal");*/
		rlua_getglobal(luaState, "Vector3");
		/*MsgBox("new", "getfield -1");*/
		rlua_getfield(luaState, -1, "new");
		/*MsgBox(std::to_string(xx), "pushnumber");*/
		rlua_pushnumber(luaState, xx);
		/*MsgBox(std::to_string(yy), "pushnumber");*/
		rlua_pushnumber(luaState, yy);
		/*MsgBox(std::to_string(zz), "pushnumber");*/
		rlua_pushnumber(luaState, zz);
		/*MsgBox("3 1 0", "pcall");*/
		rlua_bpcall(luaState, 3, 1, 0);
		/*	MsgBox(lua_tostring(L, -3), "setfield -3");*/
		rlua_setfield(luaState, -3, lua_tostring(L, -3));
		xx, yy, zz = 0;
		typeshit = "";
	}
	else if (typeshit == "Color3") {
		/*	MsgBox("Color3", "getglobal");*/
		rlua_getglobal(luaState, "Color3");
		/*MsgBox("-1 new", "getfield");*/
		rlua_getfield(luaState, -1, "new");
		/*MsgBox(std::to_string(xx), "pushnumber");*/
		rlua_pushnumber(luaState, xx);
		/*MsgBox(std::to_string(yy), "pushnumber");*/
		rlua_pushnumber(luaState, yy);
		/*MsgBox(std::to_string(zz), "pushnumber");*/
		rlua_pushnumber(luaState, zz);
		/*MsgBox("3 1 0", "pcall");*/
		rlua_bpcall(luaState, 3, 1, 0);
		/*MsgBox(lua_tostring(L, -3), "setfield -3");*/
		rlua_setfield(luaState, -3, lua_tostring(L, -3));
		xx, yy, zz = 0;
		typeshit = "";
	}
	else {
		if (lua_isnumber(L, -2)) {
			rlua_pushnumber(luaState, lua_tonumber(L, -2));
			/*MsgBox(std::to_string(lua_tonumber(L, -2)), "pushnumber");*/
			rlua_setfield(luaState, -2, lua_tostring(L, -3));
			/*MsgBox(lua_tostring(L, -3), "setfield -2");*/
		}
		else if (lua_isboolean(L, -2)) {
			rlua_pushboolean(luaState, lua_toboolean(L, -2));
			/*MsgBox(std::to_string(lua_toboolean(L, -2)), "pushboolean");*/
			rlua_setfield(luaState, -2, lua_tostring(L, -3));
			/*MsgBox(lua_tostring(L, -3), "setfield -2");*/
		}
		else if (lua_isstring(L, -2)) {
			rlua_pushstring(luaState, lua_tostring(L, -2));
			/*	MsgBox(lua_tostring(L, -2), "pushstring");*/
			rlua_setfield(luaState, -2, lua_tostring(L, -3));
			/*MsgBox(lua_tostring(L, -3), "setfield -2");*/
		}
		else if (lua_istable(L, -2)) {

		}
		else if (lua_isnil(L, -2)) {
			rlua_pushnil(luaState);
			/*	MsgBox("nil", "pushnil");*/
			rlua_setfield(luaState, -2, lua_tostring(L, -3));
			/*MsgBox(lua_tostring(L, -3), "setfield -2");*/
		}
	}
	return 1;
}

int WorkspaceIndex(lua_State* L) {
	if (workspace_didGlobal == false) {
		/*MsgBox("game", "getglobal");*/
		rlua_getglobal(luaState, "workspace");
		workspace_didGlobal = true;
	}
	lua_getglobal(L, "workspace");
	/*MsgBox(lua_tostring(L, -2), "getfield -1");*/
	rlua_getfield(luaState, -1, lua_tostring(L, -2));
	return 1;
}

int WorkspaceNewIndex(lua_State* L) {
	workspace_didGlobal = false;
	lua_getglobal(L, "workspace");
	if (typeshit == "Vector3") {
		/*	MsgBox("Vector3", "getglobal");*/
		rlua_getglobal(luaState, "Vector3");
		/*MsgBox("new", "getfield -1");*/
		rlua_getfield(luaState, -1, "new");
		/*MsgBox(std::to_string(xx), "pushnumber");*/
		rlua_pushnumber(luaState, xx);
		/*MsgBox(std::to_string(yy), "pushnumber");*/
		rlua_pushnumber(luaState, yy);
		/*MsgBox(std::to_string(zz), "pushnumber");*/
		rlua_pushnumber(luaState, zz);
		/*MsgBox("3 1 0", "pcall");*/
		rlua_bpcall(luaState, 3, 1, 0);
		/*	MsgBox(lua_tostring(L, -3), "setfield -3");*/
		rlua_setfield(luaState, -3, lua_tostring(L, -3));
		xx, yy, zz = 0;
		typeshit = "";
	}
	else if (typeshit == "Color3.new") {
		/*	MsgBox("Color3", "getglobal");*/
		rlua_getglobal(luaState, "Color3");
		/*MsgBox("-1 new", "getfield");*/
		rlua_getfield(luaState, -1, "new");
		/*MsgBox(std::to_string(xx), "pushnumber");*/
		rlua_pushnumber(luaState, xx);
		/*MsgBox(std::to_string(yy), "pushnumber");*/
		rlua_pushnumber(luaState, yy);
		/*MsgBox(std::to_string(zz), "pushnumber");*/
		rlua_pushnumber(luaState, zz);
		/*MsgBox("3 1 0", "pcall");*/
		rlua_bpcall(luaState, 3, 1, 0);
		/*MsgBox(lua_tostring(L, -3), "setfield -3");*/
		rlua_setfield(luaState, -3, lua_tostring(L, -3));
		xx, yy, zz = 0;
		typeshit = "";
	}
	else {
		if (lua_isnumber(L, -2)) {
			rlua_pushnumber(luaState, lua_tonumber(L, -2));
			/*MsgBox(std::to_string(lua_tonumber(L, -2)), "pushnumber");*/
			rlua_setfield(luaState, -2, lua_tostring(L, -3));
			/*MsgBox(lua_tostring(L, -3), "setfield -2");*/
		}
		else if (lua_isboolean(L, -2)) {
			rlua_pushboolean(luaState, lua_toboolean(L, -2));
			/*MsgBox(std::to_string(lua_toboolean(L, -2)), "pushboolean");*/
			rlua_setfield(luaState, -2, lua_tostring(L, -3));
			/*MsgBox(lua_tostring(L, -3), "setfield -2");*/
		}
		else if (lua_isstring(L, -2)) {
			rlua_pushstring(luaState, lua_tostring(L, -2));
			/*	MsgBox(lua_tostring(L, -2), "pushstring");*/
			rlua_setfield(luaState, -2, lua_tostring(L, -3));
			/*MsgBox(lua_tostring(L, -3), "setfield -2");*/
		}
		else if (lua_isnil(L, -2)) {
			rlua_pushnil(luaState);
			/*	MsgBox("nil", "pushnil");*/
			rlua_setfield(luaState, -2, lua_tostring(L, -3));
			/*MsgBox(lua_tostring(L, -3), "setfield -2");*/
		}
	}
	return 1;
}

int GameCall(lua_State* L) {
	game_didGlobal = false;
	arg_size = 1;
	rlua_pushvalue(luaState, -2);
	/*MsgBox("-2", "pushvalue");*/
	int i = 2;
	while (!lua_isnil(L, -i)) {
		if (lua_isnumber(L, -i)) {
			rlua_pushnumber(luaState, lua_tonumber(L, -i));
			/*MsgBox(std::to_string(lua_tonumber(L, -i)), "pushnumber");*/
			arg_size++;
		}
		if (lua_isstring(L, -i)) {
			rlua_pushstring(luaState, lua_tostring(L, -i));
			/*MsgBox(lua_tostring(L, -i), "pushstring");*/
			arg_size++;
		}
		if (lua_isboolean(L, -i)) {
			rlua_pushboolean(luaState, lua_toboolean(L, -i));
			/*MsgBox(std::to_string(lua_toboolean(L, -i)), "pushboolean");*/
			arg_size++;
		}
		i++;
	}
	rlua_bpcall(luaState, arg_size, 1, 0);
	/*MsgBox(std::to_string(arg_size) + " 1 0", "pcall");*/
	arg_size = 1;
	return 1;
}

int WorkspaceCall(lua_State* L) {
	workspace_didGlobal = false;
	arg_size = 1;
	rlua_pushvalue(luaState, -2);
	/*MsgBox("-2", "pushvalue");*/
	int i = 2;
	while (!lua_isnil(L, -i)) {
		if (lua_isnumber(L, -i)) {
			rlua_pushnumber(luaState, lua_tonumber(L, -i));
			/*MsgBox(std::to_string(lua_tonumber(L, -i)), "pushnumber");*/
			arg_size++;
		}
		if (lua_isstring(L, -i)) {
			rlua_pushstring(luaState, lua_tostring(L, -i));
			/*MsgBox(lua_tostring(L, -i), "pushstring");*/
			arg_size++;
		}
		if (lua_isboolean(L, -i)) {
			rlua_pushboolean(luaState, lua_toboolean(L, -i));
			/*MsgBox(std::to_string(lua_toboolean(L, -i)), "pushboolean");*/
			arg_size++;
		}
		i++;
	}
	rlua_bpcall(luaState, arg_size, 1, 0);
	/*MsgBox(std::to_string(arg_size) + " 1 0", "pcall");*/
	arg_size = 1;
	return 1;
}

int Instance_new(lua_State* L) {
	game_didGlobal = false;
	workspace_didGlobal = false;
	int a = lua_gettop(L);
	/*MsgBox("Instance", "getglobal");*/
	rlua_getglobal(luaState, "Instance");
	/*MsgBox("new", "getfield -1");*/
	rlua_getfield(luaState, -1, "new");
	if (lua_isstring(L, 1)) {
		/*MsgBox(lua_tostring(L, 1), "pushstring");*/
		rlua_pushstring(luaState, lua_tostring(L, 1));
		if (a == 2) rlua_pushvalue(luaState, -4);/* MsgBox("-4", "pushvalue");*/
	}
	/*MsgBox(std::to_string(a) + " 1 0", "pcall");*/
	rlua_bpcall(luaState, a, 1, 0);
	return 1;
}

int LuaCAPI(lua_State* LuaS) {
	DWORD a = lua_gettop(LuaS);
	std::string cmd;
	for (int i = 1; i <= a; ++i) cmd = lua_tostring(LuaS, i);
	LuaCExe(cmd);
	return 0;
}

int PrintIdentity(lua_State* Lua51) {
	int arg = lua_gettop(Lua51);
	std::string print;
	for (int i = 1; i <= arg; ++i) {
		if (lua_isstring(Lua51, -(i))) {
			print = lua_tostring(Lua51, i);
			rlua_getglobal(luaState, "printidentity");
			rlua_pushstring(luaState, print.c_str());
			rlua_bpcall(luaState, 1, 0, 0);
			rlua_settop(luaState, 0);
		}
		else if (lua_isboolean(Lua51, -(i))) {
			print = lua_toboolean(Lua51, i);
			rlua_getglobal(luaState, "printidentity");
			rlua_pushstring(luaState, print.c_str());
			rlua_bpcall(luaState, 1, 0, 0);
			rlua_settop(luaState, 0);
		}
		else if (lua_isnil(Lua51, -(i))) {
			rlua_getglobal(luaState, "printidentity");
			rlua_pushnil(luaState);
			rlua_bpcall(luaState, 1, 0, 0);
			rlua_settop(luaState, 0);
		}
	}
	if (arg == 0) {
		rlua_getglobal(luaState, "printidentity");
		rlua_bpcall(luaState, 0, 0, 0);
		rlua_settop(luaState, 0);
	}
	return 0;
}

int Print(lua_State* L) {
	std::string message;

	int n = lua_gettop(L);  /* number of arguments */
	int i;

	lua_getglobal(L, "tostring");
	for (i = 1; i <= n; ++i) {
		if (i > 1)
		{
			message += ' ';
		}

		lua_pushvalue(L, -1);  /* function to be called */
		lua_pushvalue(L, i);   /* value to print */
		lua_call(L, 1, 1);
		const char* s = lua_tostring(L, -1);  /* get result */
		message += s;
		if (i > 1) fputs("\t", stdout);
		lua_pop(L, 1);  /* pop result */
	}
	rlua_getglobal(luaState, "print");
	rlua_pushstring(luaState, message.c_str());
	rlua_bpcall(luaState, n, 0, 0);
	return 0;
}

int Warn(lua_State* L) {
	std::string message;

	int n = lua_gettop(L);  /* number of arguments */
	int i;

	lua_getglobal(L, "tostring");
	for (i = 1; i <= n; ++i) {
		if (i > 1)
		{
			message += ' ';
		}

		lua_pushvalue(L, -1);  /* function to be called */
		lua_pushvalue(L, i);   /* value to print */
		lua_call(L, 1, 1);
		const char* s = lua_tostring(L, -1);  /* get result */
		message += s;
		if (i > 1) fputs("\t", stdout);
		lua_pop(L, 1);  /* pop result */
	}
	rlua_getglobal(luaState, "warn");
	rlua_pushstring(luaState, message.c_str());
	rlua_bpcall(luaState, n, 0, 0);
	return 0;
}
int Error(lua_State* L) {
	std::string message;

	int n = lua_gettop(L);  /* number of arguments */
	int i;

	lua_getglobal(L, "tostring");
	for (i = 1; i <= n; ++i) {
		if (i > 1)
		{
			message += ' ';
		}

		lua_pushvalue(L, -1);  /* function to be called */
		lua_pushvalue(L, i);   /* value to print */
		lua_call(L, 1, 1);
		const char* s = lua_tostring(L, -1);  /* get result */
		message += s;
		if (i > 1) fputs("\t", stdout);
		lua_pop(L, 1);  /* pop result */
	}
	rlua_getglobal(luaState, "error");
	rlua_pushstring(luaState, message.c_str());
	rlua_bpcall(luaState, n, 0, 0);
	return 0;
}
int Info(lua_State* L) {
	std::string message;

	int n = lua_gettop(L);  /* number of arguments */
	int i;

	lua_getglobal(L, "tostring");
	for (i = 1; i <= n; ++i) {
		if (i > 1)
		{
			message += ' ';
		}

		lua_pushvalue(L, -1);  /* function to be called */
		lua_pushvalue(L, i);   /* value to print */
		lua_call(L, 1, 1);
		const char* s = lua_tostring(L, -1);  /* get result */
		message += s;
		if (i > 1) fputs("\t", stdout);
		lua_pop(L, 1);  /* pop result */
	}
	rlua_getglobal(luaState, "info");
	rlua_pushstring(luaState, message.c_str());
	rlua_bpcall(luaState, n, 0, 0);
	return 0;
}


//YALL KNOW DAMN WELL WHERE THAT SHIT CAME FROM ^^

int Wait(lua_State* Lua51) {
	DWORD arg = lua_gettop(Lua51);
	float time;
	for (int i = 1; i <= arg; ++i) {
		time = lua_tonumber(Lua51, i);
	}
	Sleep(time * 1000);
	// DISGUSTING ^
	return 0;
}

int opencustomlibs(lua_State* L) {
	lua_newtable(L);
	lua_pushcfunction(L, Instance_new);
	lua_setfield(L, -2, "new");
	lua_setglobal(L, "Instance");
	lua_settop(L, 0);
	lua_newtable(L);
	lua_pushcfunction(L, Vector3_new);
	lua_setfield(L, -2, "new");
	lua_setglobal(L, "Vector3");
	lua_settop(L, 0);
	lua_getglobal(L, "Vector3");
	lua_pushvalue(L, -1);
	lua_setfield(L, -2, "__index");
	lua_settop(L, 0);
	lua_newtable(L);
	lua_pushcfunction(L, Color3_new);
	lua_setfield(L, -2, "new");
	lua_setglobal(L, "Color3");
	lua_settop(L, 0);
	lua_getglobal(L, "Color3");
	lua_pushvalue(L, -1);
	lua_setfield(L, -2, "__index");
	lua_settop(L, 0);
	lua_newtable(L);
	lua_pushstring(L, "deadass should already know that this is locked");
	lua_setfield(L, -2, "__metatable");
	lua_settop(L, 0);
	lua_newtable(L);
	lua_createtable(L, 0, 1);
	lua_pushcfunction(L, GameIndex);
	lua_setfield(L, -2, "__index");
	lua_pushcfunction(L, GameNewIndex);
	lua_setfield(L, -2, "__newindex");
	lua_pushcfunction(L, GameCall);
	lua_setfield(L, -2, "__call");
	lua_setmetatable(L, -2);
	lua_setglobal(L, "game");
	lua_settop(L, 0);
	lua_newtable(L);
	lua_createtable(L, 0, 1);
	lua_pushcfunction(L, WorkspaceIndex);
	lua_setfield(L, -2, "__index");
	lua_pushcfunction(L, WorkspaceNewIndex);
	lua_setfield(L, -2, "__newindex");
	lua_pushcfunction(L, WorkspaceCall);
	lua_setfield(L, -2, "__call");
	lua_setmetatable(L, -2);
	lua_setglobal(L, "workspace");
	lua_settop(L, 0);
	lua_pushcfunction(L, PrintIdentity);
	lua_setglobal(L, "printidentity");
	lua_settop(L, 0);
	lua_pushcfunction(L, Warn);
	lua_setglobal(L, "warn");
	lua_settop(L, 0);
	lua_pushcfunction(L, Print);
	lua_setglobal(L, "print");
	lua_settop(L, 0);
	lua_pushcfunction(L, Wait);
	lua_setglobal(L, "wait");
	lua_settop(L, 0);
	lua_pushcfunction(L, Error);
	lua_setglobal(L, "error");
	lua_pushcfunction(L, Error);
	lua_setglobal(L, "error");
	lua_settop(L, 0);
	lua_pushcfunction(L, LuaCAPI);
	lua_setglobal(L, "luac");
	lua_settop(L, 0);
	return 1;
}

void Exe(std::string input) {
	lua_State* luaS = luaL_newstate();
	lua_State* LuaS = lua_newthread(luaS);
	luaL_openlibs(LuaS);
	opencustomlibs(LuaS);
	std::string total;
	luaL_dostring(LuaS, input.c_str());
	lua_settop(LuaS, 0);
	lua_close(LuaS);
}