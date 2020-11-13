// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "UEPyICU.h"
#include "IPythonScriptPlugin.h"
#include "Containers/Ticker.h"
#define LOCTEXT_NAMESPACE "FUEPyICUModule"
FString StartUpScript =
    R"(
import unreal
import sys 
import os
# add plugins python script dir
python_script_dir = \
    os.path.join(
        unreal.Paths.make_standard_filename(
            unreal.Paths.project_plugins_dir()
        ), 
        'UEPyICU/PyLib'
    )
# append PyLib dir
sys.path.insert(0, python_script_dir)
# append PyLib/site-packages dir
sys.path.insert(0, os.path.join(python_script_dir, 'site-packages'))


start_up_file_path = os.path.join(python_script_dir, '__ue_py_icu_start_up__.py' )

try:
    execfile(start_up_file_path)
except Exception as e:
    print(e)
)";

FString ShutDownScript =
    R"(
import unreal
import sys 
import os
# add plugins python script dir
python_script_dir = \
    os.path.join(
        unreal.Paths.make_standard_filename(
            unreal.Paths.project_plugins_dir()
        ), 
        'UEPyICU/PyLib'
    )
# append current dir
sys.path.insert(0, python_script_dir)

shut_down_file_path = os.path.join(python_script_dir, '__ue_py_icu_shut_down__.py' )

try:
    execfile(shut_down_file_path)
except Exception as e:
    print(e)
)";

void FUEPyICUModule::StartupModule()
{
    // with this to ensure init script run after editor show up
    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

    // Initialize the tick handler 
    // ref https://blog.l0v0.com/posts/513f9ff.html
    FTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateLambda([this](float DeltaTime)
    {
        OnTick(DeltaTime);
        return true;
    }));
}

void FUEPyICUModule::ShutdownModule()
{
    // todo make shut down script works 
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.

    // seems this will cause crash
    /*UE_LOG(
        LogTemp, Warning,
        TEXT(
            "#### shut down  script : start #### try load init script Plugins/UEPyICU/Scripts/__ue_py_icu_shut_down__.py"
        )
    );
    IPythonScriptPlugin::Get()->ExecPythonCommand(ToCStr(ShutDownScript));
    UE_LOG(
        LogTemp, Warning,
        TEXT(
            "#### shut down  script :  end  #### try load init script Plugins/UEPyICU/Scripts/__ue_py_icu_shut_down__.py"
        )
    );*/
}

void FUEPyICUModule::OnTick(const float InDeltaTime)
{
    if (!bHasTicked)
    {
        bHasTicked = true;
        // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
        UE_LOG(
            LogTemp, Warning,
            TEXT(
                "#### start up  script : start #### try load init script Plugins/UEPyICU/Scripts/__ue_py_icu_start_up__.py"
            )
        );
        IPythonScriptPlugin::Get()->ExecPythonCommand(ToCStr(StartUpScript));
        UE_LOG(
            LogTemp, Warning,
            TEXT(
                "#### start up  script :  end  #### try load init script Plugins/UEPyICU/Scripts/__ue_py_icu_start_up__.py"
            )
        );
    }
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FUEPyICUModule, UEPyICU)
