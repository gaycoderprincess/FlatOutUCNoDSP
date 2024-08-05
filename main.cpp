#include <windows.h>
#include "nya_commonhooklib.h"

BOOL WINAPI DllMain(HINSTANCE, DWORD fdwReason, LPVOID) {
	switch( fdwReason ) {
		case DLL_PROCESS_ATTACH: {
			if (NyaHookLib::GetEntryPoint() != 0x24CEF7) {
				MessageBoxA(nullptr, "Unsupported game version! Make sure you're using the Steam GFWL version (.exe size of 4242504 bytes)", "nya?!~", MB_ICONERROR);
				exit(0);
				return TRUE;
			}

			NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x41ADA4, 0x41AE35);
			NyaHookLib::Patch<uint8_t>(0x41EC78, 0xEB);
			NyaHookLib::Patch<uint8_t>(0x41AF78, 0xEB);
			NyaHookLib::Patch<uint8_t>(0x41ECF0, 0xC3);
			NyaHookLib::Patch<uint8_t>(0x419A20, 0xC3);
		} break;
		default:
			break;
	}
	return TRUE;
}