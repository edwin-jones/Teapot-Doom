#include "stdafx.h"
#include "xcontroller.h"

//XInput Header:
#include <XInput.h>

// Now, the XInput Library
// NOTE: COMMENT THIS OUT IF YOU ARE NOT USING
// A COMPILER THAT SUPPORTS THIS METHOD OF LINKING LIBRARIES
#pragma comment(lib, "XInput.lib")
// We need the Windows Header and the XInput Header

#define Player1 0
#define MinimumInput 16768
#define StandardRumble 32000
#define MinimumTriggerValue 50
#define RumbleDecrement 1000;

XINPUT_STATE controllerState = { 0 };

int rumbleAmount = 0;

//static (sort of like private for C) function to load current input stat into controllerstate struct.
static DWORD GetInput(XINPUT_STATE *pControllerState)
{
	ZeroMemory(&controllerState, sizeof(XINPUT_STATE));
	return XInputGetState(Player1, &controllerState);
}

//Check to see if a controller is connected
bool IsControllerConnected()
{
	return GetInput == ERROR_SUCCESS;
}

//check to see if the right trigger is down (past a small threshold).
bool IsTriggerDown(Direction trigger)
{
	if (GetInput(&controllerState) == ERROR_SUCCESS)
	{
		if (trigger == RIGHT && controllerState.Gamepad.bRightTrigger > MinimumTriggerValue
			|| trigger == LEFT && controllerState.Gamepad.bLeftTrigger > MinimumTriggerValue)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//check to see if the a button is pressed
bool IsButtonPressed(Button button)
{
	if (GetInput(&controllerState) == ERROR_SUCCESS)
	{
		if (controllerState.Gamepad.wButtons & button)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//check to see if the left analog stick is pressed left (past a small threshold).
bool IsAnalogStickPressedInDirection(Direction stick, Direction direction)
{
	if (GetInput(&controllerState) == ERROR_SUCCESS)
	{
		if (stick == LEFT)
		{
			switch (direction)
			{
			case LEFT:
				if (controllerState.Gamepad.sThumbLX < -MinimumInput) return true;
				break;
			case RIGHT:
				if (controllerState.Gamepad.sThumbLX > MinimumInput) return true;
				break;
			case UP:
				if (controllerState.Gamepad.sThumbLY > MinimumInput) return true;
				break;
			case DOWN:
				if (controllerState.Gamepad.sThumbLY < -MinimumInput) return true;
				break;
			default:
				break;
			}
		}
		if (stick == RIGHT)
		{
			switch (direction)
			{
			case LEFT:
				if (controllerState.Gamepad.sThumbRX < -MinimumInput) return true;
				break;
			case RIGHT:
				if (controllerState.Gamepad.sThumbRX > MinimumInput) return true;
				break;
			case UP:
				if (controllerState.Gamepad.sThumbRY > MinimumInput) return true;
				break;
			case DOWN:
				if (controllerState.Gamepad.sThumbRY < -MinimumInput) return true;
				break;
			default:
				break;
			}
		}

		//if this point is reached, NOTHING is pressed - return false.
		return false;

	}
	else
	{
		return false;
	}
}

//This function will reset controller rumble to it's max.
void StartRumble()
{
	rumbleAmount = StandardRumble;
}

//This function will slowly decrement rumble over time and should be called in an update loop.
void UpdateRumble()
{
	if (rumbleAmount > 0)
	{
		rumbleAmount -= RumbleDecrement;
	}

	XINPUT_VIBRATION controllerVibration =
	{
		rumbleAmount,
		rumbleAmount,
	};

	XInputSetState(Player1, &controllerVibration);
}
