#include "hooks.h"
#include "imports.h"
#include "utility.h"
#include "invoker.h"
#include "crossmaping.h"
#include "natives.h"
#include "vars.h"
#include "enums.h"
#include "utils.h"
#include "drawing.h"
#include "functions.h"

namespace Hooks {

registerNative_t registerNative_Stub;
//fcxLoader_t fcxLoader_Stub;
contentIsExist_t contentIsExist_Stub;
omtLoader_t omtLoader_Stub;
xml_omt_Loader_t xml_omt_Loader_Stub;
main_t main_Stub;
DataFunc_t DataFunc_Stub;
xmlLoader_t xmlLoader_Stub;
uint64_t v_gameDir;
int64_t SUB_19E03E0_ADDR;
int64_t SUB_19E0200_ADDR;
char nr_buffer[255];
bool natives_init;
#define PROT_READ 0x1
#define PROT_WRITE 0x2
#define PROT_EXEC 0x4
#define MAP_ANONYMOUS 0x20
#define MAP_PRIVATE 0x02
#define MAP_FIXED 0x10

uint64_t registerNative_hook(int64_t pointer, uint64_t nativeCrossmap, int64_t nativeFuncAddr) {
if(!natives_init) {
	nativesTableAddr = (void*)0x270000000;
	//sprintf(nr_buffer, "nativesTableAddr: %p", nativesTableAddr);
	// sceSysUtilSendSystemNotificationWithText(222, nr_buffer);
	natives_init = 1;
	}
	twoQwords *p2q;
	 //for(int i = 0; i < 36; i++) {
	 p2q = reinterpret_cast<twoQwords*>(__HASHMAPDATA);
	 while(p2q->p0) {
	  if(p2q->p1 == nativeCrossmap) { //crossmap comparation
	 // sprintf(buffer2, "NativeFunction: 0x%llx", p2q->p1);
	  
	
	
	*(uint64_t*)((uint64_t)nativesTableAddr + v_nt_counter) = p2q->p0;
	*(uint32_t*)(((uint64_t)nativesTableAddr + v_nt_counter + 0xC)) = nativeFuncAddr;
	v_nt_counter += 0x10;
	break;
	}
	p2q++;
	}
	return registerNative_Stub(pointer, nativeCrossmap, nativeFuncAddr);
}


void DrawSprite(const char* Streamedtexture, const char* textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a) {
	if (!HAS_STREAMED_TEXTURE_DICT_LOADED(Streamedtexture)) {
		REQUEST_STREAMED_TEXTURE_DICT(Streamedtexture, 0);
	}
	else {
		DRAW_SPRITE(Streamedtexture, textureName, x, y, width, height, rotation, r, g, b, a);
	}
}


void DRAW_TEXT_OPTION(char * text, int Font, float x, float y, float scalex, float scaley, int a, bool center, bool UseEdge, int RD, int GD, int BD) {
	SET_TEXT_FONT(Font);
	if(SelectedItem) {
		SET_TEXT_SCALE(0.45, 0.45);
		SET_TEXT_COLOUR(SelClrR, SelClrG, SelClrB, 255);
	}
    else {
		SET_TEXT_SCALE(scalex, scaley);
		SET_TEXT_COLOUR(255, 255, 255, 255);
	}
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_JUSTIFICATION(!center);
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y, 0);
	//const char* str = CREATE_STRING(10, "LITERAL_STRING", text);
	//#if GAME_VERSION != 129
	//DRAW_TEXT(str, x, y);
	//#else
	//_BG_DISPLAY_TEXT(str, x, y);
	//#endif
}
void DRAW_TEXT(const char * text, int Font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, bool center, bool UseEdge , int RD, int GD, int BD) {
	SET_TEXT_FONT(Font);
	SET_TEXT_SCALE(scalex, scaley);
	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_JUSTIFICATION(!center);
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y, 0);
	//const char* str = CREATE_STRING(10, "LITERAL_STRING", text);
	//#if GAME_VERSION != 129
	//DRAW_TEXT(str, x, y);
	//#else
	//_BG_DISPLAY_TEXT(str, x, y);
	//#endif
	}
