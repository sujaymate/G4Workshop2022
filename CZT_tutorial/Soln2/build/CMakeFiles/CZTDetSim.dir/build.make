# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/purvi/Desktop/g4_try/HEAP21

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/purvi/Desktop/g4_try/HEAP21/build

# Include any dependencies generated for this target.
include CMakeFiles/CZTDetSim.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CZTDetSim.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CZTDetSim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CZTDetSim.dir/flags.make

CMakeFiles/CZTDetSim.dir/CZTDetSim.cc.o: CMakeFiles/CZTDetSim.dir/flags.make
CMakeFiles/CZTDetSim.dir/CZTDetSim.cc.o: /home/purvi/Desktop/g4_try/HEAP21/CZTDetSim.cc
CMakeFiles/CZTDetSim.dir/CZTDetSim.cc.o: CMakeFiles/CZTDetSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/purvi/Desktop/g4_try/HEAP21/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CZTDetSim.dir/CZTDetSim.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CZTDetSim.dir/CZTDetSim.cc.o -MF CMakeFiles/CZTDetSim.dir/CZTDetSim.cc.o.d -o CMakeFiles/CZTDetSim.dir/CZTDetSim.cc.o -c /home/purvi/Desktop/g4_try/HEAP21/CZTDetSim.cc

CMakeFiles/CZTDetSim.dir/CZTDetSim.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CZTDetSim.dir/CZTDetSim.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/purvi/Desktop/g4_try/HEAP21/CZTDetSim.cc > CMakeFiles/CZTDetSim.dir/CZTDetSim.cc.i

CMakeFiles/CZTDetSim.dir/CZTDetSim.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CZTDetSim.dir/CZTDetSim.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/purvi/Desktop/g4_try/HEAP21/CZTDetSim.cc -o CMakeFiles/CZTDetSim.dir/CZTDetSim.cc.s

CMakeFiles/CZTDetSim.dir/src/CZTDetSimActionInitialization.cc.o: CMakeFiles/CZTDetSim.dir/flags.make
CMakeFiles/CZTDetSim.dir/src/CZTDetSimActionInitialization.cc.o: /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimActionInitialization.cc
CMakeFiles/CZTDetSim.dir/src/CZTDetSimActionInitialization.cc.o: CMakeFiles/CZTDetSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/purvi/Desktop/g4_try/HEAP21/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CZTDetSim.dir/src/CZTDetSimActionInitialization.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CZTDetSim.dir/src/CZTDetSimActionInitialization.cc.o -MF CMakeFiles/CZTDetSim.dir/src/CZTDetSimActionInitialization.cc.o.d -o CMakeFiles/CZTDetSim.dir/src/CZTDetSimActionInitialization.cc.o -c /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimActionInitialization.cc

CMakeFiles/CZTDetSim.dir/src/CZTDetSimActionInitialization.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CZTDetSim.dir/src/CZTDetSimActionInitialization.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimActionInitialization.cc > CMakeFiles/CZTDetSim.dir/src/CZTDetSimActionInitialization.cc.i

CMakeFiles/CZTDetSim.dir/src/CZTDetSimActionInitialization.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CZTDetSim.dir/src/CZTDetSimActionInitialization.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimActionInitialization.cc -o CMakeFiles/CZTDetSim.dir/src/CZTDetSimActionInitialization.cc.s

CMakeFiles/CZTDetSim.dir/src/CZTDetSimDetectorConstruction.cc.o: CMakeFiles/CZTDetSim.dir/flags.make
CMakeFiles/CZTDetSim.dir/src/CZTDetSimDetectorConstruction.cc.o: /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimDetectorConstruction.cc
CMakeFiles/CZTDetSim.dir/src/CZTDetSimDetectorConstruction.cc.o: CMakeFiles/CZTDetSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/purvi/Desktop/g4_try/HEAP21/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CZTDetSim.dir/src/CZTDetSimDetectorConstruction.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CZTDetSim.dir/src/CZTDetSimDetectorConstruction.cc.o -MF CMakeFiles/CZTDetSim.dir/src/CZTDetSimDetectorConstruction.cc.o.d -o CMakeFiles/CZTDetSim.dir/src/CZTDetSimDetectorConstruction.cc.o -c /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimDetectorConstruction.cc

CMakeFiles/CZTDetSim.dir/src/CZTDetSimDetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CZTDetSim.dir/src/CZTDetSimDetectorConstruction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimDetectorConstruction.cc > CMakeFiles/CZTDetSim.dir/src/CZTDetSimDetectorConstruction.cc.i

