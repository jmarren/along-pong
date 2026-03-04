#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <uv.h>

/* types */
typedef struct {
	char* type;
	char* content;
} message;


typedef struct {
	char** messages;
	int count;
} raw_msg_list;

typedef struct {
	message* base;
	int len;
} message_list;

/* buffer */
void buffer_alloc_uv_handle(uv_handle_t* handle, size_t suggested_size, uv_buf_t* buf);
void buffer_encode_assign(char* type,  char* content, uv_buf_t* buf);

/* callback */
void cb_free_write(uv_write_t *req, int status);

/* parse */
raw_msg_list parse_messages(char* raw);
message parse_message(char* msg);
message_list parse_raw_message_list(raw_msg_list* list);

#endif
