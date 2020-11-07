# open dialog

files = unreal.UEPyICUBPLibrary.open_file_dialog("open dialog", ".", "*")
print(files)

# print info on viewport
icu_lib = unreal.UEPyICUBPLibrary
icu_lib.log_info_on_screen("Hello , UEPyICU")