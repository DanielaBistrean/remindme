cmake_minimum_required (VERSION 2.8.11)
project (RemindMe)

find_package(PkgConfig)
pkg_check_modules(LIBNOTIFY QUIET libnotify)

find_path(LIBNOTIFY_INCLUDE_DIRS
    NAMES notify.h
    HINTS ${LIBNOTIFY_INCLUDEDIR}
          ${LIBNOTIFY_INCLUDE_DIRS}
    PATH_SUFFIXES libnotify
)

find_library(LIBNOTIFY_LIBRARIES
    NAMES notify
    HINTS ${LIBNOTIFY_LIBDIR}
          ${LIBNOTIFY_LIBRARY_DIRS}
)

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(LibNotify REQUIRED_VARS LIBNOTIFY_INCLUDE_DIRS LIBNOTIFY_LIBRARIES
                                            VERSION_VAR   LIBNOTIFY_VERSION)

mark_as_advanced(
    LIBNOTIFY_INCLUDE_DIRS
    LIBNOTIFY_LIBRARIES
)

set (SOURCES
	main.cpp
	notification.cc
	notification_service.cc
	reminder.cc
	timer.cc
    reminder_manager.cc
)

add_executable (RemindMe ${SOURCES})
target_include_directories (RemindMe PUBLIC ${LIBNOTIFY_INCLUDE_DIRS})
target_link_libraries (RemindMe rt ${LIBNOTIFY_LIBRARIES})
