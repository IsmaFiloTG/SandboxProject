// Copyright Epic Games, Inc. All Rights Reserved.

#include "Core/SandboxProjectGameMode.h"
#include "Core/SandboxProjectPlayerController.h"
#include "Core/SandboxProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASandboxProjectGameMode::ASandboxProjectGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ASandboxProjectPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}