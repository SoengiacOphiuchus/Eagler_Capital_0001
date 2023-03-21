/* server_h 
 * 
 * Ophiuchus Solutions LLCP @ 2023 All rights reserved
 * /
 * */
#ifndef server_h
#define server_h

#include <sys/socket.h>
#include <netinet/in.h>

struct server_h
{
	
	int domain;
	int protocol;
	int service;
	u_long interface;
	int port;
	int backlog;
	
	struct sockaddr_in address;
	// struct sockaddr_in6 address6;
	
	int socket;
	
	void (*launch)(struct server *server);
	
};

struct server server_constructor(int doimain, int service, int protocol, u_long interface, int port, int backlong, void(*launch)(void)(struct server *server));

#endif /* server_h*/
