// Fill out your copyright notice in the Description page of Project Settings.


#include "MySaveGame.h"

UMySaveGame::UMySaveGame()
{
	PlayerName = TEXT("Default");
	UserIndex = 0;

	CharacterStats.WeaponName = TEXT("");
	CharacterStats.LevelName = TEXT("");
}