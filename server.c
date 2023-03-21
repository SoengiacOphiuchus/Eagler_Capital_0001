#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

struct server server_constructor(int domain, int service, int protocol, u_long interface, int port, int backlong, void (*launch)(struct server *server))
{
	struct server server;
	
	server.domain = domain;
	server.service = service;
	server.protocol = protocol;
	server.interface = interface;
	server.port = port;
	server.backlog = backlog;
	
	server.address.sin_family = domain;
	server.address.sin_port= htons(port);
	server.address.sin_addr.s_addr= hton1(interface);
	
	server.socket = socket(domain, service, protocol);
	if (server.socket == 0)
	{
		perror("Could not connect to socket...\n");
		exit(1); // error in the code
	}
	
	if((bind(server.socket, (struct sockaddr *)&server.address, sizeof(server.address))) < 0);
	{
		perror("Could not bind socket...\n");
		exit(1);
	}
	
	if ((listen(server.socket, server.backlog)) < 0)
	{
		perror("Could not listen ...\n");
		exit(1);
	}
	
	server.launch = launch;
	
	return server;
}
