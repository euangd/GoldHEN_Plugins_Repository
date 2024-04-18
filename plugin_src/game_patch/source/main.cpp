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
#define GOLDHEN_PATH_ (const char*) GOLDHEN_PATH
#define BASE_PATH_PATCH (const char*) GOLDHEN_PATH_ "/patches"
#define BASE_PATH_PATCH_SETTINGS (const char*) BASE_PATH_PATCH "/settings"
#define PLUGIN_NAME (const char*) "GoldenQueef"
#define PLUGIN_DESC (const char*) "BeefQueef Menu Base"
#define PLUGIN_AUTH (const char*) "rfoodxmodz"
#define PLUGIN_VER 0x148 // 1.48

#define NO_ASLR_ADDR 0x00400000

attr_public const char *g_pluginName = PLUGIN_NAME;
attr_public const char *g_pluginDesc = PLUGIN_DESC;
attr_public const char *g_pluginAuth = PLUGIN_AUTH;
attr_public u32 g_pluginVersion = PLUGIN_VER;

char titleid[16] = {0};
char game_elf[32] = {0};
char game_prx[MAX_PATH_] = {0};
char game_ver[8] = {0};

u64 module_base = 0;
u32 module_size = 0;
// unused for now
u64 PRX_module_base = 0;
u32 PRX_module_size = 0;
struct proc_info procInfo;
long APP_BASE = 0x400000;


// https://github.com/bucanero/apollo-ps4/blob/a530cae3c81639eedebac606c67322acd6fa8965/source/orbis_jbc.c#L62
int get_module_info(OrbisKernelModuleInfo moduleInfo, const char* name, uint64_t *base, uint32_t *size)
{
    OrbisKernelModule handles[256];
    size_t numModules;
    int ret = 0;
    ret = sceKernelGetModuleList(handles, sizeof(handles), &numModules);
    if (ret)
    {
        final_printf("sceKernelGetModuleList (0x%08x)\n", ret);
        return ret;
    }
    final_printf("numModules: %li\n", numModules);
    for (size_t i = 0; i < numModules; ++i)
    {
        ret = sceKernelGetModuleInfo(handles[i], &moduleInfo);
        final_printf("ret 0x%x\n", ret);
        final_printf("module %li\n", i);
        final_printf("name: %s\n", moduleInfo.name);
        final_printf("start: 0x%lx\n", (uint64_t)moduleInfo.segmentInfo[0].address);
        final_printf("size: %u (0x%x)\n", moduleInfo.segmentInfo[0].size, moduleInfo.segmentInfo[0].size);
        if (ret)
        {
            final_printf("sceKernelGetModuleInfo (%X)\n", ret);
            return ret;
        }

        if (strcmp(moduleInfo.name, name) == 0 || name[0] == '0')
        {
            if (base)
                *base = (uint64_t)moduleInfo.segmentInfo[0].address;

            if (size)
                *size = moduleInfo.segmentInfo[0].size;
            return 1;
        }
    }
    return 0;
}
void* my_thread(void* args) {
    /*u64  registerN_addr = (uint64_t)0x27B4AD0 + APP_BASE;
    memcpy_p((registerN_addr), "\x55\x48\x89\xE5\x41\x57\x41\x56\x41\x55\x41\x54\x53\x50\x49\x89\xD6", 17);
    Hooks::registerNative_Stub = (Hooks::registerNative_t)DetourFunction((registerN_addr), (void *)Hooks::registerNative_hook, 17);
	*/
	u64 isonline_addr = (uint64_t)0xBFB4B0 + APP_BASE;//0xBFB4B0 1.46
	WriteJump(isonline_addr, (uint64_t)Hooks::main_Hook);
    scePthreadExit(NULL);
    return NULL;
}
unsigned int CRC32(const char* str) {
	size_t textLen = strlen(str);
	//int i = 0;
	unsigned int retHash = 0;
	//
	for (int i = 0; i < textLen; i++)
	{
		if (str[0] == '"')
		i = 1;
		char ctext = str[i];
		if (ctext == '"')
		break;
		if (ctext - 65 > 25)
		{
			if (ctext == '\\')
			ctext = '/';
		}
		else ctext += 32;
		retHash = (1032 * (retHash + ctext) >> 8) ^ 1032 * (retHash + ctext);
	}
	return 32769 * (9 * retHash ^ (10 * retHash >> 11));
}
extern "C" {
s32 attr_module_hidden module_start(size_t argc, const void *args) {
    final_printf("[GoldHEN] <%s\\Ver.0x%08x> %s\n", g_pluginName, g_pluginVersion, __func__);
    final_printf("[GoldHEN] Plugin Author(s): %s\n", g_pluginAuth);
    boot_ver();
    struct proc_info procInfo;
    OrbisKernelModuleInfo CurrentModuleInfo;
    CurrentModuleInfo.size = sizeof(OrbisKernelModuleInfo);
    if(!get_module_info(CurrentModuleInfo, "0", &module_base, &module_size) && module_base && module_size)
    {
        final_printf("Could not find module info for current process\n");
        return -1;
    }
    if (sys_sdk_proc_info(&procInfo) == 0) {
    initImports();
    sceSysUtilSendSystemNotificationWithText(222, "[GTAV] - ArabicGuy Menu Base v1.0");
    print_proc_info();
    OrbisPthread thread;
    scePthreadCreate(&thread, NULL, my_thread, NULL, "my_thread");
    scePthreadJoin(thread, NULL);
    return 0;
    }
    NotifyStatic(TEX_ICON_SYSTEM, "Unable to get process info from " STRINGIFY(sys_sdk_proc_info));
    return -1;
}
}

extern "C" {
s32 attr_module_hidden module_stop(s64 argc, const void *args) {
    final_printf("[GoldHEN] <%s\\Ver.0x%08x> %s\n", g_pluginName, g_pluginVersion, __func__);
    return 0;
}
}