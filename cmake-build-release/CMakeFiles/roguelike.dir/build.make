# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\mrnos\CLionProjects\roguelike

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\mrnos\CLionProjects\roguelike\cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/roguelike.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/roguelike.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/roguelike.dir/flags.make

CMakeFiles/roguelike.dir/main.cpp.obj: CMakeFiles/roguelike.dir/flags.make
CMakeFiles/roguelike.dir/main.cpp.obj: CMakeFiles/roguelike.dir/includes_CXX.rsp
CMakeFiles/roguelike.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mrnos\CLionProjects\roguelike\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/roguelike.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\roguelike.dir\main.cpp.obj -c C:\Users\mrnos\CLionProjects\roguelike\main.cpp

CMakeFiles/roguelike.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roguelike.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mrnos\CLionProjects\roguelike\main.cpp > CMakeFiles\roguelike.dir\main.cpp.i

CMakeFiles/roguelike.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roguelike.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mrnos\CLionProjects\roguelike\main.cpp -o CMakeFiles\roguelike.dir\main.cpp.s

CMakeFiles/roguelike.dir/GameTile.cpp.obj: CMakeFiles/roguelike.dir/flags.make
CMakeFiles/roguelike.dir/GameTile.cpp.obj: CMakeFiles/roguelike.dir/includes_CXX.rsp
CMakeFiles/roguelike.dir/GameTile.cpp.obj: ../GameTile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mrnos\CLionProjects\roguelike\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/roguelike.dir/GameTile.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\roguelike.dir\GameTile.cpp.obj -c C:\Users\mrnos\CLionProjects\roguelike\GameTile.cpp

CMakeFiles/roguelike.dir/GameTile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roguelike.dir/GameTile.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mrnos\CLionProjects\roguelike\GameTile.cpp > CMakeFiles\roguelike.dir\GameTile.cpp.i

CMakeFiles/roguelike.dir/GameTile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roguelike.dir/GameTile.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mrnos\CLionProjects\roguelike\GameTile.cpp -o CMakeFiles\roguelike.dir\GameTile.cpp.s

CMakeFiles/roguelike.dir/GameWorld.cpp.obj: CMakeFiles/roguelike.dir/flags.make
CMakeFiles/roguelike.dir/GameWorld.cpp.obj: CMakeFiles/roguelike.dir/includes_CXX.rsp
CMakeFiles/roguelike.dir/GameWorld.cpp.obj: ../GameWorld.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mrnos\CLionProjects\roguelike\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/roguelike.dir/GameWorld.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\roguelike.dir\GameWorld.cpp.obj -c C:\Users\mrnos\CLionProjects\roguelike\GameWorld.cpp

CMakeFiles/roguelike.dir/GameWorld.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roguelike.dir/GameWorld.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mrnos\CLionProjects\roguelike\GameWorld.cpp > CMakeFiles\roguelike.dir\GameWorld.cpp.i

CMakeFiles/roguelike.dir/GameWorld.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roguelike.dir/GameWorld.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mrnos\CLionProjects\roguelike\GameWorld.cpp -o CMakeFiles\roguelike.dir\GameWorld.cpp.s

CMakeFiles/roguelike.dir/Character.cpp.obj: CMakeFiles/roguelike.dir/flags.make
CMakeFiles/roguelike.dir/Character.cpp.obj: CMakeFiles/roguelike.dir/includes_CXX.rsp
CMakeFiles/roguelike.dir/Character.cpp.obj: ../Character.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mrnos\CLionProjects\roguelike\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/roguelike.dir/Character.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\roguelike.dir\Character.cpp.obj -c C:\Users\mrnos\CLionProjects\roguelike\Character.cpp

CMakeFiles/roguelike.dir/Character.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roguelike.dir/Character.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mrnos\CLionProjects\roguelike\Character.cpp > CMakeFiles\roguelike.dir\Character.cpp.i

CMakeFiles/roguelike.dir/Character.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roguelike.dir/Character.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mrnos\CLionProjects\roguelike\Character.cpp -o CMakeFiles\roguelike.dir\Character.cpp.s

