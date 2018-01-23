#pragma once
DWORD getfieldaddress = ASLR(0x733d00);
DWORD settopaddress = ASLR(0x735e40);
DWORD pushstringaddress = ASLR(0x7350b0);
DWORD pushvalueaddress = ASLR(0x735180);
DWORD calladdress = ASLR(0x733680);
DWORD setfieldaddress = ASLR(0x735a60);
DWORD pushnumberaddress = ASLR(0x735020);
DWORD contextleveladdress = ASLR(0x5a96e0);
DWORD ScriptContextVFTableaddress = ASLR(0x6bce6e);
DWORD getmetatableaddress = ASLR(0x733ff0);
DWORD pcalladdress = ASLR(0x734ae0);
DWORD rawrjzaddress = ASLR(0x72d3f7);
DWORD pushbooleanaddress = ASLR(0x734bb0);

int v41;//ScriptContext
int v49 = 1;
int luaState;

void ScanScriptContext() {
	DWORD ScriptContextVFTable = *(DWORD*)(ScriptContextVFTableaddress + 0x2);
	v41 = Memory::Scan((char*)&ScriptContextVFTable);
	//luaState
	luaState = *(DWORD *)(v41 + 56 * v49 + 164) - (v41 + 56 * v49 + 164);
}