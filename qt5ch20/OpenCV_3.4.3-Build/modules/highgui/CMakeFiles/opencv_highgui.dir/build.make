# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = I:\charon\IDM\cmake-3.18.0-win64-x64\cmake-3.18.0-win64-x64\bin\cmake.exe

# The command to remove a file.
RM = I:\charon\IDM\cmake-3.18.0-win64-x64\cmake-3.18.0-win64-x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Source

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build

# Include any dependencies generated for this target.
include modules/highgui/CMakeFiles/opencv_highgui.dir/depend.make

# Include the progress variables for this target.
include modules/highgui/CMakeFiles/opencv_highgui.dir/progress.make

# Include the compile flags for this target's objects.
include modules/highgui/CMakeFiles/opencv_highgui.dir/flags.make

modules/highgui/src/moc_window_QT.cpp: I:/charon/mydemo/measurement/MfcQt/QT/QT5/qt5ch20/OpenCV_3.4.3-Source/modules/highgui/src/window_QT.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating src/moc_window_QT.cpp"
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui\src && D:\Qt\5.12.2\mingw73_32\bin\moc.exe @I:/charon/mydemo/measurement/MfcQt/QT/QT5/qt5ch20/OpenCV_3.4.3-Build/modules/highgui/src/moc_window_QT.cpp_parameters

modules/highgui/qrc_window_QT.cpp: I:/charon/mydemo/measurement/MfcQt/QT/QT5/qt5ch20/OpenCV_3.4.3-Source/modules/highgui/src/files_Qt/Milky/48/28.png
modules/highgui/qrc_window_QT.cpp: I:/charon/mydemo/measurement/MfcQt/QT/QT5/qt5ch20/OpenCV_3.4.3-Source/modules/highgui/src/files_Qt/Milky/48/23.png
modules/highgui/qrc_window_QT.cpp: I:/charon/mydemo/measurement/MfcQt/QT/QT5/qt5ch20/OpenCV_3.4.3-Source/modules/highgui/src/files_Qt/Milky/48/19.png
modules/highgui/qrc_window_QT.cpp: I:/charon/mydemo/measurement/MfcQt/QT/QT5/qt5ch20/OpenCV_3.4.3-Source/modules/highgui/src/files_Qt/Milky/48/24.png
modules/highgui/qrc_window_QT.cpp: I:/charon/mydemo/measurement/MfcQt/QT/QT5/qt5ch20/OpenCV_3.4.3-Source/modules/highgui/src/files_Qt/Milky/48/27.png
modules/highgui/qrc_window_QT.cpp: I:/charon/mydemo/measurement/MfcQt/QT/QT5/qt5ch20/OpenCV_3.4.3-Source/modules/highgui/src/files_Qt/Milky/48/61.png
modules/highgui/qrc_window_QT.cpp: I:/charon/mydemo/measurement/MfcQt/QT/QT5/qt5ch20/OpenCV_3.4.3-Source/modules/highgui/src/files_Qt/Milky/48/106.png
modules/highgui/qrc_window_QT.cpp: I:/charon/mydemo/measurement/MfcQt/QT/QT5/qt5ch20/OpenCV_3.4.3-Source/modules/highgui/src/files_Qt/Milky/48/107.png
modules/highgui/qrc_window_QT.cpp: I:/charon/mydemo/measurement/MfcQt/QT/QT5/qt5ch20/OpenCV_3.4.3-Source/modules/highgui/src/files_Qt/Milky/48/7.png
modules/highgui/qrc_window_QT.cpp: I:/charon/mydemo/measurement/MfcQt/QT/QT5/qt5ch20/OpenCV_3.4.3-Source/modules/highgui/src/files_Qt/Milky/48/38.png
modules/highgui/qrc_window_QT.cpp: I:/charon/mydemo/measurement/MfcQt/QT/QT5/qt5ch20/OpenCV_3.4.3-Source/modules/highgui/src/files_Qt/stylesheet_trackbar.qss
modules/highgui/qrc_window_QT.cpp: modules/highgui/src/window_QT.qrc.depends
modules/highgui/qrc_window_QT.cpp: I:/charon/mydemo/measurement/MfcQt/QT/QT5/qt5ch20/OpenCV_3.4.3-Source/modules/highgui/src/window_QT.qrc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating qrc_window_QT.cpp"
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui && D:\Qt\5.12.2\mingw73_32\bin\rcc.exe --name window_QT --output I:/charon/mydemo/measurement/MfcQt/QT/QT5/qt5ch20/OpenCV_3.4.3-Build/modules/highgui/qrc_window_QT.cpp I:/charon/mydemo/measurement/MfcQt/QT/QT5/qt5ch20/OpenCV_3.4.3-Source/modules/highgui/src/window_QT.qrc