CMakeFiles/CZTDetSim.dir/src/CZTDetSimDetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CZTDetSim.dir/src/CZTDetSimDetectorConstruction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimDetectorConstruction.cc -o CMakeFiles/CZTDetSim.dir/src/CZTDetSimDetectorConstruction.cc.s

CMakeFiles/CZTDetSim.dir/src/CZTDetSimEventAction.cc.o: CMakeFiles/CZTDetSim.dir/flags.make
CMakeFiles/CZTDetSim.dir/src/CZTDetSimEventAction.cc.o: /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimEventAction.cc
CMakeFiles/CZTDetSim.dir/src/CZTDetSimEventAction.cc.o: CMakeFiles/CZTDetSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/purvi/Desktop/g4_try/HEAP21/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CZTDetSim.dir/src/CZTDetSimEventAction.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CZTDetSim.dir/src/CZTDetSimEventAction.cc.o -MF CMakeFiles/CZTDetSim.dir/src/CZTDetSimEventAction.cc.o.d -o CMakeFiles/CZTDetSim.dir/src/CZTDetSimEventAction.cc.o -c /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimEventAction.cc

CMakeFiles/CZTDetSim.dir/src/CZTDetSimEventAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CZTDetSim.dir/src/CZTDetSimEventAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimEventAction.cc > CMakeFiles/CZTDetSim.dir/src/CZTDetSimEventAction.cc.i

CMakeFiles/CZTDetSim.dir/src/CZTDetSimEventAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CZTDetSim.dir/src/CZTDetSimEventAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimEventAction.cc -o CMakeFiles/CZTDetSim.dir/src/CZTDetSimEventAction.cc.s

CMakeFiles/CZTDetSim.dir/src/CZTDetSimHit.cc.o: CMakeFiles/CZTDetSim.dir/flags.make
CMakeFiles/CZTDetSim.dir/src/CZTDetSimHit.cc.o: /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimHit.cc
CMakeFiles/CZTDetSim.dir/src/CZTDetSimHit.cc.o: CMakeFiles/CZTDetSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/purvi/Desktop/g4_try/HEAP21/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CZTDetSim.dir/src/CZTDetSimHit.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CZTDetSim.dir/src/CZTDetSimHit.cc.o -MF CMakeFiles/CZTDetSim.dir/src/CZTDetSimHit.cc.o.d -o CMakeFiles/CZTDetSim.dir/src/CZTDetSimHit.cc.o -c /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimHit.cc

CMakeFiles/CZTDetSim.dir/src/CZTDetSimHit.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CZTDetSim.dir/src/CZTDetSimHit.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimHit.cc > CMakeFiles/CZTDetSim.dir/src/CZTDetSimHit.cc.i

CMakeFiles/CZTDetSim.dir/src/CZTDetSimHit.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CZTDetSim.dir/src/CZTDetSimHit.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimHit.cc -o CMakeFiles/CZTDetSim.dir/src/CZTDetSimHit.cc.s

CMakeFiles/CZTDetSim.dir/src/CZTDetSimPhysicsList.cc.o: CMakeFiles/CZTDetSim.dir/flags.make
CMakeFiles/CZTDetSim.dir/src/CZTDetSimPhysicsList.cc.o: /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimPhysicsList.cc
CMakeFiles/CZTDetSim.dir/src/CZTDetSimPhysicsList.cc.o: CMakeFiles/CZTDetSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/purvi/Desktop/g4_try/HEAP21/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/CZTDetSim.dir/src/CZTDetSimPhysicsList.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CZTDetSim.dir/src/CZTDetSimPhysicsList.cc.o -MF CMakeFiles/CZTDetSim.dir/src/CZTDetSimPhysicsList.cc.o.d -o CMakeFiles/CZTDetSim.dir/src/CZTDetSimPhysicsList.cc.o -c /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimPhysicsList.cc

CMakeFiles/CZTDetSim.dir/src/CZTDetSimPhysicsList.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CZTDetSim.dir/src/CZTDetSimPhysicsList.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimPhysicsList.cc > CMakeFiles/CZTDetSim.dir/src/CZTDetSimPhysicsList.cc.i

CMakeFiles/CZTDetSim.dir/src/CZTDetSimPhysicsList.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CZTDetSim.dir/src/CZTDetSimPhysicsList.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimPhysicsList.cc -o CMakeFiles/CZTDetSim.dir/src/CZTDetSimPhysicsList.cc.s

