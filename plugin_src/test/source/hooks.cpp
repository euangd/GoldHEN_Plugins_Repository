#include "hooks.h"
#include "defines.h"
#include "functions.h"
#include "utility.h"
#include "menu.h"
//#include "natives.h"
//#include "setGlobal.h"

using namespace Functions;

// NAMESPACE(Hooks)

// IsPlayerOnline_t IsPlayerOnline_s;

// void selfLoops()
// {
// 	Player player = PLAYER::PLAYER_ID();

// 	if (superJump)
// 	{
// 		MISC::SET_SUPER_JUMP_THIS_FRAME(player);
// 	}
// 	if (explosiveAmmo)
// 	{
// 		MISC::SET_EXPLOSIVE_AMMO_THIS_FRAME(player);
// 	}
// 	if (explosiveMelee)
// 	{
// 		MISC::SET_EXPLOSIVE_MELEE_THIS_FRAME(player);
// 	}
// 	//*getGlobal(4541411) = 1; //DLC Cars in SP //updated to 1.48
// }

// void selfOptions() {
// 	menu.banner("Self Options");

// 	bool godmode = PLAYER::GET_PLAYER_INVINCIBLE(PLAYER::PLAYER_ID());
// 	menu.option("Godmode").data(godmode).call(PLAYER::SET_PLAYER_INVINCIBLE, PLAYER::PLAYER_ID(), !godmode);

// 	bool invisibility = !ENTITY::IS_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID());
// 	menu.option("Invisibility").data(invisibility).call(ENTITY::SET_ENTITY_VISIBLE, PLAYER::PLAYER_PED_ID(), invisibility, false);

// 	menu.option("Super Jump").toggle(&superJump);
// 	menu.option("Explosive Ammo").toggle(&explosiveAmmo);
// 	menu.option("Explosive Melee").toggle(&explosiveMelee);
// }

// void vehSpawnKeyboardHandler(const char* text) {
// 	Hash vehHash = MISC::GET_HASH_KEY(text);
// 	if (STREAMING::IS_MODEL_A_VEHICLE(vehHash)) {
// 		menu.vehicleToSpawn = vehHash;
// 	}
// 	else {
// 		menu.drawFeedNotification("Invalid vehicle model", "Error");
// 	}
// }
// void vehSpawnHandler() {
// 	if (menu.vehicleToSpawn) {
// 		if (STREAMING::HAS_MODEL_LOADED(menu.vehicleToSpawn)) {
// 			Ped playerPed = PLAYER::PLAYER_PED_ID();
// 			Vector3 myCoords = ENTITY::GET_ENTITY_COORDS(playerPed, false);
// 			Vehicle newVehicle = VEHICLE::CREATE_VEHICLE(menu.vehicleToSpawn, myCoords.x, myCoords.y, myCoords.z, ENTITY::GET_ENTITY_HEADING(playerPed), false, false, false);

// 			if (ENTITY::DOES_ENTITY_EXIST(newVehicle)) {
// 				float currentSpeed = 0;

// 				if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, false)) {
// 					Vehicle currentVehicle = PED::GET_VEHICLE_PED_IS_USING(playerPed);
// 					currentSpeed = ENTITY::GET_ENTITY_SPEED(currentVehicle);
// 					VEHICLE::DELETE_VEHICLE(&currentVehicle);
// 				}

// 				PED::SET_PED_INTO_VEHICLE(playerPed, newVehicle, -1);
// 				VEHICLE::SET_VEHICLE_FORWARD_SPEED(newVehicle, currentSpeed);
// 				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(menu.vehicleToSpawn);
// 				menu.vehicleToSpawn = 0;
// 			}
// 		}
// 		else {
// 			STREAMING::REQUEST_MODEL(menu.vehicleToSpawn);
// 		}
// 	}
// }
// void vehicleSpawner() {
// 	menu.banner("Vehicle Spawner");
// 	menu.option("Adder").vehicleSpawn(0xB779A091);
// 	menu.option("Turismo").vehicleSpawn(0x185484E1);
// 	menu.option("Rhino").vehicleSpawn(0x2EA68690);
// 	menu.option("Liberator").vehicleSpawn(0xCD93A7DB);
// 	menu.option("Buzzard").vehicleSpawn(0x2F03547B);
// 	menu.option("Lazer").vehicleSpawn(0xB39B0AE6);
// 	menu.option("Custom").keyboard(vehSpawnKeyboardHandler, 20);
// }

// void bannerSettings() {
// 	menu.banner("Banner Settings");
// 	menu.option("Color").editColor(&menu.bannerColor, true);
// 	menu.option("Indicator Color").editColor(&menu.indicatorColor, true);
// 	menu.option("Text Color").editColor(&menu.bannerTextColor, true);
// 	menu.option("Text Font").scroller(&menu.titleFont);
// }
// void optionSettings() {
// 	menu.banner("Option Settings");
// 	menu.option("Background Color").editColor(&menu.bodyColor, true);
// 	menu.option("Scroller Color").editColor(&menu.scrollerColor, true);
// 	menu.option("Text Active Color").editColor(&menu.optionsActiveColor, true);
// 	menu.option("Text Inactive Color").editColor(&menu.optionsInactiveColor, true);
// 	menu.option("Text Font").scroller(&menu.optionsFont);
// 	menu.option("Max Options").scroller(&menu.maxOptions, 1, 30, false, false);
// }
// void instructionSettings() {
// 	menu.banner("Instruction Settings");
// 	menu.option("Show").toggle(&menu.instructions);
// 	menu.option("Color").editColor(&menu.instructionsColor, true);
// }
// void menuSettings() {
// 	menu.banner("Menu Settings");
// 	menu.option("Banner Settings").submenu(bannerSettings);
// 	menu.option("Option Settings").submenu(optionSettings);
// 	menu.option("Instruction Settings").submenu(instructionSettings);
// 	menu.option("Sounds").toggle(&menu.sounds);
// }

// void mainMenu() {
// 	menu.banner("Main Menu");
// 	menu.option("Self Options").submenu(selfOptions);
// 	menu.option("Vehicle Spawner").submenu(vehicleSpawner);
// 	menu.option("Settings").tip("Customize the menu").submenu(menuSettings);
// }

//Menu menu;

// void IsPlayerOnlineHook()
// {
// 	// IsPlayerOnline_s();
// 	if (!init)
// 	{
// 		menu = Menu(mainMenu);
// 		init = true;
// 	}
// 	int newFrameCount = MISC::GET_FRAME_COUNT();
// 	if (newFrameCount > frameCount)
// 	{
// 		frameCount = newFrameCount;
// 		menu.monitorButtons();

// 		// menu.Loop();
// 		// Menu::SetupButtons();
// 		// Menu();
// 		// Menu::Setup_System();
// 		// vehSpawnHandler();
// 		// if (menu.open) {
// 		// 	menu.run();
// 		// }
// 	}
// }

// END