void DRAW_TEXT2(char * text, int Font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, bool center) {
	SET_TEXT_FONT(Font);
	SET_TEXT_SCALE(scalex, scaley);
	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_JUSTIFICATION(!center);
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y, 0);
	//const char* str = CREATE_STRING(10, "LITERAL_STRING", text);
	//#if GAME_VERSION != 129
	//DRAW_TEXT(str, x, y);
	//#else
	//_BG_DISPLAY_TEXT(str, x, y);
	//#endif
}
void drawFloat(float Val, bool center, float x, float y, float scalex, float scaley, int r, int b, int g, int a) {
	char buf[255];
	SET_TEXT_FONT(0);
	SET_TEXT_SCALE(scalex, scaley);
	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_JUSTIFICATION(!center);
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("NUMBER");
	ADD_TEXT_COMPONENT_FLOAT(Val, 2);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y, 0);
	//snprintf(buf, sizeof(buf), "%.2f", Val);
	//const char* str = CREATE_STRING(10, "LITERAL_STRING", buf);
	//#if GAME_VERSION != 129
	//DRAW_TEXT(str, x, y);
	//#else
	//_BG_DISPLAY_TEXT(str, x, y);
	//#endif
}
void drawNumber(int Val, int font,  float x, float y, float scalex, float scaley, int r, int b, int g, int a, int center) {
	char buf[255];
	SET_TEXT_FONT(font);
	SET_TEXT_SCALE(scalex, scaley);
	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_JUSTIFICATION(!center);
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("NUMBER");
	ADD_TEXT_COMPONENT_INTEGER(Val);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y, 0);
	//snprintf(buf, sizeof(buf), "%i", Val);
	//const char* str = CREATE_STRING(10, "LITERAL_STRING", buf);
	//#if GAME_VERSION != 129
	//DRAW_TEXT(str, x, y);
	//#else
	//_BG_DISPLAY_TEXT(str, x, y);
	//#endif
}
void drawTextCounter(char* text, int Font, float x, float y, float scalex, float scaley, int r, int b, int g, int a) {
	SET_TEXT_FONT(Font);
	SET_TEXT_SCALE(scalex, scaley);
	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_JUSTIFICATION(0);
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y, 0);
	//const char* str = CREATE_STRING(10, "LITERAL_STRING", text);
	//#if GAME_VERSION != 129
	//DRAW_TEXT(str, x, y);
	//#else
	//_BG_DISPLAY_TEXT(str, x, y);
	//#endif
}

