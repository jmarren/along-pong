#include "server.h"
#include <uv.h>
#include <stdbool.h>
#include "net/net.h"
#include <protocol.h>


server_t server;


int main(void) {

    // create default libuv loop
    server.loop = uv_default_loop();

    server.active_users.len = 0;

    tcp.init(&server);
    udp.init(&server);


    // TEST_ASSERT_BIT_HIGH(1, 2);
	
    // // initialize networking
    // server_init_tcp(&server);
    // server_init_udp(&server);

    // run the loop with default flag
    uv_run(server.loop, UV_RUN_DEFAULT); // 8. Run the Event Loop

    return 0;
}

