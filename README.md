# UEPyICU

official api doc is so confusing, this just save your lives.

1. Introduction

    0.  **need open these plugins**
        - Editor Scripting Utilities
        - Python Editor Script Plu
    1.  - **now only works in editor time**
        - if you need runtime , please add a card to the project
    2.  - visual studio version : **vs 2015**
    3.  - ue4 version of the project : **4.24.3**
    4.  **wiki site**
        - click https://github.com/GamesDev0/UEPyICU/wiki
    5.  **add reqeuest**
        - click https://github.com/GamesDev0/UEPyICU/projects/1 add a card to **want** column gin

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
    # print info on viewport 
    icu_lib = unreal.UEPyICUBPLibrary
    icu_lib.log_info_on_screen("Hello , UEPyICU")
    ```
