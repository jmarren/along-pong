cmake_minimum_required(VERSION 3.16)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_INCLUDE_PATH vendored/SDL_ttf/include)


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


# add client and server subdirectories
add_subdirectory(client)
add_subdirectory(server)

# include the include directory for shared header files
target_include_directories(
	Client 
	PRIVATE
	include
)



# include the include directory for shared header files
target_include_directories(
	Server 
	PRIVATE
	include
)




