cmake_minimum_required(VERSION 2.8)
PROJECT(automapd_sld)

FIND_PACKAGE(LibXml2) 

INCLUDE_DIRECTORIES("include" ${LIBXML2_INCLUDE_DIR} )

FILE(GLOB HEADERS "include/*.h")
FILE(GLOB SOURCES "src/*.cpp")

ADD_LIBRARY(automapd_sld ${HEADERS} ${SOURCES} )
TARGET_LINK_LIBRARIES(automapd_sld ${LIBXML2_LIBRARIES} )