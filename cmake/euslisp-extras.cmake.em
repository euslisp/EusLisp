# euslisp.cmake
@[if DEVELSPACE]@
set(EUSDIR @(PROJECT_SOURCE_DIR))
@[else]@
set(EUSDIR @(CMAKE_INSTALL_PREFIX)/@(CATKIN_PACKAGE_SHARE_DESTINATION))
@[end if]@
set(ARCHDIR @{import os; print(os.environ['ARCHDIR']),})
set(euslisp_INCLUDE_DIRS ${EUSDIR}/include)
message(STATUS "set EUSDIR to ${EUSDIR}")
message(STATUS "set ARCHDIR to ${ARCHDIR}")
message(STATUS "set euslisp_INCLUDE_DIRS to ${euslisp_INCLUDE_DIRS}")

