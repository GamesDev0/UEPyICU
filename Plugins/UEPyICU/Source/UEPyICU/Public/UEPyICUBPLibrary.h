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

/**
* ref: Runtime/Engine/Classes/Engine/EngineBaseTypes.h  line 914 EViewModeIndex
* Define view modes to get specific show flag settings (some on, some off and some are not altered)
* Don't change the order, the ID is serialized with the editor
*/
UENUM(BlueprintType)
enum EEViewModeIndex
{
    /*
     * to avoid to save as EngineBaseTypes
     *
     * EViewModeIndex -> EEViewModeIndex
     *                    *
     *
     * "VMI_"         -> ""  
     */


    /** Wireframe w/ brushes. */
    BrushWireframe = 0 UMETA(DisplayName = "Brush Wireframe"),
    /** Wireframe w/ BSP. */
    Wireframe = 1 UMETA(DisplayName = "Wireframe"),
    /** Unlit. */
    Unlit = 2 UMETA(DisplayName = "Unlit"),
    /** Lit. */
    Lit = 3 UMETA(DisplayName = "Lit"),
    Lit_DetailLighting = 4 UMETA(DisplayName = "Detail Lighting"),
    /** Lit wo/ materials. */
    LightingOnly = 5 UMETA(DisplayName = "Lighting Only"),
    /** Colored according to light count. */
    LightComplexity = 6 UMETA(DisplayName = "Light Complexity"),
    /** Colored according to shader complexity. */
    ShaderComplexity = 8 UMETA(DisplayName = "Shader Complexity"),
    /** Colored according to world-space LightMap texture density. */
    LightmapDensity = 9 UMETA(DisplayName = "Lightmap Density"),
    /** Colored according to light count - showing lightmap texel density on texture mapped objects. */
    LitLightmapDensity = 10 UMETA(DisplayName = "Lit Lightmap Density"),
    ReflectionOverride = 11 UMETA(DisplayName = "Reflections"),
    VisualizeBuffer = 12 UMETA(DisplayName = "Buffer Visualization"),
    //	VMI_VoxelLighting = 13,

    /** Colored according to stationary light overlap. */
    StationaryLightOverlap = 14 UMETA(DisplayName = "Stationary Light Overlap"),

    CollisionPawn = 15 UMETA(DisplayName = "Player Collision"),
    CollisionVisibility = 16 UMETA(DisplayName = "Visibility Collision"),
    //VMI_UNUSED = 17,
    /** Colored according to the current LOD index. */
    LODColoration = 18 UMETA(DisplayName = "Mesh LOD Coloration"),
    /** Colored according to the quad coverage. */
    QuadOverdraw = 19 UMETA(DisplayName = "Quad Overdraw"),
    /** Visualize the accuracy of the primitive distance computed for texture streaming. */
    PrimitiveDistanceAccuracy = 20 UMETA(DisplayName = "Primitive Distance"),
    /** Visualize the accuracy of the mesh UV densities computed for texture streaming. */
    MeshUVDensityAccuracy = 21 UMETA(DisplayName = "Mesh UV Density"),
    /** Colored according to shader complexity, including quad overdraw. */
    ShaderComplexityWithQuadOverdraw = 22 UMETA(DisplayName = "Shader Complexity & Quads"),
    /** Colored according to the current HLOD index. */
    HLODColoration = 23 UMETA(DisplayName = "Hierarchical LOD Coloration"),
    /** Group item for LOD and HLOD coloration*/
    GroupLODColoration = 24 UMETA(DisplayName = "Group LOD Coloration"),
    /** Visualize the accuracy of the material texture scales used for texture streaming. */
    MaterialTextureScaleAccuracy = 25 UMETA(DisplayName = "Material Texture Scales"),
    /** Compare the required texture resolution to the actual resolution. */
    RequiredTextureResolution = 26 UMETA(DisplayName = "Required Texture Resolution"),

    // Ray tracing modes

    /** Run path tracing pipeline */
    PathTracing = 27 UMETA(DisplayName = "Path Tracing"),
    /** Run ray tracing debug pipeline */
    RayTracingDebug = 28 UMETA(DisplayName = "Ray Tracing Debug"),

    Max UMETA(Hidden),

    // Unknown = 255 UMETA(DisplayName = "Unknown"),
};


UCLASS()
class UUEPyICUBPLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_UCLASS_BODY()

    UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Sample function", Keywords =
        "UEPyICU sample test testing"), Category = "UEPyICUTesting")
    static float UEPyICUSampleFunction(float Param);


    UFUNCTION(BlueprintCallable)
    static void ChangeViewMode(EEViewModeIndex ViewModeIndex);

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

    UFUNCTION(BlueprintCallable)
    static void SelectActor(
        AActor* actor, bool bInSelected = true, bool bNotify = true,
        bool bSelectEvenIfHidden = true, bool bForceRefresh = true
    );

    UFUNCTION(BlueprintCallable)
    static int32 GetCompilingShaderJobCount();

    UFUNCTION(BlueprintCallable)
    static void WaitForCompilingShaderDone();
};
