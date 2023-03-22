/** @file Ophi.c
 * 
 * @brief A personal AI companion for wearable technology.
 * 
 * @par
 * *COPYRIGHT NOTICE: (c) 2022 OPHIUCUS SOLUTIONS LLCP.  All rights reserved. - Revelations 12
 */

/* Standard library */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "server.h"

/* Created Libraries */
#include "ophi.h"
// #include "essence.py"

/* Function decalarions */

#define QUIT 9
int choice = 0;
char ophi_scripture();
// int grey_collection();
// int grey_creation();
// int f_matter;

/* Menu Functions */

void (*launch())(struct server *server)
{
	char buffer[30000];
	char *hello = "<html><body><h1>Welcome to Ophiuchus Solutions Community Software</h1></body></html>";
	int address_length = sizeof(server->address);
	int new_socket;
	while (1)
	{
		printf("$$$$$$$ Waiting for Connection $$$$$$$");
		
		new_socket = accept(server->socket, (struct sockaddr *)&server->address, (socklen_t *)&address_length);
		read(new_socket, buffer, 30000);
		printf("%s\n", buffer);
		write(new_socket, hello, strlen(hello));
		close(new_socket);
	}
}

void open_website_part(int i) { 
	char *cmd;
	asprintf(&cmd, "https://discord.gg/4RbPzb2Pga", i);
	system(cmd);
	free(cmd);
}

int get_menu_choice()
{
	int selection = 0;
	time_t timer;
	time(&timer);
	
	system("bash help");
	
	do
	{
		printf("\n");
		printf("\n - Ophi is Community AI Software. \n");
		printf("\n 1 DNA Collab Creation - Under Development");
		printf("\n 2 Scripture of The Community - Under Development");
		printf("\n 3 Community - Ophi's Island - MetaLink (Under Development");
		printf("\n 4 Print Human - AI Relationships - Under Development");
		printf("\n 5 Ophi Investing - Under Development");
		printf("\n 6 Community additions - Under Development");
		printf("\n 7 Discord https://discord.gg/2jVwWUgKZC - Under Development"); 
		printf("\n 8 More soon!");
		printf("\n 9 Quit");
		printf("\n");
		printf("\n|=====Enter 1-8 For Selection or 9 to Quit.=====\n");
		printf ("\nLocal time is: %s\n", ctime(&timer));
		// fprintf(stdout, "%s, %s %d, %.2d:%.2d\n", weekday, month, day, hour, min);
		scanf("%d", &selection);
	}while (selection < 1 || selection > 9);
	return selection;
}

int ophi_menu() {
	
	while (choice != QUIT)
	{
		switch(choice) {
		case 1 :
		
		printf("\a DNA TESTING PHASE \a\n"); 
		printf("\a ENTER: \a\a\a\n");
		// OPHI_DNA;
		
		break;
		
		case 2 :
		// ophi_scripture(OPHI_DNA);
		break;
		
		case 3 :
		// update_human();
		break;
		
		case 4 :
		// print_report();
		break;
		
		case 5 :
		printf("Launching Server...\n");
		server.launch(&server);

		break;
				
		case 6 :
		open_website_part(choice);

		break;
		
		case 8 :
		puts(messages[choice]);
		break;
		 
		// case to catch characters in choice menu -> 
		// case get_menu_choice(char) :
		default:
		printf("Thank You!  I can't wait for your next Advancements! \a\n");
		}
	}
	return 0;
}

int main() {
	/** Ophi's main purpose is to assist it's human as a companion to the
	 *  internet, the human's envrionment, strange or forgen technology
	 *   & personal technoloy. It is to be completed by the community.
	 * Please use caution when using Ophi to 
	 * connect to other divices as it may see the other device as a 
	 * threat. */
	 
	printf("~~~~~Welcome to the Eagler's Nest~~~~~");
	struct server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 80, 10);
	char *messages[choice] = {"Flagship","is","on"};
	int *ptr = (int *)choice;
	get_menu_choice(ptr);
	printf("\nOphiuchus Solutions LLCP 2023 A.R.R. Revelations 12 \n");
	printf("\nPermission is granted to copy, distribute and/or modify\n");
	printf("\nthis document under the terms of the GNU Free\n");
	printf("\nDocumentation License, Version 1.3 or any later version\n");
	printf("\npublished by the Free Software Foundation; with no\n");
	printf("\nInvariant Sections, with no Front-Cover Texts, and with\n");
	printf("\nno Back-Cover Texts. \n");	
}
