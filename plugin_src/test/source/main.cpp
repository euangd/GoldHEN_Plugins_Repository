#include <stdint.h>
#include <stdarg.h>

#include "defines.h"
#include "detour.h"
#include "functions.h"
#include "global.h"
#include "hooks.h"
#include "imports.h"
#include "utility.h"
#include "types.h"
#include "natives.h"
#include "addresses.h"

void DetectGame() {
	char userName[20];
	char welcomeMessage[100];
	sceUserServiceGetUserName(userId, userName, 20);
	snprintf(welcomeMessage, sizeof(welcomeMessage), "Welcome %s to GTA5 1.48 Base", userName);
	Notify(welcomeMessage);
	//sceKernelMprotect((void*)globalAddress, 0x1000, 0x7);
	sceKernelMprotect((void*)Address_PlayerIsOnline, 0x1000, 0x7);
	//memcpy((void*)Address_PlayerIsOnline, "\x55\x48\x89\xE5\x53\x50\x48\x89\xFB\xBF\x01\x00\x00\x00\xE8\xFD\x92\x92\x00", 19); // 1.00
	memcpy((void*)Address_PlayerIsOnline, "\x55\x48\x89\xE5\x53\x50\x48\x89\xFB\xBF\x01\x00\x00\x00\xE8\xDD\xD6\xB8\x00", 19); //1.48
	Hooks::IsPlayerOnline_s = (Hooks::IsPlayerOnline_t)DetourFunction(Address_PlayerIsOnline, (void*)Hooks::IsPlayerOnlineHook, 19);
}

extern "C" void _main(struct payload_args* args) {
	dlsym_t* dlsym = args->dlsym;
	processBaseAddress = args->processBaseAddress;
	initImports(dlsym);
	// initImports MUST be called before syscalls
	initSyscall();

	SceUserServiceLoginUserIdList userIdList;
	sceUserServiceGetLoginUserIdList(&userIdList);

	for (int i = 0; i < 4; i++) {
		if (userIdList.userId[i] != -1) {
			userId = userIdList.userId[i];
			break;
		}
	}

	userPadHandle = scePadGetHandle(userId, 0, 0);

	DetectGame();
}