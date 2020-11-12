// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "UEPyICU.h"
#include "IPythonScriptPlugin.h"
#define LOCTEXT_NAMESPACE "FUEPyICUModule"
FString InitScript =
    R"(
import unreal
import sys 
import os
# add plugins python script dir
python_init_script_dir = \
    os.path.join(
        unreal.Paths.make_standard_filename(
            unreal.Paths.project_plugins_dir()
        ), 
        'UEPyICU/Scripts'
    )
# append current dir
sys.path.insert(0, python_init_script_dir)

init_script_file_path = os.path.join(python_init_script_dir, '__ue_py_icu_init__.py' )

try:
    execfile(init_script_file_path)
except Exception as e:
    print(e)
)";


void FUEPyICUModule::StartupModule()
{
    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
    UE_LOG(LogTemp, Warning, TEXT("---- load init script : start ---- try load init script UEPyICU/Scripts/__ue_py_icu_init__.py"));
    IPythonScriptPlugin::Get()->ExecPythonCommand(ToCStr(InitScript));
    UE_LOG(LogTemp, Warning, TEXT("---- load init script :  end  ---- try load init script UEPyICU/Scripts/__ue_py_icu_init__.py"));
}

void FUEPyICUModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FUEPyICUModule, UEPyICU)