modules/highgui/CMakeFiles/opencv_highgui.dir/src/window.cpp.obj: modules/highgui/CMakeFiles/opencv_highgui.dir/flags.make
modules/highgui/CMakeFiles/opencv_highgui.dir/src/window.cpp.obj: modules/highgui/CMakeFiles/opencv_highgui.dir/includes_CXX.rsp
modules/highgui/CMakeFiles/opencv_highgui.dir/src/window.cpp.obj: I:/charon/mydemo/measurement/MfcQt/QT/QT5/qt5ch20/OpenCV_3.4.3-Source/modules/highgui/src/window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object modules/highgui/CMakeFiles/opencv_highgui.dir/src/window.cpp.obj"
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui && D:\Qt\Tools\mingw730_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\opencv_highgui.dir\src\window.cpp.obj -c I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Source\modules\highgui\src\window.cpp

modules/highgui/CMakeFiles/opencv_highgui.dir/src/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_highgui.dir/src/window.cpp.i"
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui && D:\Qt\Tools\mingw730_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Source\modules\highgui\src\window.cpp > CMakeFiles\opencv_highgui.dir\src\window.cpp.i

modules/highgui/CMakeFiles/opencv_highgui.dir/src/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_highgui.dir/src/window.cpp.s"
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui && D:\Qt\Tools\mingw730_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Source\modules\highgui\src\window.cpp -o CMakeFiles\opencv_highgui.dir\src\window.cpp.s

modules/highgui/CMakeFiles/opencv_highgui.dir/src/roiSelector.cpp.obj: modules/highgui/CMakeFiles/opencv_highgui.dir/flags.make
modules/highgui/CMakeFiles/opencv_highgui.dir/src/roiSelector.cpp.obj: modules/highgui/CMakeFiles/opencv_highgui.dir/includes_CXX.rsp
modules/highgui/CMakeFiles/opencv_highgui.dir/src/roiSelector.cpp.obj: I:/charon/mydemo/measurement/MfcQt/QT/QT5/qt5ch20/OpenCV_3.4.3-Source/modules/highgui/src/roiSelector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object modules/highgui/CMakeFiles/opencv_highgui.dir/src/roiSelector.cpp.obj"
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui && D:\Qt\Tools\mingw730_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\opencv_highgui.dir\src\roiSelector.cpp.obj -c I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Source\modules\highgui\src\roiSelector.cpp

modules/highgui/CMakeFiles/opencv_highgui.dir/src/roiSelector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_highgui.dir/src/roiSelector.cpp.i"
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui && D:\Qt\Tools\mingw730_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Source\modules\highgui\src\roiSelector.cpp > CMakeFiles\opencv_highgui.dir\src\roiSelector.cpp.i

modules/highgui/CMakeFiles/opencv_highgui.dir/src/roiSelector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_highgui.dir/src/roiSelector.cpp.s"
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui && D:\Qt\Tools\mingw730_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Source\modules\highgui\src\roiSelector.cpp -o CMakeFiles\opencv_highgui.dir\src\roiSelector.cpp.s

modules/highgui/CMakeFiles/opencv_highgui.dir/src/window_QT.cpp.obj: modules/highgui/CMakeFiles/opencv_highgui.dir/flags.make
modules/highgui/CMakeFiles/opencv_highgui.dir/src/window_QT.cpp.obj: modules/highgui/CMakeFiles/opencv_highgui.dir/includes_CXX.rsp
modules/highgui/CMakeFiles/opencv_highgui.dir/src/window_QT.cpp.obj: I:/charon/mydemo/measurement/MfcQt/QT/QT5/qt5ch20/OpenCV_3.4.3-Source/modules/highgui/src/window_QT.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object modules/highgui/CMakeFiles/opencv_highgui.dir/src/window_QT.cpp.obj"
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui && D:\Qt\Tools\mingw730_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\opencv_highgui.dir\src\window_QT.cpp.obj -c I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Source\modules\highgui\src\window_QT.cpp

