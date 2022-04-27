# importing os module
import os
import glob
import pathlib
import shutil
# Directory
directory = "강성태 영어회화 DAY{}-DAY{}"

  
# Parent Directory path
parent_dir_path = pathlib.PureWindowsPath(r"C:\Users\like_\OneDrive\storage\english\강성태 66일 영어회화\drive-download-20220319T134759Z-001\강성태 원어민 5일단위")

input_folder_path = pathlib.PureWindowsPath(r"C:\Users\like_\OneDrive\storage\english\강성태 66일 영어회화\drive-download-20220319T134759Z-001\「강성태 66일 영어회화」원어민 mp3")

for start in range(1,66,5):
    # Path
    target_folder_path = os.path.join(parent_dir_path, directory.format(start,start+5 -1))
    os.mkdir(target_folder_path)    
    # 폴더를 생성한다.
    for idx in range(5):
        # 혹시나 해당하는 파일들이 있으면
        os.chdir(input_folder_path)
        for file in glob.glob("Day{}_E*".format(start+idx)):
            # 복사해서 붙여넣는다.
            origin_file_path = os.path.join(input_folder_path, file)
            target_file_path = os.path.join(target_folder_path, file)
            shutil.copyfile(origin_file_path, target_file_path)
