#pragma once
DWORD getfieldaddress = ASLR(0x71d190);
DWORD settopaddress = ASLR(0x71f2a0);
DWORD pushstringaddress = ASLR(0x71e510);
DWORD pushvalueaddress = ASLR(0x71e5d0);
DWORD calladdress = ASLR(0x71caf0);
DWORD setfieldaddress = ASLR(0x71eec0);
DWORD pushnumberaddress = ASLR(0x71e480);
DWORD ScriptContextVFTableaddress = ASLR(0x69fd3e);
DWORD getmetatableaddress = ASLR(0x71d460);
DWORD pcalladdress = ASLR(0x71df50);
DWORD rawrjzaddress = ASLR(0x7167a7);
DWORD pushbooleanaddress = ASLR(0x71e020);
DWORD Identityflagaddress = ASLR(0x1585DFC);

int v41;//ScriptContext
int v49 = 1;
int luaState;

void ScanScriptContext() {
	DWORD ScriptContextVFTable = *(DWORD*)(ScriptContextVFTableaddress + 0x2);
	v41 = Memory::Scan((char*)&ScriptContextVFTable);
	//luaState
	luaState = v41 + 56 * v49 + 164 - *(DWORD *)(v41 + 56 * v49 + 164);
	*(DWORD*)Identityflagaddress = 6;
}