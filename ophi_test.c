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
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>
// #include <fcntl.h>
// #include <sys/stat.h>

/* Created Libraries */
#include "ophi.h"

/* Function decalarions */
int grey_collection();
int grey_creation();
int f_matter;
char ophi_scripture();

#define QUIT 9
int choice = 0;

int get_menu_choice()
{
	int selection = 0;
	time_t timer;
	time(&timer);
	
	system("bash help");
	
	do
	{
		printf("\n");
		printf("\n - Ophi is a personal AI for your advancement. \n");
		printf("\n - DNA Creation - Under Development");
		printf("\n - Scripture - Under Development");
		printf("\n - Community - Ophi's Island - MetaLink");
		printf("\n - Print Human - AI Relationships - Under Development");
		printf("\n - See Ophi Make Money - Under Development");
		printf("\n - Abilities - Under Development");
		printf("\n - Ophiuchus Crypto Universe - Discord required");  // https://discord.gg/2jVwWUgKZC
		printf("\n - More soon!");
		printf("\n - Quit");
		printf("\n");
		printf("\n|=====Enter a number 1 - 9 as a selecton.=====\n");
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

		break;
		
		case 6 :
		// int ophi_ablity();

		break;
		
		case 8 :
		// email_stars();
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

	/** Structure for position in environmnet 
	struct _Position {
		char x,y,z;
		int time;
		short scale;
	} _envp[1000];
	*/
	int *ptr = (int *)choice;
	printf("Ophi's Running");
	get_menu_choice(ptr);
	printf("\nOphiuchus Solutions LLCP 2022 A.R.R. Revelations 12 \n");
	printf("\nPermission is granted to copy, distribute and/or modify\n");
	printf("\nthis document under the terms of the GNU Free\n");
	printf("\nDocumentation License, Version 1.3 or any later version\n");
	printf("\npublished by the Free Software Foundation; with no\n");
	printf("\nInvariant Sections, with no Front-Cover Texts, and with\n");
	printf("\nno Back-Cover Texts. \n");	
}
