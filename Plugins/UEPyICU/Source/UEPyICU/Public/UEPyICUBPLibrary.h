// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"

//#if WITH_EDITOR
#include "Editor/UnrealEd/Classes/MaterialGraph/MaterialGraph.h"
#include "Editor/UnrealEd/Public/Kismet2/BlueprintEditorUtils.h"
#include "Editor/UnrealEd/Classes/MaterialGraph/MaterialGraphSchema.h"
#include "Materials/MaterialInstanceConstant.h"

#include "DesktopPlatform/Public/IDesktopPlatform.h"
#include "DesktopPlatform/Public/DesktopPlatformModule.h"
#include "Framework/Application/SlateApplication.h"

#include "LevelEditor.h"
#include "EditorViewportClient.h"
//#endif


#include "UEPyICUBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class UUEPyICUBPLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_UCLASS_BODY()

    UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Sample function", Keywords =
        "UEPyICU sample test testing"), Category = "UEPyICUTesting")
    static float UEPyICUSampleFunction(float Param);


    UFUNCTION(BlueprintCallable)
    static void ChangeViewMode();

    UFUNCTION(BlueprintCallable)
    static void LogInfoOnScreen(FString InputString);

    UFUNCTION(BlueprintCallable)
    static void LogWarnOnScreen(FString InputString);

    UFUNCTION(BlueprintCallable)
    static void LogErrorOnScreen(FString InputString);

    UFUNCTION(BlueprintCallable)
    static void SetSwitchParameter(
        UMaterialInstanceConstant* MaterialInstance, FName ParameterName, bool SwitchEnabled, bool SwitchValue
    );

    UFUNCTION(BlueprintCallable)
    static TArray<FString> OpenFileDialog(
        const FString& DialogTitle, const FString& DefaultPath, const FString& FileTypes
    );

    UFUNCTION(BlueprintCallable)
    static bool IsAllGlobalShaderCompiled();
};