CMakeFiles/roguelike.dir/otrisovka.cpp.obj: CMakeFiles/roguelike.dir/flags.make
CMakeFiles/roguelike.dir/otrisovka.cpp.obj: CMakeFiles/roguelike.dir/includes_CXX.rsp
CMakeFiles/roguelike.dir/otrisovka.cpp.obj: ../otrisovka.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mrnos\CLionProjects\roguelike\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/roguelike.dir/otrisovka.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\roguelike.dir\otrisovka.cpp.obj -c C:\Users\mrnos\CLionProjects\roguelike\otrisovka.cpp

CMakeFiles/roguelike.dir/otrisovka.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roguelike.dir/otrisovka.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mrnos\CLionProjects\roguelike\otrisovka.cpp > CMakeFiles\roguelike.dir\otrisovka.cpp.i

CMakeFiles/roguelike.dir/otrisovka.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roguelike.dir/otrisovka.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mrnos\CLionProjects\roguelike\otrisovka.cpp -o CMakeFiles\roguelike.dir\otrisovka.cpp.s

# Object files for target roguelike
roguelike_OBJECTS = \
"CMakeFiles/roguelike.dir/main.cpp.obj" \
"CMakeFiles/roguelike.dir/GameTile.cpp.obj" \
"CMakeFiles/roguelike.dir/GameWorld.cpp.obj" \
"CMakeFiles/roguelike.dir/Character.cpp.obj" \
"CMakeFiles/roguelike.dir/otrisovka.cpp.obj"

# External object files for target roguelike
roguelike_EXTERNAL_OBJECTS =

roguelike.exe: CMakeFiles/roguelike.dir/main.cpp.obj
roguelike.exe: CMakeFiles/roguelike.dir/GameTile.cpp.obj
roguelike.exe: CMakeFiles/roguelike.dir/GameWorld.cpp.obj
roguelike.exe: CMakeFiles/roguelike.dir/Character.cpp.obj
roguelike.exe: CMakeFiles/roguelike.dir/otrisovka.cpp.obj
roguelike.exe: CMakeFiles/roguelike.dir/build.make
roguelike.exe: C:/Libraries/SFML/lib/libsfml-graphics-s.a
roguelike.exe: C:/Libraries/SFML/lib/libsfml-audio-s.a
roguelike.exe: C:/Libraries/SFML/lib/libsfml-window-s.a
roguelike.exe: C:/Libraries/SFML/lib/libfreetype.a
roguelike.exe: C:/Libraries/SFML/lib/libopenal32.a
roguelike.exe: C:/Libraries/SFML/lib/libsfml-system-s.a
roguelike.exe: C:/Libraries/SFML/lib/libvorbisfile.a
roguelike.exe: C:/Libraries/SFML/lib/libvorbisenc.a
roguelike.exe: C:/Libraries/SFML/lib/libvorbis.a
roguelike.exe: C:/Libraries/SFML/lib/libogg.a
roguelike.exe: C:/Libraries/SFML/lib/libFLAC.a
roguelike.exe: CMakeFiles/roguelike.dir/linklibs.rsp
roguelike.exe: CMakeFiles/roguelike.dir/objects1.rsp
roguelike.exe: CMakeFiles/roguelike.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\mrnos\CLionProjects\roguelike\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable roguelike.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\roguelike.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/roguelike.dir/build: roguelike.exe

.PHONY : CMakeFiles/roguelike.dir/build

CMakeFiles/roguelike.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\roguelike.dir\cmake_clean.cmake
.PHONY : CMakeFiles/roguelike.dir/clean

CMakeFiles/roguelike.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\mrnos\CLionProjects\roguelike C:\Users\mrnos\CLionProjects\roguelike C:\Users\mrnos\CLionProjects\roguelike\cmake-build-release C:\Users\mrnos\CLionProjects\roguelike\cmake-build-release C:\Users\mrnos\CLionProjects\roguelike\cmake-build-release\CMakeFiles\roguelike.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/roguelike.dir/depend