CMakeFiles/CZTDetSim.dir/src/CZTDetSimPrimaryGeneratorAction.cc.o: CMakeFiles/CZTDetSim.dir/flags.make
CMakeFiles/CZTDetSim.dir/src/CZTDetSimPrimaryGeneratorAction.cc.o: /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimPrimaryGeneratorAction.cc
CMakeFiles/CZTDetSim.dir/src/CZTDetSimPrimaryGeneratorAction.cc.o: CMakeFiles/CZTDetSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/purvi/Desktop/g4_try/HEAP21/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/CZTDetSim.dir/src/CZTDetSimPrimaryGeneratorAction.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CZTDetSim.dir/src/CZTDetSimPrimaryGeneratorAction.cc.o -MF CMakeFiles/CZTDetSim.dir/src/CZTDetSimPrimaryGeneratorAction.cc.o.d -o CMakeFiles/CZTDetSim.dir/src/CZTDetSimPrimaryGeneratorAction.cc.o -c /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimPrimaryGeneratorAction.cc

CMakeFiles/CZTDetSim.dir/src/CZTDetSimPrimaryGeneratorAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CZTDetSim.dir/src/CZTDetSimPrimaryGeneratorAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimPrimaryGeneratorAction.cc > CMakeFiles/CZTDetSim.dir/src/CZTDetSimPrimaryGeneratorAction.cc.i

CMakeFiles/CZTDetSim.dir/src/CZTDetSimPrimaryGeneratorAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CZTDetSim.dir/src/CZTDetSimPrimaryGeneratorAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimPrimaryGeneratorAction.cc -o CMakeFiles/CZTDetSim.dir/src/CZTDetSimPrimaryGeneratorAction.cc.s

CMakeFiles/CZTDetSim.dir/src/CZTDetSimRunAction.cc.o: CMakeFiles/CZTDetSim.dir/flags.make
CMakeFiles/CZTDetSim.dir/src/CZTDetSimRunAction.cc.o: /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimRunAction.cc
CMakeFiles/CZTDetSim.dir/src/CZTDetSimRunAction.cc.o: CMakeFiles/CZTDetSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/purvi/Desktop/g4_try/HEAP21/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/CZTDetSim.dir/src/CZTDetSimRunAction.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CZTDetSim.dir/src/CZTDetSimRunAction.cc.o -MF CMakeFiles/CZTDetSim.dir/src/CZTDetSimRunAction.cc.o.d -o CMakeFiles/CZTDetSim.dir/src/CZTDetSimRunAction.cc.o -c /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimRunAction.cc

CMakeFiles/CZTDetSim.dir/src/CZTDetSimRunAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CZTDetSim.dir/src/CZTDetSimRunAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimRunAction.cc > CMakeFiles/CZTDetSim.dir/src/CZTDetSimRunAction.cc.i

CMakeFiles/CZTDetSim.dir/src/CZTDetSimRunAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CZTDetSim.dir/src/CZTDetSimRunAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimRunAction.cc -o CMakeFiles/CZTDetSim.dir/src/CZTDetSimRunAction.cc.s

CMakeFiles/CZTDetSim.dir/src/CZTDetSimSD.cc.o: CMakeFiles/CZTDetSim.dir/flags.make
CMakeFiles/CZTDetSim.dir/src/CZTDetSimSD.cc.o: /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimSD.cc
CMakeFiles/CZTDetSim.dir/src/CZTDetSimSD.cc.o: CMakeFiles/CZTDetSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/purvi/Desktop/g4_try/HEAP21/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/CZTDetSim.dir/src/CZTDetSimSD.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CZTDetSim.dir/src/CZTDetSimSD.cc.o -MF CMakeFiles/CZTDetSim.dir/src/CZTDetSimSD.cc.o.d -o CMakeFiles/CZTDetSim.dir/src/CZTDetSimSD.cc.o -c /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimSD.cc

CMakeFiles/CZTDetSim.dir/src/CZTDetSimSD.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CZTDetSim.dir/src/CZTDetSimSD.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimSD.cc > CMakeFiles/CZTDetSim.dir/src/CZTDetSimSD.cc.i

CMakeFiles/CZTDetSim.dir/src/CZTDetSimSD.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CZTDetSim.dir/src/CZTDetSimSD.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/purvi/Desktop/g4_try/HEAP21/src/CZTDetSimSD.cc -o CMakeFiles/CZTDetSim.dir/src/CZTDetSimSD.cc.s

