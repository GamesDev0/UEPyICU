# open dialog
icu_lib = unreal.UEPyICUBPLibrary

files = icu_lib.open_file_dialog("open dialog", ".", "*")
# if utf8 string , encode
file_name = files[0].encode('utf8')
print(file_name)

# print info on viewport , this no needs encode
icu_lib.log_info_on_screen(file_name)