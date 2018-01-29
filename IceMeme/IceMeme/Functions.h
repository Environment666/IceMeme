#pragma once

#define IceMemebox(msg) MessageBox(NULL, msg, "ICEMEME - Uh Oh", MB_OK | MB_TOPMOST);

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
	Rlua::rlua_getfield(luaState, LUA_GLOBALSINDEX, "game");
	Rlua::rlua_getfield(luaState, -1, "GetService");
	Rlua::rlua_pushvalue(luaState, -2);
	Rlua::rlua_pushstring(luaState, service.c_str());
	rlua_bpcall(luaState, 2, 1, 0);
}

DWORD APIENTRY UglyToolBar()
{
	IceMemebox("ICEMEME has loaded Correctly!\nHey SKID! now you can use ICEMEME!\nUpdated and improved by rakion99\nIce Skidded by Josh(), MemeHax by tepig");
	HWND FindRobloxWindow = FindWindowExW(NULL, NULL, NULL, L"Roblox");
	HMENU GetUglyMenu = GetMenu(FindRobloxWindow);
	HMENU CreateUglyMenuBar = CreateMenu();
	InsertMenuW(CreateUglyMenuBar, NULL, MF_BYPOSITION | MF_STRING | MF_DISABLED, NULL, L"                             ICEMEME has loaded Correctly!           Hey SKID! now you can use ICEMEME!           Updated and improved by rakion99                 Ice Skidded by Josh(), MemeHax by tepig");
	SetMenu(FindRobloxWindow, CreateUglyMenuBar);
	SetWindowTextW(FindRobloxWindow, L"Roblox Exploited with ICEMEME");
	return 0;
}