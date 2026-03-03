add_executable(Client)

add_library(Render)

target_sources(
	Render
	PRIVATE 
	render/circle.c
	render/line.c
	render/font.c
	render/text.c	

	# PUBLIC allows consumers of the library
	# to "see" the library's header files
	PUBLIC
	FILE_SET HEADERS
	FILES 
	render/render.h
	client.h

)


target_link_libraries(
	Render
	PUBLIC 
	SDL3_ttf::SDL3_ttf
)

add_library(Frames)


target_sources(
	Frames
	PRIVATE
	frames/enter_username.c
	render/text.c

	# PUBLIC allows consumers of the library
	# to "see" the library's header files
	PUBLIC
	FILE_SET HEADERS
	FILES 
	frames/frames.h
	render/render.h
)



target_link_libraries(
	Frames 
	PRIVATE 
	Render
)





target_sources(
	Client
	PRIVATE
	client.c
	loop.c
)




# # Link to the actual SDL3 library.
# target_link_libraries(hello PRIVATE SDL3_ttf::SDL3_ttf SDL3::SDL3)
target_link_libraries(
	Client
	PRIVATE 
	SDL3_ttf::SDL3_ttf
	SDL3::SDL3
	Frames
	Render
)

