#ifndef _XBOX_CONTROLLER_H_
#define _XBOX_CONTROLLER_H_

#include <stdbool.h>

typedef unsigned short Button;
typedef enum { LEFT, RIGHT, UP, DOWN, } Direction;

//we have to steal the XINPUT button defines here, as including the header breaks things
//if it gets exposed to the main doom code.
#define XINPUT_GAMEPAD_DPAD_UP          0x0001
#define XINPUT_GAMEPAD_DPAD_DOWN        0x0002
#define XINPUT_GAMEPAD_DPAD_LEFT        0x0004
#define XINPUT_GAMEPAD_DPAD_RIGHT       0x0008
#define XINPUT_GAMEPAD_START            0x0010
#define XINPUT_GAMEPAD_BACK             0x0020
#define XINPUT_GAMEPAD_LEFT_THUMB       0x0040
#define XINPUT_GAMEPAD_RIGHT_THUMB      0x0080
#define XINPUT_GAMEPAD_LEFT_SHOULDER    0x0100
#define XINPUT_GAMEPAD_RIGHT_SHOULDER   0x0200
#define XINPUT_GAMEPAD_A                0x1000
#define XINPUT_GAMEPAD_B                0x2000
#define XINPUT_GAMEPAD_X                0x4000
#define XINPUT_GAMEPAD_Y                0x8000

//Boolean functions to check button states
bool IsTriggerDown(Direction trigger);
bool IsButtonPressed(Button button);
bool IsAnalogStickPressedInDirection(Direction stick, Direction direction);

//Rumble setter functions.
void StartRumble();
void UpdateRumble();

#endif