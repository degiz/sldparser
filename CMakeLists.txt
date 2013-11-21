cmake_minimum_required(VERSION 2.8)
PROJECT(sldparser)

SET(SLD_PARSER_BIN_DIR ${CMAKE_CURRENT_BINARY_DIR})
SET(SLD_PARSER_OUTPUT_NAME ${CMAKE_PROJECT_NAME})

FIND_PACKAGE(LibXml2) 
 
ADD_SUBDIRECTORY(test)

INCLUDE_DIRECTORIES("include" "src/include" "src/include/filters" ${LIBXML2_INCLUDE_DIR} )

FILE(GLOB HEADERS "include/*.h" "src/include/*.h")
FILE(GLOB FILTERS_H "src/include/filters/*.h")
FILE(GLOB SOURCES "src/src/*.cpp")
FILE(GLOB FILTERS_SRC "src/src/filters/*.cpp")

source_group(Headers\\Parser FILES ${HEADERS})
source_group(Headers\\Filters FILES ${FILTERS_H})

source_group(Source\\Parser FILES ${SOURCES})
source_group(Source\\Filters FILES ${FILTERS_SRC})

ADD_LIBRARY(sldparser ${HEADERS} ${FILTERS_H} ${SOURCES} ${FILTERS_SRC})
TARGET_LINK_LIBRARIES(sldparser ${LIBXML2_LIBRARIES} )