void ChangeMenu(int Menu) {
	lastNumMenu[NumMenuLevel] = NumMenu;
	lastOption[NumMenuLevel] = currentOption;
	currentOption = 1;
	NumMenu = Menu;
	NumMenuLevel++;
}
int GET() {
	if (PressX) {
		return currentOption;
		PressX = false;
	}
	else return 0;
}
void resetVars() {
	PressX = false;
	rightPress = false;
	leftPress = false;
}
void drawScroller() {
	if (optionCount > maxOptions) {
		if (currentOption > maxOptions) {
			DRAW_RECT(0.8900, ((maxOptions *  0.030f) + 0.1410f), 0.0050, 0.0285, SRL_R, SRL_G, SRL_B, 189);
		}
		else {
			DRAW_RECT(0.8900, ((currentOption *  0.030f) + 0.1410f), 0.0050, 0.0285, SRL_R, SRL_G, SRL_B, 189);
		}
	}
	else {
		DRAW_RECT(0.8900, ((currentOption *  0.030f) + 0.1410f), 0.0050, 0.0285, SRL_R, SRL_G, SRL_B, 189);
	}
}
void AddTitle(char* Text, int fontId = 1) {
	DRAW_TEXT2(Text, fontId, Title_X, 0.0840, 0.9000, 0.9000, TITLE_R, TITLE_G , TITLE_B , 255, false);
}
void AddOption(char *option, bool Normal, int color, char* Infox = NULL) {
	optionCount++;
	if (currentOption == optionCount)
	InfoText = Infox;
	SelectedItem = false;
	if (optionCount == currentOption) {
		SelectedItem = true;
	}
	if(Normal) {
		if (currentOption <= maxOptions && optionCount <= maxOptions) {
			if(color == 0) {
				DRAW_RECT(Menu_X, (optionCount * 0.030f + 0.1410f), CenterDraw, 0.0285, BKG_R, BKG_G, BKG_B, 189);
			}
			if(color == 1) {
				DRAW_RECT(Menu_X, (optionCount * 0.030f + 0.1410f), CenterDraw, 0.0285, 0, 0, 0, 150);
			}
			DRAW_TEXT_OPTION(option, OptionsFont, Cunt - 0.015 , (optionCount * 0.030f + 0.127f), 0.35000000, 0.35000000, 255, false, false, 0, 0, 0);
		}
		else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption) {
			if(color == 0) {
				DRAW_RECT(Menu_X, ((optionCount - (currentOption - maxOptions)) * 0.030f + 0.1410f), CenterDraw, 0.0285, BKG_R, BKG_G, BKG_B, 189);
			}
			if(color == 1) {
				DRAW_RECT(Menu_X,  ((optionCount - (currentOption - maxOptions)) * 0.030f + 0.1410f), CenterDraw, 0.0285,0, 0, 0, 150);
			}
			DRAW_TEXT_OPTION(option, OptionsFont, Cunt - 0.015, ((optionCount - (currentOption - maxOptions)) * 0.030f + 0.127f), 0.35000000, 0.35000000, 255, false, false, 0, 0, 0);
		}
	}
	else {
		if (currentOption <= maxOptions && optionCount <= maxOptions) {
			if(color == 0) {
				DRAW_RECT(Menu_X, (optionCount * 0.030f + 0.1410f), CenterDraw, 0.0285, BKG_R, BKG_G, BKG_B, 189);
			}
			if(color == 1) {
				DRAW_RECT(Menu_X, (optionCount * 0.030f + 0.1410f), CenterDraw, 0.0285, 0, 0, 0, 150);
			}
			DRAW_TEXT_OPTION(option, OptionsFont, Cunt, (optionCount * 0.030f + 0.127f), 0.35000000, 0.35000000, 255, false, false, 0, 0, 0);
		}
		else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption) {
			if(color == 0) {
				DRAW_RECT(Menu_X, ((optionCount - (currentOption - maxOptions)) * 0.030f + 0.1410f), CenterDraw, 0.0285, BKG_R, BKG_G, BKG_B, 189);
			}
			if(color == 1) {
				DRAW_RECT(Menu_X, ((optionCount - (currentOption - maxOptions)) * 0.030f + 0.1410f), CenterDraw, 0.0285, 0, 0, 0, 150);
			}
			DRAW_TEXT_OPTION(option, OptionsFont, Cunt, ((optionCount - (currentOption - maxOptions)) * 0.030f + 0.127f), 0.35000000, 0.35000000, 255, false, false, 0, 0, 0);
		}
	}
}
void addOption(char* option, int color, char* Infox) {
	AddOption(option, false, color, Infox);
}
void CheckBox(char* text, bool toggle, int color, char* Infox = NULL) {
	char buf[255];
	AddOption(text, false, color, Infox);
	int optionIndex = 0;
	if (currentOption <= maxOptions && optionCount <= maxOptions) {
		DrawSprite("menu_textures", "SELECTION_BOX_SQUARE", 0.8700, ((optionCount) * 0.030f + 0.1413f), 0.0150, 0.0250, 0, 255, 255, 255, 255);
	}
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption) {
		DrawSprite("menu_textures", "SELECTION_BOX_SQUARE", 0.8700, ((optionCount - (currentOption - maxOptions)) * 0.030f + 0.1413f), 0.0150, 0.0250, 0, 255, 255, 255, 255);
	}
	if (toggle) {
		int optionIndex = 0;
		if (currentOption <= maxOptions && optionCount <= maxOptions) {
			DrawSprite("generic_textures", "TICK", 0.8700, ((optionCount) * 0.030f + 0.1413f), 0.0150, 0.0250, 0, 129, 45, 45, 255);
		}
		else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption) {
			DrawSprite("generic_textures", "TICK", 0.8700, ((optionCount - (currentOption - maxOptions)) * 0.030f + 0.1413f), 0.0150, 0.0250, 0, 129, 45, 45, 255);
		}
	}
}
void IntOption(char *option, int *var, int min, int max, bool fast, int color, char* Infox) {
	AddOption(option, false, color, Infox);
	if (currentOption <= maxOptions && optionCount <= maxOptions) {
		drawNumber(*var, 0, 0.868, (optionCount * 0.030f + 0.126f), 0.36f, 0.36f, 255, 255, 255, 255, 1);
	}
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption) {
		drawNumber(*var, 0, 0.868, (maxOptions * 0.030f + 0.126f), 0.36f, 0.36f, 255, 255, 255, 255, 1);
	}
	if (currentOption == optionCount) {
		if(fast == false) {
			if (rightPress == true) {
				if (*var >= max) {
					*var = min;
				}
				else {
					*var = *var + 1;
				}
				rightPress = false;
			}
			else if (leftPress == true) {
				if (*var <= min) {
					*var = max;
				}
				else {
					*var = *var - 1;
				}
				leftPress = false;
			}
		}
	}
}
void FloatOption(char *option, float *var, float min, float max, float Default, int color, char* Infox ) {
	AddOption(option, false, color, Infox);
	if (currentOption <= maxOptions && optionCount <= maxOptions) {
	drawFloat(*var, true, 0.858, (optionCount  * 0.030f + 0.1250f), 0.36f, 0.36f, 255, 255, 255, 255);	}
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption) {
		drawFloat(*var, true, 0.858, (maxOptions  * 0.030f + 0.1250f), 0.36f, 0.36f, 255, 255, 255, 255);
	}
	if (currentOption == optionCount) {
		if (rightPress == true) {
			if (*var >= max) {
				*var = min;
			}
			else {
				*var = *var + 0.01f;
			}
			rightPress = false;
		}
		else if (leftPress == true) {
			if (*var <= min) {
				*var = max;
			}
			else {
				*var = *var - 0.01f;
			}
			leftPress = false;
		}
		else if(IS_CONTROL_JUST_PRESSED(0, FrontendX)) {
			*var = Default;
		}
	}
}
void TextOption(char *option, char* Text, int *Num, int min, int max, bool SmallFont, bool withoutSPRITE, int color, char* Info) {
	AddOption(option, withoutSPRITE, color, Info);
	if (currentOption <= maxOptions && optionCount <= maxOptions) {
		if (SmallFont == false) {
			DRAW_TEXT(Text, 0, 0.857, (optionCount * 0.030f + 0.127f), 0.35000000f, 0.35000000f, 255, 255, 255, 255, true, false, 0, 0, 0);
		}
		else {
			DRAW_TEXT(Text, 0, 0.820, (optionCount * 0.030f + 0.127f), 0.26000000f, 0.26000000f, 255, 255, 255, 255, 1, false, 0, 0, 0);
		}
	}
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption) {
		if (SmallFont == true) {
			DRAW_TEXT(Text, 0, 0.857, ((optionCount - (currentOption - maxOptions)) * 0.030f + 0.127f), 0.35000000f, 0.35000000f, 255, 255, 255, 255, false, false, 0, 0, 0);
		}
		else {
			DRAW_TEXT(Text, 0, 0.820, ((optionCount - (currentOption - maxOptions)) * 0.030f + 0.127f), 0.26000000f, 0.26000000f, 255, 255, 255, 255, 1, false, 0, 0, 0);
		}
	}
	if (currentOption == optionCount) {
		if (rightPress == true) {
			if (*Num >= max) {
				*Num = min;
			}
			else {
				*Num = *Num + 1;
			}
			rightPress = false;
		}
		else if (leftPress == true) { 
			if (*Num <= min) {
				*Num = max;
			}
			else {
				*Num = *Num - 1;
			}
			leftPress = false;
		}
	}
}
bool check_button(int buttonID, bool checkSpeed) {
	bool isPressed = false;
	if (IS_DISABLED_CONTROL_JUST_PRESSED(0, buttonID))
	return true;
	if (checkSpeed) {
		if(IS_DISABLED_CONTROL_PRESSED(0, buttonID)) {
			timerScrollSpeed++;
			if (timerScrollSpeed > 7) {
				timerScrollSpeed = 6;
				isPressed = true;
			}
		}
		if (IS_DISABLED_CONTROL_JUST_RELEASED(0, buttonID)) {
			timerScrollSpeed = 0;
		}
	}
	return isPressed;
}
bool delayed_key_press(int control) {
	if (GET_GAME_TIMER() - lastButtonPress < buttonPressDelay) {
		return false;
	}
	if (IS_DISABLED_CONTROL_PRESSED(0, control) == true) {
		lastButtonPress = GET_GAME_TIMER();
		return true;
	}
	return false;
}

