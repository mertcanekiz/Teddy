SET(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11")
FILE(GLOB SRCS main.cc
			   engine/*.cc
			   engine/*.h
			   engine/game/*.cc
			   engine/game/*.h
			   engine/graphics/*.cc
			   engine/graphics/*.h
			   engine/util/*.cc
			   engine/util/*.h
	)
ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})
SET(CMAKE_DIR "../cmake")
FIND_PACKAGE(OpenGL REQUIRED)
FIND_PACKAGE(GLEW REQUIRED)
INCLUDE(${CMAKE_DIR}/FindSDL2.cmake)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${GLEW_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${SDL2_LIBRARIES} )
