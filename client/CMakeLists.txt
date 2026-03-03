add_executable(Client)


add_subdirectory(frames)
add_subdirectory(render)


target_sources(
	Client
	PRIVATE
	client.c
	loop.c
)


target_link_libraries(
	Client
	PRIVATE 
	SDL3::SDL3
	frames
	render
)