void monitorButtons() {
	Static_67 = GET_FRAME_COUNT();
	if ( !( GET_FRAME_COUNT() - Static_67 >= 2 ) ) {
		testT = true;
	} else testT = false;
	Static_67 = GET_FRAME_COUNT();
	if (NumMenu == Closed) {
		if (IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_RB) && IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_X)) {
			NumMenu = Main_Menu;
			NumMenuLevel = 0;
			currentOption = 1;
			//playSound("HUD_DRAW", "HUD_DUEL_SOUNDSET");
		}
	}
	else {
		if(testT) {
			if (check_button(INPUT_FRONTEND_CANCEL, 0)) {
				if (NumMenu == Main_Menu) {
					NumMenu = Closed;
				}
				else {
					NumMenu = lastNumMenu[NumMenuLevel - 1];
					currentOption = lastOption[NumMenuLevel - 1];
					NumMenuLevel--;
				}
				playSound("BACK", "PAUSE_MENU_SOUNDSET");
			}
			else if (check_button(INPUT_FRONTEND_ACCEPT, 0)) {
				PressX = true;
				playSound("ACCEPT", "PAUSE_MENU_SOUNDSET");
			}
			else if (check_button(INPUT_FRONTEND_UP, 1)) {
				currentOption--;
				if (currentOption < 1) {
					currentOption = optionCount;
				}
				playSound("BUMPER_LEFT", "PAUSE_MENU_SOUNDSET");
			}
			else if (check_button(INPUT_FRONTEND_DOWN, 1)) {
				currentOption++;
				if (currentOption > optionCount) {
					currentOption = 1;
				}
				playSound("BUMPER_LEFT", "PAUSE_MENU_SOUNDSET");
			}
			else if (check_button(INPUT_FRONTEND_RIGHT, 1)) {
				rightPress = true;
				playSound("BUMPER_LEFT", "PAUSE_MENU_SOUNDSET");
			}
			else if (check_button(INPUT_FRONTEND_LEFT, 1)) {
				leftPress = true;
				playSound("BUMPER_LEFT", "PAUSE_MENU_SOUNDSET");
			}
		}
	}
}
void actionsController() {
	DISPLAY_AMMO_THIS_FRAME(0);
		SET_CINEMATIC_BUTTON_ACTIVE(0);
		HIDE_HUD_COMPONENT_THIS_FRAME(HUD_UNUSED);
		HIDE_HUD_COMPONENT_THIS_FRAME(HUD_HELP_TEXT);
		HIDE_HUD_COMPONENT_THIS_FRAME(HUD_STREET_NAME);
		HIDE_HUD_COMPONENT_THIS_FRAME(HUD_AREA_NAME);
		HIDE_HUD_COMPONENT_THIS_FRAME(HUD_VEHICLE_NAME);
		DISABLE_CONTROL_ACTION(2, INPUT_NEXT_CAMERA, true);
		DISABLE_CONTROL_ACTION(2, INPUT_VEH_SELECT_NEXT_WEAPON, true);
		DISABLE_CONTROL_ACTION(2, INPUT_VEH_CIN_CAM, true);
		DISABLE_CONTROL_ACTION(2, INPUT_HUD_SPECIAL, true);
		DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_ACCEPT, true);
		DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_CANCEL, true);
		DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_LEFT, true);
		DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_RIGHT, true);
		DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_DOWN, true);
		DISABLE_CONTROL_ACTION(2, INPUT_FRONTEND_UP, true);
		DISABLE_CONTROL_ACTION(2, INPUT_CHARACTER_WHEEL, true);
		DISABLE_CONTROL_ACTION(2, INPUT_SPRINT, true);
		DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
		DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_LIGHT, true);
		DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_HEAVY, true);
		DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_ALTERNATE, true);
		DISABLE_CONTROL_ACTION(2, INPUT_MELEE_BLOCK, true);
		//DISABLE_CONTROL_ACTION(0, INPUT_ATTACK2, true);
		DISABLE_CONTROL_ACTION(2, INPUT_SCRIPT_PAD_UP, true);
		DISABLE_CONTROL_ACTION(2, INPUT_SCRIPT_PAD_DOWN, true);
		DISABLE_CONTROL_ACTION(2, INPUT_SCRIPT_PAD_LEFT, true);
		DISABLE_CONTROL_ACTION(2, INPUT_SCRIPT_PAD_RIGHT, true);
		DISABLE_CONTROL_ACTION(2, INPUT_RELOAD, true);
		SET_INPUT_EXCLUSIVE(2, INPUT_RELOAD);
		SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_ACCEPT);
		SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_CANCEL);
		SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_DOWN);
		SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_UP);
		SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_LEFT);
		SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_RIGHT);
		SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_X);
		SET_INPUT_EXCLUSIVE(2, INPUT_SCRIPT_PAD_UP);
		SET_INPUT_EXCLUSIVE(2, INPUT_SCRIPT_PAD_DOWN);
		SET_INPUT_EXCLUSIVE(2, INPUT_SCRIPT_PAD_LEFT);
		SET_INPUT_EXCLUSIVE(2, INPUT_SCRIPT_PAD_RIGHT);
		//SET_PED_CAN_SWITCH_WEAPON(PLAYER_PED_ID(), false);
	DRAW_RECT(Menu_X, 0.1177f, CenterDraw, 0.080f,BannerR, BannerG, BannerB, 150);
	if (NumMenu != Closed) {
		if (InfoText != NULL) {
			if (optionCount > maxOptions) {
				DRAW_TEXT(InfoText, 0, 0.758 - 0.125, ((maxOptions + 2.2080) * 0.030f + 0.125f), 0.35f, 0.35f, 255, 255, 255, 255, false, false, 0, 0, 0);
				DRAW_RECT(Menu_X, (((maxOptions + 2.2080) * 0.030f) + 0.1415f), CenterDraw, 0.035f, BannerR, BannerG, BannerB, 150); //Info Box
			}
			else {
				DRAW_TEXT(InfoText, 0, 0.758- 0.125, ((optionCount + 2.2080) * 0.030f + 0.125f), 0.35f, 0.35f, 255, 255, 255, 255, false, false, 0, 0, 0);
				DRAW_RECT(Menu_X, (((optionCount + 2.2080) * 0.030f) + 0.1415f), CenterDraw, 0.035f, BannerR, BannerG, BannerB, 150); //Info Box
			}
		}
		if (optionCount > maxOptions) {
			DRAW_TEXT("Ver: 1.0", 0, 0.758 - 0.125, ((maxOptions + 1) * 0.030f + 0.125f), 0.32f, 0.32f, 255, 255, 255, 255, false, false, 0, 0, 0);
			char buffer[30];
			snprintf(buffer, sizeof(buffer), "~bold~%i/%i", currentOption, optionCount);
			drawTextCounter(buffer, 0, 0.758 + 0.102, ((maxOptions + 1) * 0.030f + 0.125f), 0.32f, 0.32f, 255, 255, 255, 200); //option count
			DRAW_RECT(Menu_X, (((maxOptions + 1) * 0.030f) + 0.1415f), CenterDraw, 0.035f, BannerR, BannerG, BannerB, 150); //Info Box
		}
		else {
			DRAW_TEXT("Ver: 1.0", 0, 0.758- 0.125, ((optionCount + 1) * 0.030f + 0.125f), 0.32f, 0.32f, 255, 255, 255, 255, false, false, 0, 0, 0);
			char buffer[30];
			snprintf(buffer, sizeof(buffer), "~bold~%i/%i", currentOption, optionCount);
			drawTextCounter(buffer, 0, 0.758 + 0.102, ((optionCount + 1) * 0.030f + 0.125f), 0.32f, 0.32f, 255, 255, 255, 200); //option count
			DRAW_RECT(Menu_X, (((optionCount + 1) * 0.030f) + 0.1415f), CenterDraw, 0.035f, BannerR, BannerG, BannerB, 150); //Info Box
		}
	}
}
void looping()
{
	if(GodMode) {
		SET_PLAYER_INVINCIBLE(PLAYER_ID(), true);
	}
}
void menu(void) {
	drawScroller();
	optionCount = 0;
	if(NumMenu == Main_Menu) {
		AddTitle("ArabicGuy");
		addOption("Player",  1, "");
		addOption("Credits",  0, "");
		if(GET() == 1) {
			ChangeMenu(PlayerMenu);
		}
		if(GET() == 2) {
			ChangeMenu(Credits);
		}
	}
	else if(NumMenu == PlayerMenu) {
		AddTitle("Player");
		CheckBox("GodMode", GodMode, 0, "");
		CheckBox("Never Wanted", NeverWanted, 1, "");
		CheckBox("Super Run", SuperRun, 0, "Press X to use super run.");
		CheckBox("Super Jump", SuperJump, 1, "");
		CheckBox("Forcefield", Forcefield, 0, "");
		CheckBox("Invisibility", Invisibility, 1, "");
		CheckBox("Freeze Position", FreezePos, 0, "");
		if(GET() == 1) {
			GodMode = !GodMode;
		}
		
	}
	else if(NumMenu == Credits) {
		AddTitle("Credits");
		addOption("rfoodxmodz", 1, "");;
	}
	if(NumMenu != Closed)
	actionsController();
}

uint32_t main_Hook(char a1) {
int FrameCount = GET_FRAME_COUNT();
		if (FrameCount > frameCount) {
			frameCount = FrameCount;
			looping();
			monitorButtons();
			if(NumMenu != Closed) {
				menu();
				resetVars();
			}
	}
	return 1;
}


};
