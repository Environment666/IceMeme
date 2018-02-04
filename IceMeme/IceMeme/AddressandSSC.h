#pragma once
DWORD getfieldaddress = ASLR(0x7219B0);
DWORD settopaddress = ASLR(0x723AD0);
DWORD pushstringaddress = ASLR(0x722D50);
DWORD pushvalueaddress = ASLR(0x722E10);
DWORD setfieldaddress = ASLR(0x7236F0);
DWORD pushnumberaddress = ASLR(0x722CC0);
DWORD ScriptContextVFTableaddress = ASLR(0x69EE5E);
DWORD getmetatableaddress = ASLR(0x721CA0);
DWORD pcalladdress = ASLR(0x722790);
DWORD rawrjzaddress = ASLR(0x71B007);
DWORD pushbooleanaddress = ASLR(0x722860);
DWORD Identityaddress = ASLR(0x1585DFC); //IM NOT BOTHERING TO UPDATE THIS, DO IT URSELF
DWORD pushniladdress = ASLR(0x71A730);

int v41;//ScriptContext
int v49 = 1;
int luaState;

void ScanScriptContext() {
	DWORD ScriptContextVFTable = *(DWORD*)(ScriptContextVFTableaddress + 0x2);
	v41 = Memory::Scan((char*)&ScriptContextVFTable);
	//luaState
	luaState = v41 + 56 * v49 + 220 + *(DWORD *)(v41 + 56 * v49 + 220);
	//*(DWORD*)Identityaddress = 6; < commented cause address isnt updated
}
