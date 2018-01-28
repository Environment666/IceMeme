#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib, "wininet")

#pragma once

#include "stdafx.h"
#include "Scanners.h"
#include "AddressandSSC.h"
#include "RobloxStuff.h"
#include "Functions.h"
#include "Commands.h"
#include "LuaCExe.h"
#include "Pipes.h"

int Main() {
	CreateThread(NULL, 0, CmdPipe, NULL, 0, NULL);//Create new thread for command pipe
	CreateThread(NULL, 0, LuaCPipe, NULL, 0, NULL);//Create new thread for lua c pipe
	ScanScriptContext();
	UglyToolBar();
	return 0;
}