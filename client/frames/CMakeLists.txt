add_library(frames)



target_sources(
	frames
	PRIVATE
	enter_username.c

	# PUBLIC allows consumers of the library
	# to "see" the library's header files
	PUBLIC
	FILE_SET HEADERS
	FILES frames.h
)


