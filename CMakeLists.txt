cmake_minimum_required(VERSION 3.16)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Create symlink to compile_commands.json for IDE to pick it up
execute_process(
COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
)

project(Client)
project(Server)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# This assumes the SDL source is available in vendored/SDL
add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
set(SDLTTF_VENDORED OFF)

# This assumes the SDL_ttf source is available in vendored/SDL_ttf
add_subdirectory(vendored/SDL_ttf EXCLUDE_FROM_ALL)
add_subdirectory(vendored/libuv EXCLUDE_FROM_ALL)


# add protocol library and subdirectory
add_library(protocol)
add_subdirectory(protocol)


add_library(layout)
add_subdirectory(layout)


# add client and server subdirectories
add_subdirectory(client)
add_subdirectory(server)


# include the protocol and include directories for building net_server
target_include_directories(
	net_server
	PUBLIC
	protocol
	include
)

# include the protocol and vendored directories for building net_client
target_include_directories(
	net_client
	PUBLIC
	protocol
)


# include the include directory, vendored and protocol when building Client
target_include_directories(
	Client 
	PRIVATE
	include
	vendored
	protocol
	layout
)

# include the include directory, vendored and protocol when building Server
target_include_directories(
	Server
	PRIVATE
	include
	protocol
)


