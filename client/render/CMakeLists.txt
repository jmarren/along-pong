
add_library(render)



target_sources(
	render
	PRIVATE
	circle.c
	line.c

	# PUBLIC allows consumers of the library
	# to "see" the library's header files
	PUBLIC
	FILE_SET HEADERS
	FILES render.h
)


