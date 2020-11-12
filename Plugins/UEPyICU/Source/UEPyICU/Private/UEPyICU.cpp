// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "UEPyICU.h"
#include "IPythonScriptPlugin.h"
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
        'UEPyICU/Scripts'
    )
# append current dir
sys.path.insert(0, python_script_dir)

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
        'UEPyICU/Scripts'
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

void FUEPyICUModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
    UE_LOG(
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
    );
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FUEPyICUModule, UEPyICU)
