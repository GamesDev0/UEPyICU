# UEPyICU

official api doc is so confusing, this just save your lives.

Thanks to https://github.com/20tab/UnrealEnginePython

1. Introduction

    0.  **need open these plugins**
        - Editor Scripting Utilities
        - Python Editor Script Plugin
    1.  - **now only works in editor time**
            - if you need runtime , please add a card to the project
    2.  - visual studio version : **vs 2015**
    3.  - ue4 version of the project : **4.24.3**
    4.  **wiki site**
        - click https://github.com/GamesDev0/UEPyICU/wiki
    5.  **add reqeuest**
        - click https://github.com/GamesDev0/UEPyICU/projects/1 add a card to **want** column

2. git commit format

    ```
    update: update string
    chore: some chore string , like bat files
    feature: new feature add
    todo: add todo string
    docs: docs update string
    ```

3. example
    ```python
    icu_lib = unreal.UEPyICUBPLibrary
    
    icu_lib.log_error_on_screen("error")
    icu_lib.log_info_on_screen("info")
    icu_lib.log_warn_on_screen("warn")
    file_list = icu_lib.open_file_dialog("title","d:/","*")
    icu_lib.set_switch_parameter(
        material_instance,
        "switch_param_name",
        True, # enable swtich
        True # set switch value to true
    )

    #### example for change view mode ####
    enum_view_mode_index = unreal.EViewModeIndex
    # set view mode 
    # valid view mode , search with the string you saw in viewport:
    """
     BRUSH_WIREFRAME COLLISION_PAWN COLLISION_VISIBILITY GROUP_LOD_COLORATION 
     HLOD_COLORATION LIGHTING_ONLY LIGHTMAP_DENSITY LIGHT_COMPLEXITY 
     LIT LIT_DETAIL_LIGHTING LIT_LIGHTMAP_DENSITY LOD_COLORATION 
     MATERIAL_TEXTURE_SCALE_ACCURACY MESH_UV_DENSITY_ACCURACY 
     PATH_TRACING PRIMITIVE_DISTANCE_ACCURACY QUAD_OVERDRAW RAY_TRACING_DEBUG 
     REFLECTION_OVERRIDE REQUIRED_TEXTURE_RESOLUTION SHADER_COMPLEXITY 
     SHADER_COMPLEXITY_WITH_QUAD_OVERDRAW STATIONARY_LIGHT_OVERLAP 
     UNLIT VISUALIZE_BUFFER WIREFRAME
    """
    icu_lib.change_view_mode(enum.LIT)

    # this method to select actor even actor is hidden
    icu_lib.select_actor(actor)
    
    # add [ Plugins/UEPyICU/PyLib , Plugins/UEPyICU/PyLib/site-packages ] to sys.path
    # add Plugins/UEPyICU/PyLib/__ue_py_icu_start_up__.py  as startup script
    # -- not works now , support later -- add Plugins/UEPyICU/PyLib/__ue_py_icu_shut_down__.py as shutdown script
    ```