modules/highgui/CMakeFiles/opencv_highgui.dir/src/window_QT.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_highgui.dir/src/window_QT.cpp.i"
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui && D:\Qt\Tools\mingw730_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Source\modules\highgui\src\window_QT.cpp > CMakeFiles\opencv_highgui.dir\src\window_QT.cpp.i

modules/highgui/CMakeFiles/opencv_highgui.dir/src/window_QT.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_highgui.dir/src/window_QT.cpp.s"
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui && D:\Qt\Tools\mingw730_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Source\modules\highgui\src\window_QT.cpp -o CMakeFiles\opencv_highgui.dir\src\window_QT.cpp.s

modules/highgui/CMakeFiles/opencv_highgui.dir/src/moc_window_QT.cpp.obj: modules/highgui/CMakeFiles/opencv_highgui.dir/flags.make
modules/highgui/CMakeFiles/opencv_highgui.dir/src/moc_window_QT.cpp.obj: modules/highgui/CMakeFiles/opencv_highgui.dir/includes_CXX.rsp
modules/highgui/CMakeFiles/opencv_highgui.dir/src/moc_window_QT.cpp.obj: modules/highgui/src/moc_window_QT.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object modules/highgui/CMakeFiles/opencv_highgui.dir/src/moc_window_QT.cpp.obj"
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui && D:\Qt\Tools\mingw730_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\opencv_highgui.dir\src\moc_window_QT.cpp.obj -c I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui\src\moc_window_QT.cpp

modules/highgui/CMakeFiles/opencv_highgui.dir/src/moc_window_QT.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_highgui.dir/src/moc_window_QT.cpp.i"
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui && D:\Qt\Tools\mingw730_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui\src\moc_window_QT.cpp > CMakeFiles\opencv_highgui.dir\src\moc_window_QT.cpp.i

modules/highgui/CMakeFiles/opencv_highgui.dir/src/moc_window_QT.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_highgui.dir/src/moc_window_QT.cpp.s"
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui && D:\Qt\Tools\mingw730_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui\src\moc_window_QT.cpp -o CMakeFiles\opencv_highgui.dir\src\moc_window_QT.cpp.s

modules/highgui/CMakeFiles/opencv_highgui.dir/qrc_window_QT.cpp.obj: modules/highgui/CMakeFiles/opencv_highgui.dir/flags.make
modules/highgui/CMakeFiles/opencv_highgui.dir/qrc_window_QT.cpp.obj: modules/highgui/CMakeFiles/opencv_highgui.dir/includes_CXX.rsp
modules/highgui/CMakeFiles/opencv_highgui.dir/qrc_window_QT.cpp.obj: modules/highgui/qrc_window_QT.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object modules/highgui/CMakeFiles/opencv_highgui.dir/qrc_window_QT.cpp.obj"
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui && D:\Qt\Tools\mingw730_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\opencv_highgui.dir\qrc_window_QT.cpp.obj -c I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui\qrc_window_QT.cpp

modules/highgui/CMakeFiles/opencv_highgui.dir/qrc_window_QT.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_highgui.dir/qrc_window_QT.cpp.i"
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui && D:\Qt\Tools\mingw730_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui\qrc_window_QT.cpp > CMakeFiles\opencv_highgui.dir\qrc_window_QT.cpp.i

modules/highgui/CMakeFiles/opencv_highgui.dir/qrc_window_QT.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_highgui.dir/qrc_window_QT.cpp.s"
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui && D:\Qt\Tools\mingw730_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui\qrc_window_QT.cpp -o CMakeFiles\opencv_highgui.dir\qrc_window_QT.cpp.s

modules/highgui/CMakeFiles/opencv_highgui.dir/vs_version.rc.obj: modules/highgui/CMakeFiles/opencv_highgui.dir/flags.make
modules/highgui/CMakeFiles/opencv_highgui.dir/vs_version.rc.obj: modules/highgui/vs_version.rc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building RC object modules/highgui/CMakeFiles/opencv_highgui.dir/vs_version.rc.obj"
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui && D:\Qt\Tools\mingw730_32\bin\windres.exe -O coff $(RC_DEFINES) $(RC_INCLUDES) $(RC_FLAGS) I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui\vs_version.rc CMakeFiles\opencv_highgui.dir\vs_version.rc.obj

