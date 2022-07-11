cmake_minimum_required(VERSION 3.0)

project(CIA VERSION 0.1)

set(JAVA_AWT_LIBRARY "C:\\Program Files\\Java\\jdk-18.0.1.1\\lib\\jawt.lib")
set(JAVA_JVM_LIBRARY "C:\\Program Files\\Java\\jdk-18.0.1.1\\lib\\jvm.lib")

set(JAVA_AWT_INCLUDE_PATH "C:\\Program Files\\Java\\jdk-18.0.1.1\\include")
set(JAVA_INCLUDE_PATH "C:\\Program Files\\Java\\jdk-18.0.1.1\\include")
set(JAVA_INCLUDE_PATH2 "C:\\Program Files\\Java\\jdk-18.0.1.1\\include\\win32")

find_package(JNI REQUIRED)

if (NOT DEFINED SOURCES)
	file(GLOB_RECURSE CIA_SOURCE src/*.*)
endif ()

source_group("Source Files" FILES ${CIA_SOURCE})

add_library(CIA SHARED ${CIA_SOURCE})