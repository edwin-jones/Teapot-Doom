#ifndef _XBOX_CONTROLLER_H_
#define _XBOX_CONTROLLER_H_
#endif

//
#include "stdafx.h"
#include "controller.h"

// We need the Windows Header and the XInput Header
#include <windows.h>
#include <xinput.h>

void IsRightTriggerDown()
{
	XINPUT_STATE controllerState;
	DWORD player1 = 0;
	ZeroMemory(&controllerState, sizeof(XINPUT_STATE));

	BOOL enabled = 1;

	//XInputEnable(enabled);
	DWORD Result = XInputGetState(0, &controllerState);

	//return controllerState.Gamepad.bRightTrigger > 50;
}

//XINPUT_STATE GetState()
//{
//	// Zeroise the state
//	ZeroMemory(&_controllerState, sizeof(XINPUT_STATE));
//
//	// Get the state
//	XInputGetState(PLAYER_NUMBER, &_controllerState);
//
//	return _controllerState;
//}
//
//bool ControllerIsConnected()
//{
//	// Zeroise the state
//	ZeroMemory(&_controllerState, sizeof(XINPUT_STATE));
//
//	// Get the state
//	DWORD Result = XInputGetState(PLAYER_NUMBER, &_controllerState);
//
//	if (Result == ERROR_SUCCESS)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//void Vibrate(int leftVal, int rightVal)
//{
//	// Create a Vibraton State
//	XINPUT_VIBRATION Vibration;
//
//	// Zeroise the Vibration
//	ZeroMemory(&Vibration, sizeof(XINPUT_VIBRATION));
//
//	// Set the Vibration Values
//	Vibration.wLeftMotorSpeed = leftVal;
//	Vibration.wRightMotorSpeed = rightVal;
//
//	// Vibrate the controller
//	XInputSetState(PLAYER_NUMBER, &Vibration);
//}