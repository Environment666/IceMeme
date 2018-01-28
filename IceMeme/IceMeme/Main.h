#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib, "wininet")

#pragma once

#include "stdafx.h"
#include "lua.hpp"
#include "Scanners.h"
#include "AddressandSSC.h"
#include "RobloxStuff.h"
#include "Functions.h"
#include "Commands.h"
#include "LuaCExe.h"
#include "Meme.h"
#include "Pipes.h"

int Main() {
	CreateThread(NULL, 0, CmdPipe, NULL, 0, NULL);
	CreateThread(NULL, 0, LuaCPipe, NULL, 0, NULL);
	CreateThread(NULL, 0, LuaPipe, NULL, 0, NULL);
	ScanScriptContext();
	UglyToolBar();
	return 0;
}