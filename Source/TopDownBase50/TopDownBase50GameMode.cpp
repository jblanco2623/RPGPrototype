// Copyright Epic Games, Inc. All Rights Reserved.

#include "TopDownBase50GameMode.h"
#include "TopDownBase50PlayerController.h"
#include "TopDownBase50Character.h"
#include "UObject/ConstructorHelpers.h"

ATopDownBase50GameMode::ATopDownBase50GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATopDownBase50PlayerController::StaticClass();

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