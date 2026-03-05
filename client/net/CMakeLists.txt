
target_sources(
	net_client
	PRIVATE
	tcp.c
	net.c
)

target_link_libraries(
	net_client
	PRIVATE
	uv_a
)
