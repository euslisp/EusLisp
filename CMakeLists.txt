# http://ros.org/doc/groovy/api/catkin/html/user_guide/supposed.html
cmake_minimum_required(VERSION 2.8.3)
project(euslisp)

# check arch and os
execute_process(COMMAND bash -c "gcc -dumpmachine" OUTPUT_VARIABLE gcc_dump_machine OUTPUT_STRIP_TRAILING_WHITESPACE)
message("-- gcc dumpmachine returns ${gcc_dump_machine}")
if(gcc_dump_machine MATCHES "x86_64-linux-.*" OR gcc_dump_machine MATCHES "x86_64-redhat-linux")
  set(ARCHDIR "Linux64")
  set(MAKEFILE "Makefile.Linux64")
elseif(gcc_dump_machine MATCHES "i686-linux-.*" OR gcc_dump_machine MATCHES "i686-redhat-linux")
  set(ARCHDIR "Linux")
  set(MAKEFILE "Makefile.Linux.thread")
elseif(gcc_dump_machine MATCHES "arm.*-.*")
  set(ARCHDIR "LinuxARM")
  set(MAKEFILE "Makefile.LinuxARM")
elseif(gcc_dump_machine MATCHES "aarch64.*-.*")
  set(ARCHDIR "LinuxARM")
  set(MAKEFILE "Makefile.LinuxARM")
elseif(gcc_dump_machine MATCHES "cygwin.*-.*")
  set(ARCHDIR "Cygwin")
  set(MAKEFILE "Makefile.Cygwin")
elseif(gcc_dump_machine MATCHES ".*darwin.*")
  set(ARCHDIR "Darwin")
  set(MAKEFILE "Makefile.Darwin")
else()
  message(FATAL_ERROR "-- -- This machine is not supported")
endif()
message(STATUS "ARCHDIR  : ${ARCHDIR}")
message(STATUS "MAKEFILE : ${MAKEFILE}")

# build euslisp
add_custom_command(OUTPUT ${PROJECT_SOURCE_DIR}/lisp/Makefile
  COMMAND cmake -E create_symlink ${MAKEFILE} Makefile
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/lisp/)
add_custom_target(compile_euslisp
  DEPENDS ${PROJECT_SOURCE_DIR}/lisp/Makefile
  COMMAND export EUSDIR=${PROJECT_SOURCE_DIR} lt_cv_sys_lib_dlsearch_path_spec=${lt_cv_sys_lib_dlsearch_path_spec} LD_LIBRARY_PATH=${PROJECT_SOURCE_DIR}/${ARCHDIR}/lib:\$LD_LIBRARY_PATH && \$\(MAKE\) -C ${PROJECT_SOURCE_DIR}/lisp -f Makefile EUSRPATH=)
add_custom_target(clean_euslisp
  DEPENDS compile_euslisp
  COMMAND sh tool/clean-ch.sh
  COMMAND rm -f l/constants.l.[co] l/eusstart.l.[co] comp/builtins.l.[co] c/makedate.c
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/lisp)
add_custom_target(doc_euslisp
  DEPENDS compile_euslisp
  COMMAND make -C latex  manual clean
  COMMAND make -C jlatex all clean
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/doc)
add_custom_target(build_euslisp ALL
  DEPENDS compile_euslisp doc_euslisp
  clean_euslisp)

# catkin
find_package(catkin)
set(ENV{ARCHDIR} ${ARCHDIR}) ## for add_env_hook
catkin_package(CFG_EXTRAS euslisp-extras.cmake)
catkin_add_env_hooks(99.euslisp SHELLS sh DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/env-hooks)

# install
install(DIRECTORY contrib lib lisp models ${ARCHDIR}
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  USE_SOURCE_PERMISSIONS)
install(CODE "message(STATUS \"execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink lisp/c include WORKING_DIRECTORY \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/${CATKIN_PACKAGE_SHARE_DESTINATION})\")")
install(CODE "execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink lisp/c include WORKING_DIRECTORY \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/${CATKIN_PACKAGE_SHARE_DESTINATION})")
install(CODE "execute_process(COMMAND make html WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/doc/latex)")
install(CODE "execute_process(COMMAND make html WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/doc/jlatex)")
install(DIRECTORY doc
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  USE_SOURCE_PERMISSIONS
  FILES_MATCHING PATTERN "doc/*/*.{pdf,hlp}"
  PATTERN "doc/html/*"
  PATTERN "doc/algorithm" EXCLUDE
  PATTERN "licence-old" EXCLUDE
  PATTERN "doc/mails" EXCLUDE
  PATTERN "doc/hirukawa" EXCLUDE
  PATTERN "doc/help.cltl" EXCLUDE
  PATTERN "doc/help.eus" EXCLUDE
  PATTERN "doc/publications" EXCLUDE
  PATTERN "doc/latex/fig" EXCLUDE
  PATTERN "doc/jlatex/fig" EXCLUDE
  )
