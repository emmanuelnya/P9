# CMake generated Testfile for 
# Source directory: C:/Users/emman/CLionProjects/P9
# Build directory: C:/Users/emman/CLionProjects/P9/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[UnitTests]=] "C:/Users/emman/CLionProjects/P9/cmake-build-debug/P9_tests.exe")
set_tests_properties([=[UnitTests]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/emman/CLionProjects/P9/CMakeLists.txt;24;add_test;C:/Users/emman/CLionProjects/P9/CMakeLists.txt;0;")
subdirs("lib/googletest")
