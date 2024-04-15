#pragma once

#include "types.h"
#include <utility>
#include "global.h"

NAMESPACE(Hooks)

typedef void(*IsPlayerOnline_t)();

extern IsPlayerOnline_t IsPlayerOnline_s;

void IsPlayerOnlineHook();

END

#define MaxSubmenuLevels 20

typedef void(*Function)();
typedef void(*KeyboardHandler)(const char*);

class Menu {
private:
	Function mainMenu;
	Function currentMenu;
	Function lastSubmenu[MaxSubmenuLevels];
	int submenuLevel;

	const char* tipText;
	int currentOption;
	int optionCount;
	int lastOption[MaxSubmenuLevels];

	bool optionPress,
		leftPress,
		rightPress,
		leftHold,
		rightHold,
		upPress,
		downPress,
		squarePress;

	Scaleform instructionsHandle;
	int instructionCount;
	bool setupIntructionsThisFrame,
		xInstruction,
		squareInstruction,
		lrInstruction;

	bool keyboardActive;
	KeyboardHandler keyboardHandler;

	template <typename T> struct scrollData {
		T* var;
		T min;
		T max;
		int decimals;
	};
	static scrollData<int> intScrollData;
	static scrollData<float> floatScrollData;

	static void intScrollKeyboardHandler(const char* text);
	static void floatScrollKeyboardHandler(const char* text);

	void playSound(const char* sound);

	enum Alignment {
		Left,
		Center,
		Right
	};
	void drawText(const char* text, Vector2 pos, float scale, Font font, Color color, Alignment alignment, bool outline);

	void setupInstructions();
	void addInstruction(ScaleformSymbol symbol, const char* text);
	void finishInstructions();

	void positionMenuText(const char* text, float xPos, Alignment alignment);

	bool fastScrolling;

	bool colorEditing;
	bool editingAlpha;
	Color* colorToEdit;
	Function colorChangeCallback;
	void colorEditor();

public:
	bool open,
		sounds,
		instructions;

	const char* title;
	Font titleFont;

	int maxOptions;
	Font optionsFont;

	Color bannerColor,
		bannerTextColor,
		optionsActiveColor,
		optionsInactiveColor,
		bodyColor,
		scrollerColor,
		indicatorColor,
		instructionsColor;

	Menu();
	Menu(Menu& menu);
	Menu(Function main);

	static void drawCenterNotification(const char* text, int duration = 3000);
	static void drawFeedNotification(const char* text, const char* subtitle, const char* title = "Menu Base");

	void monitorButtons();
	void run();
	void Loop();
};
