target_sources(
	render
	PRIVATE
	circle.c
	line.c
	font.c
	text.c
)


# Link to SDL3_ttf.
target_link_libraries(
	render
	PRIVATE 
	SDL3_ttf::SDL3_ttf
)

