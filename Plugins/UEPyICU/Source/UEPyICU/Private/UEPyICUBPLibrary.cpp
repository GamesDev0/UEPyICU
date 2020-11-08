// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "UEPyICUBPLibrary.h"
#include "UEPyICU.h"
#include "ShaderCompiler.h"

UUEPyICUBPLibrary::UUEPyICUBPLibrary(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

float UUEPyICUBPLibrary::UEPyICUSampleFunction(float Param)
{
    return -1;
}


void UUEPyICUBPLibrary::ChangeViewMode(EEViewModeIndex ViewModeIndex)
{
    if (GEditor)
    {
        // get veiwport client
        FEditorViewportClient* ViewportClient =
            static_cast<FEditorViewportClient*>(GEditor->GetActiveViewport()->GetClient());
        // set view mode 
        ViewportClient->SetViewMode((EViewModeIndex)((int)(ViewModeIndex)));
    }
}

void UUEPyICUBPLibrary::LogInfoOnScreen(FString InputString)
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, InputString);
    }
}

void UUEPyICUBPLibrary::LogWarnOnScreen(FString InputString)
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, InputString);
    }
}

void UUEPyICUBPLibrary::LogErrorOnScreen(FString InputString)
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, InputString);
    }
}


void UUEPyICUBPLibrary::SetSwitchParameter(
    UMaterialInstanceConstant* MaterialInstance, FName ParameterName, bool SwitchEnabled, bool SwitchValue
)
{
    /*
    * reference
    * https://github.com/20tab/UnrealEnginePython/pull/365/commits/09157b7d0a76d524ebe18f3e8a6567e4d7cc6e2a#diff-aaa4dcbd5cb87d67a8156805f5b93d892439dfaf50159851937e21d5798e9d5b
    */
    bool valid = true;
    FStaticParameterSet StaticParameterSet = MaterialInstance->GetStaticParameters();

    bool isExisting = false;
    for (FStaticSwitchParameter& parameter : StaticParameterSet.StaticSwitchParameters)
    {
        if (parameter.bOverride && parameter.ParameterInfo.Name == ParameterName)
        {
            parameter.bOverride = SwitchEnabled;
            parameter.Value = SwitchValue;
            isExisting = true;
            break;
        }
    }

    if (!isExisting)
    {
        FStaticSwitchParameter SwitchParameter;
        SwitchParameter.ParameterInfo.Name = ParameterName;
        SwitchParameter.Value = SwitchValue;

        SwitchParameter.bOverride = SwitchEnabled;
        StaticParameterSet.StaticSwitchParameters.Add(SwitchParameter);
    }


    MaterialInstance->UpdateStaticPermutation(StaticParameterSet);
}

TArray<FString> UUEPyICUBPLibrary::OpenFileDialog(
    const FString& DialogTitle, const FString& DefaultPath, const FString& FileTypes
)
{
    TArray<FString> OutFileNames;
    void* ParentWindowPtr = FSlateApplication::Get().GetActiveTopLevelWindow()->GetNativeWindow()->GetOSWindowHandle();
    IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
    if (DesktopPlatform)
    {
        // todo add single file / multi file to argument
        uint32 SelectionFlag = 1;
        //A value of 0 represents single file selection while a value of 1 represents multiple file selection
        DesktopPlatform->OpenFileDialog(
            ParentWindowPtr, DialogTitle, DefaultPath, FString(""), FileTypes, SelectionFlag, OutFileNames
        );
    }
    return OutFileNames;
}

bool UUEPyICUBPLibrary::IsAllGlobalShaderCompiled()
{
    //ref: Runtime/Engine/Public/ShaderCompiler.h line 620 
    return IsGlobalShaderMapComplete();
}
