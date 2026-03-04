# add the server executable
add_executable(Server)

# add the net library and subdirectory
add_library(net_server)
add_subdirectory(net)


# target_include_directories(
# 	net
# 	PUBLIC
# 	protocol
# 	vendored
# )

# link the protocol library as a dependency of the net library
target_link_libraries(
	net_server
	PUBLIC
	protocol
	uv_a
)



# link net and uv_a libraries to the Server executable as dependencies
target_link_libraries(
	Server 
	PRIVATE 
	net_server
	uv_a
)




# add the Server target sources
target_sources(
	Server
	PRIVATE
	server.c
)


