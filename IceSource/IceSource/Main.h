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

//Command pipe
DWORD WINAPI CmdPipe(PVOID lvpParameter)
{
	HANDLE hPipe;
	char buffer[1024];
	DWORD dwRead;
	hPipe = CreateNamedPipe(TEXT("\\\\.\\pipe\\IceCmd"),//IceCmd is the name of the command pipe
		PIPE_ACCESS_DUPLEX | PIPE_TYPE_BYTE | PIPE_READMODE_BYTE,
		PIPE_WAIT,
		1,
		1024 * 16,
		1024 * 16,
		NMPWAIT_USE_DEFAULT_WAIT,
		NULL);
	while (hPipe != INVALID_HANDLE_VALUE)
	{
		if (ConnectNamedPipe(hPipe, NULL) != FALSE)
		{
			while (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &dwRead, NULL) != FALSE)
			{
				buffer[dwRead] = '\0';
				try {
					Commands(buffer);
				}
				catch (std::exception e) {
					MessageBoxA(NULL, e.what(), " - Uh Oh", MB_OK);
				}
				catch (...) {
					MessageBoxA(NULL, "An Unhandled Error Has Occured!", "ICE - Uh Oh", MB_OK);
				}
			}
		}
		DisconnectNamedPipe(hPipe);
	}
}
//Lua C pipe
DWORD WINAPI LuaCPipe(PVOID lvpParameter)
{
	HANDLE hPipe;
	char buffer[1024];
	DWORD dwRead;
	hPipe = CreateNamedPipe(TEXT("\\\\.\\pipe\\IceLuaC"),//IceLuaC is the name of the lua c pipe
		PIPE_ACCESS_DUPLEX | PIPE_TYPE_BYTE | PIPE_READMODE_BYTE,
		PIPE_WAIT,
		1,
		1024 * 16,
		1024 * 16,
		NMPWAIT_USE_DEFAULT_WAIT,
		NULL);
	while (hPipe != INVALID_HANDLE_VALUE)
	{
		if (ConnectNamedPipe(hPipe, NULL) != FALSE)
		{
			while (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &dwRead, NULL) != FALSE)
			{
				buffer[dwRead] = '\0';
				try {
					LuaCExe(buffer);
				}
				catch (std::exception e) {
					MessageBoxA(NULL, e.what(), " - Uh Oh", MB_OK);
				}
				catch (...) {
					MessageBoxA(NULL, "An Unhandled Error Has Occured!", "ICE - Uh Oh", MB_OK);
				}
			}
		}
		DisconnectNamedPipe(hPipe);
	}
}

int Main() {
	CreateThread(NULL, 0, CmdPipe, NULL, 0, NULL);//Create new thread for command pipe
	CreateThread(NULL, 0, LuaCPipe, NULL, 0, NULL);//Create new thread for lua c pipe
	ScanScriptContext();
	MessageBox(NULL, "Ice has loaded Correctly!\nHey SKID! now you can use Ice!\nUpdated and improved by rakion99\nIce Skidded by Josh()", "ICE", MB_OK | MB_TOPMOST);//Messagebox so we can know when scan finished
	return 0;
}