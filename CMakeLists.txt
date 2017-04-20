# http://ros.org/doc/groovy/api/catkin/html/user_guide/supposed.html
cmake_minimum_required(VERSION 2.8.3)
project(euslisp)

find_package(catkin)

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

# build euslisp
add_custom_command(OUTPUT ${PROJECT_SOURCE_DIR}/lisp/Makefile
  COMMAND cmake -E create_symlink ${MAKEFILE} Makefile
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/lisp/)
add_custom_target(compile_euslisp ALL
  DEPENDS ${PROJECT_SOURCE_DIR}/lisp/Makefile
  COMMAND export EUSDIR=${PROJECT_SOURCE_DIR} lt_cv_sys_lib_dlsearch_path_spec=${lt_cv_sys_lib_dlsearch_path_spec} LD_LIBRARY_PATH=${PROJECT_SOURCE_DIR}/${ARCHDIR}/lib:\$LD_LIBRARY_PATH && \$\(MAKE\) -C ${PROJECT_SOURCE_DIR}/lisp -f Makefile EUSRPATH=)

add_custom_target(install_euslisp
  COMMAND export EUSDIR=${PROJECT_SOURCE_DIR} lt_cv_sys_lib_dlsearch_path_spec=${lt_cv_sys_lib_dlsearch_path_spec} LD_LIBRARY_PATH=${PROJECT_SOURCE_DIR}/${ARCHDIR}/lib:\$LD_LIBRARY_PATH && ${CMAKE_COMMAND} -E make_directory \${DESTDIR}${CMAKE_INSTALL_PREFIX}/bin && \$\(MAKE\) -C ${PROJECT_SOURCE_DIR}/lisp -f Makefile install PUBBINDIR=\${DESTDIR}${CMAKE_INSTALL_PREFIX}/bin)

install(CODE "execute_process(COMMAND ${CMAKE_COMMAND} --build . --target install_euslisp)")
install(DIRECTORY contrib lib lisp models ${ARCHDIR}
  DESTINATION share/euslisp/jskeus/eus/
  USE_SOURCE_PERMISSIONS)
install(DIRECTORY doc
  DESTINATION share/euslisp/jskeus/eus/
  USE_SOURCE_PERMISSIONS
  PATTERN "doc/html" EXCLUDE
  PATTERN "doc/mails" EXCLUDE
  PATTERN "doc/hirukawa" EXCLUDE
  PATTERN "doc/help.cltl" EXCLUDE
  PATTERN "doc/publications" EXCLUDE
  PATTERN "doc/latex/fig" EXCLUDE
  PATTERN "doc/jlatex/fig" EXCLUDE
  )
install(FILES package.xml DESTINATION share/euslisp/)
install(CODE "execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink lisp/c include WORKING_DIRECTORY \$ENV{DESTDIR}\${CMAKE_INSTALL_PREFIX}/share/euslisp/jskeus/eus/)")

catkin_package(CFG_EXTRAS euslisp-extras.cmake)
catkin_add_env_hooks(99.euslisp SHELLS sh DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/env-hooks)

string(REGEX MATCH "catkin" need_catkin "$ENV{_}")
get_filename_component(install_dir_name ${CMAKE_INSTALL_PREFIX} NAME)
if(need_catkin AND NOT install_dir_name MATCHES "install") # check if  install_prefix end with /install, we can  remove this section of we remove all rosrun euslisp ... usage
  install(CODE "
## this is tricky force write catkin marker file
set(_catkin_marker_file \"\${CMAKE_INSTALL_PREFIX}/.catkin\")
# check if the develspace marker file exists yet
if(EXISTS \${_catkin_marker_file})
  file(READ \${_catkin_marker_file} _existing_sourcespaces)
  if(_existing_sourcespaces STREQUAL \"\")
    # write this sourcespace to the marker file
    file(WRITE \${_catkin_marker_file} \"${CMAKE_INSTALL_PREFIX}/${CATKIN_PACKAGE_SHARE_DESTINATION}\")
  else()
    # append to existing list of sourcespaces if it's not in the list
    list(FIND _existing_sourcespaces \"${CMAKE_INSTALL_PREFIX}/${CATKIN_PACKAGE_SHARE_DESTINATION}\" _existing_sourcespace_index)
    if(_existing_sourcespace_index EQUAL -1)
      file(APPEND \${_catkin_marker_file} \";${CMAKE_INSTALL_PREFIX}/${CATKIN_PACKAGE_SHARE_DESTINATION}\")
    endif()
  endif()
else()
  # create a new develspace marker file
  # NOTE: extra care must be taken when running multiple catkin jobs in parallel 
  #       so that this does not overwrite the result of a similar call in another package
  file(WRITE \${_catkin_marker_file} \"${CMAKE_INSTALL_PREFIX}/${CATKIN_PACKAGE_SHARE_DESTINATION}\")
endif()
")
endif()
