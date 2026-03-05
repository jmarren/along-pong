# add the Client executable
add_executable(Client)

# add render library and subdirectory
add_library(render)
add_subdirectory(render)

# add frames library and subdirectory
add_library(frames)
add_subdirectory(frames)

add_library(net_client)
add_subdirectory(net)

target_link_libraries(
	net_client
	PUBLIC
	protocol
)

# link the render library as a dependency of the frames library
target_link_libraries(
	frames 
	PRIVATE 
	render
)

# include the render directory when building frames library
target_include_directories(
	frames 
	PUBLIC 
	render
)


# add sources for the client executable
target_sources(
	Client
	PRIVATE
	client.c
	loop.c
)


# include the frames directory when building Client
target_include_directories(
	Client 
	PRIVATE 
	frames 
	net
)

# link required libraries as dependencies of the Client executable
target_link_libraries(
	Client
	PRIVATE 
	SDL3::SDL3
	frames
	render
	protocol
	net_client
	layout
)