# Object files for target CZTDetSim
CZTDetSim_OBJECTS = \
"CMakeFiles/CZTDetSim.dir/CZTDetSim.cc.o" \
"CMakeFiles/CZTDetSim.dir/src/CZTDetSimActionInitialization.cc.o" \
"CMakeFiles/CZTDetSim.dir/src/CZTDetSimDetectorConstruction.cc.o" \
"CMakeFiles/CZTDetSim.dir/src/CZTDetSimEventAction.cc.o" \
"CMakeFiles/CZTDetSim.dir/src/CZTDetSimHit.cc.o" \
"CMakeFiles/CZTDetSim.dir/src/CZTDetSimPhysicsList.cc.o" \
"CMakeFiles/CZTDetSim.dir/src/CZTDetSimPrimaryGeneratorAction.cc.o" \
"CMakeFiles/CZTDetSim.dir/src/CZTDetSimRunAction.cc.o" \
"CMakeFiles/CZTDetSim.dir/src/CZTDetSimSD.cc.o"

# External object files for target CZTDetSim
CZTDetSim_EXTERNAL_OBJECTS =

CZTDetSim: CMakeFiles/CZTDetSim.dir/CZTDetSim.cc.o
CZTDetSim: CMakeFiles/CZTDetSim.dir/src/CZTDetSimActionInitialization.cc.o
CZTDetSim: CMakeFiles/CZTDetSim.dir/src/CZTDetSimDetectorConstruction.cc.o
CZTDetSim: CMakeFiles/CZTDetSim.dir/src/CZTDetSimEventAction.cc.o
CZTDetSim: CMakeFiles/CZTDetSim.dir/src/CZTDetSimHit.cc.o
CZTDetSim: CMakeFiles/CZTDetSim.dir/src/CZTDetSimPhysicsList.cc.o
CZTDetSim: CMakeFiles/CZTDetSim.dir/src/CZTDetSimPrimaryGeneratorAction.cc.o
CZTDetSim: CMakeFiles/CZTDetSim.dir/src/CZTDetSimRunAction.cc.o
CZTDetSim: CMakeFiles/CZTDetSim.dir/src/CZTDetSimSD.cc.o
CZTDetSim: CMakeFiles/CZTDetSim.dir/build.make
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4Tree.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4FR.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4GMocren.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4visHepRep.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4RayTracer.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4VRML.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4OpenGL.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4gl2ps.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4vis_management.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4modeling.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4interfaces.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4persistency.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4error_propagation.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4readout.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4physicslists.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4tasking.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4parmodels.so
CZTDetSim: /usr/lib/x86_64-linux-gnu/libGL.so
CZTDetSim: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.9.5
CZTDetSim: /usr/lib/x86_64-linux-gnu/libQt5PrintSupport.so.5.9.5
CZTDetSim: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.9.5
CZTDetSim: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.9.5
CZTDetSim: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.9.5
CZTDetSim: /usr/lib/x86_64-linux-gnu/libXmu.so
CZTDetSim: /usr/lib/x86_64-linux-gnu/libXext.so
CZTDetSim: /usr/lib/x86_64-linux-gnu/libXt.so
CZTDetSim: /usr/lib/x86_64-linux-gnu/libICE.so
CZTDetSim: /usr/lib/x86_64-linux-gnu/libSM.so
CZTDetSim: /usr/lib/x86_64-linux-gnu/libX11.so
CZTDetSim: /usr/lib/x86_64-linux-gnu/libxerces-c.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4run.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4event.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4tracking.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4processes.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4analysis.so
CZTDetSim: /usr/lib/x86_64-linux-gnu/libexpat.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4digits_hits.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4track.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4particles.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4geometry.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4materials.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4zlib.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4graphics_reps.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4intercoms.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4global.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4clhep.so
CZTDetSim: /home/purvi/geant4/geant4.10.07.p04-install/lib/libG4ptl.so.0.0.2
CZTDetSim: CMakeFiles/CZTDetSim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/purvi/Desktop/g4_try/HEAP21/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable CZTDetSim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CZTDetSim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CZTDetSim.dir/build: CZTDetSim
.PHONY : CMakeFiles/CZTDetSim.dir/build

CMakeFiles/CZTDetSim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CZTDetSim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CZTDetSim.dir/clean

CMakeFiles/CZTDetSim.dir/depend:
	cd /home/purvi/Desktop/g4_try/HEAP21/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/purvi/Desktop/g4_try/HEAP21 /home/purvi/Desktop/g4_try/HEAP21 /home/purvi/Desktop/g4_try/HEAP21/build /home/purvi/Desktop/g4_try/HEAP21/build /home/purvi/Desktop/g4_try/HEAP21/build/CMakeFiles/CZTDetSim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CZTDetSim.dir/depend

