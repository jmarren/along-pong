#
#
# target_sources(
# 	render
# 	PUBLIC
# 	circle.c
# 	line.c
# 	font.c
# 	text.c
#
# 	# PUBLIC allows consumers of the library
# 	# to "see" the library's header files
# 	PUBLIC
# 	FILE_SET HEADERS
# 	FILES render.h
# )
#
#
#
# # # Link to the actual SDL3 library.
# # target_link_libraries(hello PRIVATE SDL3_ttf::SDL3_ttf SDL3::SDL3)
# target_link_libraries(
# 	render
# 	PRIVATE 
# 	SDL3_ttf::SDL3_ttf
# )
#
#
