#ifndef SERVER_H
#define SERVER_H

#include <macro.h>

// #include "macro.h"
#include <uv.h>

typedef struct {
	char username[MAX_USERNAME_CHARS];
	uv_stream_t* stream;
	void* opponent;
	// write_tcp* write_tcp;
} user_t;

// typedef void (render_handler)(void* app);
typedef struct {
	int len;
	user_t users[MAX_ACTIVE_USERS];
} active_users;




typedef struct {
	user_t user;
	float block_y;
} player;

struct invite {
	user_t* invitor;
	user_t* invitee;
	struct invite* next;
};

typedef struct invite invite;

typedef struct {
	int len;
	struct invite* base;
} invites;

typedef struct {
	float circle_pos;
	player player_one;
	player player_two;
} game;


typedef struct {
	int len;
	game* games;
} games;


typedef struct {
	uv_loop_t* loop;
	uv_tcp_t tcp_server;
	uv_udp_t udp_server;
	active_users active_users;
	invites invites;
	games games;
} server_t;



#endif
