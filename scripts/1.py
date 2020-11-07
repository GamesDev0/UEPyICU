# open dialog
icu_lib = unreal.UEPyICUBPLibrary

files = icu_lib.open_file_dialog("open dialog", ".", "*")
# if utf8 string , encode
print(files[0].encode('utf8'))

# print info on viewport
icu_lib.log_info_on_screen("Hello , UEPyICU")