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
include apps/visualisation/CMakeFiles/opencv_visualisation.dir/depend.make

# Include the progress variables for this target.
include apps/visualisation/CMakeFiles/opencv_visualisation.dir/progress.make

# Include the compile flags for this target's objects.
include apps/visualisation/CMakeFiles/opencv_visualisation.dir/flags.make

apps/visualisation/CMakeFiles/opencv_visualisation.dir/opencv_visualisation.cpp.obj: apps/visualisation/CMakeFiles/opencv_visualisation.dir/flags.make
apps/visualisation/CMakeFiles/opencv_visualisation.dir/opencv_visualisation.cpp.obj: apps/visualisation/CMakeFiles/opencv_visualisation.dir/includes_CXX.rsp
apps/visualisation/CMakeFiles/opencv_visualisation.dir/opencv_visualisation.cpp.obj: I:/charon/mydemo/measurement/MfcQt/QT/QT5/qt5ch20/OpenCV_3.4.3-Source/apps/visualisation/opencv_visualisation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object apps/visualisation/CMakeFiles/opencv_visualisation.dir/opencv_visualisation.cpp.obj"
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\apps\visualisation && D:\Qt\Tools\mingw730_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\opencv_visualisation.dir\opencv_visualisation.cpp.obj -c I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Source\apps\visualisation\opencv_visualisation.cpp

apps/visualisation/CMakeFiles/opencv_visualisation.dir/opencv_visualisation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_visualisation.dir/opencv_visualisation.cpp.i"
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\apps\visualisation && D:\Qt\Tools\mingw730_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Source\apps\visualisation\opencv_visualisation.cpp > CMakeFiles\opencv_visualisation.dir\opencv_visualisation.cpp.i

apps/visualisation/CMakeFiles/opencv_visualisation.dir/opencv_visualisation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_visualisation.dir/opencv_visualisation.cpp.s"
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\apps\visualisation && D:\Qt\Tools\mingw730_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Source\apps\visualisation\opencv_visualisation.cpp -o CMakeFiles\opencv_visualisation.dir\opencv_visualisation.cpp.s

# Object files for target opencv_visualisation
opencv_visualisation_OBJECTS = \
"CMakeFiles/opencv_visualisation.dir/opencv_visualisation.cpp.obj"

# External object files for target opencv_visualisation
opencv_visualisation_EXTERNAL_OBJECTS =

bin/opencv_visualisation.exe: apps/visualisation/CMakeFiles/opencv_visualisation.dir/opencv_visualisation.cpp.obj
bin/opencv_visualisation.exe: apps/visualisation/CMakeFiles/opencv_visualisation.dir/build.make
bin/opencv_visualisation.exe: lib/libopencv_highgui343.dll.a
bin/opencv_visualisation.exe: lib/libopencv_videoio343.dll.a
bin/opencv_visualisation.exe: lib/libopencv_imgcodecs343.dll.a
bin/opencv_visualisation.exe: lib/libopencv_imgproc343.dll.a
bin/opencv_visualisation.exe: lib/libopencv_core343.dll.a
bin/opencv_visualisation.exe: apps/visualisation/CMakeFiles/opencv_visualisation.dir/linklibs.rsp
bin/opencv_visualisation.exe: apps/visualisation/CMakeFiles/opencv_visualisation.dir/objects1.rsp
bin/opencv_visualisation.exe: apps/visualisation/CMakeFiles/opencv_visualisation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\..\bin\opencv_visualisation.exe"
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\apps\visualisation && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\opencv_visualisation.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
apps/visualisation/CMakeFiles/opencv_visualisation.dir/build: bin/opencv_visualisation.exe

.PHONY : apps/visualisation/CMakeFiles/opencv_visualisation.dir/build

apps/visualisation/CMakeFiles/opencv_visualisation.dir/clean:
	cd /d I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\apps\visualisation && $(CMAKE_COMMAND) -P CMakeFiles\opencv_visualisation.dir\cmake_clean.cmake
.PHONY : apps/visualisation/CMakeFiles/opencv_visualisation.dir/clean

apps/visualisation/CMakeFiles/opencv_visualisation.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Source I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Source\apps\visualisation I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\apps\visualisation I:\charon\mydemo\measurement\MfcQt\QT\QT5\qt5ch20\OpenCV_3.4.3-Build\apps\visualisation\CMakeFiles\opencv_visualisation.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : apps/visualisation/CMakeFiles/opencv_visualisation.dir/depend

