cmake_minimum_required(VERSION 3.10)

project(SHBrwoser)
set(CMAKE_VERBOSE_MAKEFILE ON)



FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)
PKG_CHECK_MODULES(GTKMM gtkmm-3.0)
set(PORT GTK)

add_subdirectory(WebKit)

set(SHBROWSER_SOURCES src/main.cpp)

set(WEBKIT_LIBRARIES 
	libwebkit2gtk-4.0.so
	)

set(WEBKIT_INCLUDES
	"WebKit/DerivedSources/ForwardingHeaders/webkit2gtk"
	"WebKit/DerivedSources/ForwardingHeaders"
	"WebKit/DerivedSources/JavaScriptCore/javascriptcoregtk"
	"WebKit/DerivedSources/ForwardingHeaders/JavaScriptCore/glib"
	"/usr/include/libsoup-2.4"
	"WebKit/DerivedSources/webkit2gtk"
	)
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(WebKit/Source)
INCLUDE_DIRECTORIES(${WEBKIT_INCLUDES})
INCLUDE_DIRECTORIES(${GTKMM_INCLUDE_DIRS})

LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})
LINK_DIRECTORIES(${GTKMM_LIBRARY_DIRS})
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHR})
LINK_DIRECTORIES(WebKit/lib)
set(EXECUTABLE_OUTPUT_PATH build/)
file(MAKE_DIRECTORY build)
ADD_EXECUTABLE(out ${SHBROWSER_SOURCES})
TARGET_LINK_LIBRARIES(out ${GTK3_LIBRARIES})
TARGET_LINK_LIBRARIES(out ${WEBKIT_LIBRARIES})
TARGET_LINK_LIBRARIES(out WebKit)
target_link_libraries(out ${GTKMM_LIBRARIES})
