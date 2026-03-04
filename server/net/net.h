#ifndef NET_H
#define NET_H

#include <uv.h>
#include "../server.h"


typedef void (initializer)(server_t* server);
typedef void (writer)(uv_stream_t* stream, char* type, char* content);

typedef struct {
	initializer* init;
	writer* write;
} tcp_t;


typedef struct {
	initializer* init;
	// writer* write;
} udp_t;

extern tcp_t tcp;
extern udp_t udp;

#endif
