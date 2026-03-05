#ifndef NET_H
#define NET_H



#include <uv.h>
#include "../client.h"


typedef void (initializer)(App* app);
typedef void (writer)(uv_stream_t* stream, char* type, char* content);
typedef void (message_writer)(char* type, char* content);


typedef struct {
	initializer* init;
	writer* write;
	message_writer* write_msg;
} tcp_t;


typedef struct {
	initializer* init;
	// writer* write;
} udp_t;

extern tcp_t tcp;


void net_start(App* app);

#endif