# Object files for target opencv_highgui
opencv_highgui_OBJECTS = \
"CMakeFiles/opencv_highgui.dir/src/window.cpp.obj" \
"CMakeFiles/opencv_highgui.dir/src/roiSelector.cpp.obj" \
"CMakeFiles/opencv_highgui.dir/src/window_QT.cpp.obj" \
"CMakeFiles/opencv_highgui.dir/src/moc_window_QT.cpp.obj" \
"CMakeFiles/opencv_highgui.dir/qrc_window_QT.cpp.obj" \
"CMakeFiles/opencv_highgui.dir/vs_version.rc.obj"

# External object files for target opencv_highgui
opencv_highgui_EXTERNAL_OBJECTS =

bin/libopencv_highgui343.dll: modules/highgui/CMakeFiles/opencv_highgui.dir/src/window.cpp.obj
bin/libopencv_highgui343.dll: modules/highgui/CMakeFiles/opencv_highgui.dir/src/roiSelector.cpp.obj
bin/libopencv_highgui343.dll: modules/highgui/CMakeFiles/opencv_highgui.dir/src/window_QT.cpp.obj
bin/libopencv_highgui343.dll: modules/highgui/CMakeFiles/opencv_highgui.dir/src/moc_window_QT.cpp.obj
bin/libopencv_highgui343.dll: modules/highgui/CMakeFiles/opencv_highgui.dir/qrc_window_QT.cpp.obj
bin/libopencv_highgui343.dll: modules/highgui/CMakeFiles/opencv_highgui.dir/vs_version.rc.obj
bin/libopencv_highgui343.dll: modules/highgui/CMakeFiles/opencv_highgui.dir/build.make
bin/libopencv_highgui343.dll: lib/libopencv_videoio343.dll.a
bin/libopencv_highgui343.dll: D:/Qt/5.12.2/mingw73_32/lib/libQt5Test.a
bin/libopencv_highgui343.dll: D:/Qt/5.12.2/mingw73_32/lib/libQt5Concurrent.a
bin/libopencv_highgui343.dll: D:/Qt/5.12.2/mingw73_32/lib/libQt5OpenGL.a
bin/libopencv_highgui343.dll: lib/libopencv_imgcodecs343.dll.a
bin/libopencv_highgui343.dll: lib/libopencv_imgproc343.dll.a
bin/libopencv_highgui343.dll: lib/libopencv_core343.dll.a
bin/libopencv_highgui343.dll: D:/Qt/5.12.2/mingw73_32/lib/libQt5Widgets.a
bin/libopencv_highgui343.dll: D:/Qt/5.12.2/mingw73_32/lib/libQt5Gui.a
bin/libopencv_highgui343.dll: D:/Qt/5.12.2/mingw73_32/lib/libQt5Core.a
bin/libopencv_highgui343.dll: modules/highgui/CMakeFiles/opencv_highgui.dir/linklibs.rsp
bin/libopencv_highgui343.dll: modules/highgui/CMakeFiles/opencv_highgui.dir/objects1.rsp
bin/libopencv_highgui343.dll: modules/highgui/CMakeFiles/opencv_highgui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX shared library ..\..\bin\libopencv_highgui343.dll"
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\opencv_highgui.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
modules/highgui/CMakeFiles/opencv_highgui.dir/build: bin/libopencv_highgui343.dll

.PHONY : modules/highgui/CMakeFiles/opencv_highgui.dir/build

modules/highgui/CMakeFiles/opencv_highgui.dir/clean:
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui && $(CMAKE_COMMAND) -P CMakeFiles\opencv_highgui.dir\cmake_clean.cmake
.PHONY : modules/highgui/CMakeFiles/opencv_highgui.dir/clean

modules/highgui/CMakeFiles/opencv_highgui.dir/depend: modules/highgui/src/moc_window_QT.cpp
modules/highgui/CMakeFiles/opencv_highgui.dir/depend: modules/highgui/qrc_window_QT.cpp
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Source I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Source\modules\highgui I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\modules\highgui\CMakeFiles\opencv_highgui.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : modules/highgui/CMakeFiles/opencv_highgui.dir/depend
