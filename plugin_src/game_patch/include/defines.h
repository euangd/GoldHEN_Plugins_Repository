#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <Common.h>
#include "plugin_common.h"
#include "global.h"
#include "menu.h"

#define SOMETHING 1

extern bool init;
extern int frameCount;
extern Menu menu;

extern bool superJump;
extern bool explosiveAmmo;
extern bool explosiveMelee;

enum SomeEnum
{
	SOME_ENUM_MEMBER = 1
};

#ifdef __cplusplus
}
#endif
