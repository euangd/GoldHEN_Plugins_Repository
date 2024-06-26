#pragma once

#include <Common.h>
#include "plugin_common.h"
#include "types.h"

#define HOOK_LENGTH 14

void PatchInJump(uint64_t address, void *destination);
void *DetourFunction(uint64_t address, void *destination, int length);