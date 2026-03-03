add_library(macros)



target_sources(
	macros
	# PUBLIC allows consumers of the library
	# to "see" the library's header files
	PUBLIC
	FILE_SET HEADERS
	FILES macros.h
)

