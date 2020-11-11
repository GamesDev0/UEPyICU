# open dialog
icu_lib = unreal.UEPyICUBPLibrary
enum_view_mode_index = unreal.EViewModeIndex

files = icu_lib.open_file_dialog("open dialog", ".", "*")
# if utf8 string , encode
file_name = files[0].encode('utf8')
print(file_name)

# print info on viewport , this no needs encode
icu_lib.log_info_on_screen(file_name)

# set view mode 
icu_lib.change_view_mode(enum_view_mode_index.LIT)
