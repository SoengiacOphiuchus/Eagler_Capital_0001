/** @file Ophi.c
 * 
 * @brief A personal AI companion for wearable technology.
 * 
 * @par
 * *COPYRIGHT NOTICE: (c) 2023 OPHIUCUS SOLUTIONS LLCP.  All rights reserved. - Revelations 12
 */

/* Standard library */
/* Windows API */

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
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
// #include "~/pico/stdlib.h"

/* Created Libraries */
#include "ophi.h"
// #include "server.h
// #include "essence.py"

/* Function decalarions */
char ophi_scripture();
// void oscilloscope();
long int fibonacci();
void sieve();
/* Variable decalarions */
#define QUIT 9
#define SIZE 13
#define ISVALIDSOCKET(s) ((s) >= 0)
#define CLOSESOCKET(s) close(s)
#define SOCKET int
#define GETSOCKETERRNO() (errno)

/* File pointer */
FILE *fptr;

/* Global Int*/
int choice = 0;
int status[SIZE];
int i, j, N, k, sq, num, flag;
long int A,B,C,D;
char ch;

/* Structs */

struct date {
	int month;
	int day;
	int year;
};

struct profile {
	char name[25];
	int svr_no;
	int age;
	float popu;
	struct date joiningDate;
};

/*Functions*/

/* Server Function */
int launch(){
		/*Create Server */
	fptr = fopen("index.html", "r");
	printf("Configuring local address...\n");
	struct addrinfo hints;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	
	/*Binding Address */
	struct addrinfo *bind_address;
	getaddrinfo(0, "8080", &hints, &bind_address);
	
	/* Creating Socket */
	printf("Creating socket...\n");
	SOCKET socket_listen;
	socket_listen = socket(bind_address->ai_family, bind_address->ai_socktype, bind_address->ai_protocol);
	if (!ISVALIDSOCKET(socket_listen)) {
		fprintf(stderr, "socket() failed - 127.0.0.1, 8080, TCPIP (%d)\n", GETSOCKETERRNO());
			return 1;
	}
	printf("Binding socket to local address...\n");
	if (bind(socket_listen, bind_address->ai_addr, bind_address->ai_addrlen)) {
		fprintf(stderr, "bind() failed- 127.0.0.1, 8080, 32BITs(%d)\n", GETSOCKETERRNO());
			return 1;
	}
	freeaddrinfo(bind_address);

	/* Listen for client */
	printf("Listening...\n");
	if (listen(socket_listen, 10) < 0) {
		fprintf(stderr, "listen() failed, (%d)\n", GETSOCKETERRNO());
		return 1;
	}

	printf("Waiting for connection...\n");
	struct sockaddr_storage client_address;
	socklen_t client_len = sizeof(client_address);
	SOCKET socket_client = accept(socket_listen, (struct sockaddr*) &client_address, &client_len);
	if (!ISVALIDSOCKET(socket_client)) {
		fprintf(stderr, "accept() failed. client, 8080, 32bit", GETSOCKETERRNO());
		return 1;
	}
	/* IP6 Addition 
	int option = 0;
	if (setsockopt(socket_listen, IPPROTO_IPV6, IPV6_V6ONLY, (void*) &option, sizeof(option))){
		fprintf(stderr, "setsockopt() IP6 Failed. (%d)\n", GETSOCKETERRNO());
		return 1;
	}
	*/
	printf("Client is connected... ");
	char address_buffer[100];
	getnameinfo((struct sockaddr*)&client_address, client_len, address_buffer, sizeof(address_buffer), 0, 0, NI_NUMERICHOST);
	printf("%s\n", address_buffer);

	printf("Reading request...\n");
	char request[1024];
	int bytes_received =recv(socket_client, request, 1024, 0);
	printf("Received %d bytes.\n", bytes_received);

	printf("%.*s", bytes_received, request);
	printf("Sending response...\n");
	fptr = fopen("index.html", "r");
	const char *response = "HTTP/1.1 200 OK\r\n" "Connection: close\r\n" "Content-Type: text/plain\r\n\r\n" "Local time is: ";
	int bytes_sent = send(socket_client, response, strlen(response), 0);
	printf("Sent %d of %d byte.\n", bytes_sent, (strlen(response)));
	// fptr

	time_t timer;
	time(&timer);
	char *time_msg = ctime(&timer);
	bytes_sent = send(socket_client, time_msg, strlen(time_msg), 0);
	printf("Sent %d of %d bytes.\n", bytes_sent, (int)strlen(time_msg));

	printf("Closing connection...\n");
	CLOSESOCKET(socket_client);

	printf("Closing listening socket...\n");
	CLOSESOCKET(socket_listen);

	printf("finshed.\n");
}
/* Reports Function */
void file_open() {
	fptr = fopen("bible.txt", "r");
	num = fgetc(fptr);

	while(num != EOF) {
	putchar(num);
	num = fgetc(fptr);
	}
	
	fclose(fptr);
}
void sieve() {
	for(i = 0; i < SIZE; i++) {
	status[i] = 0;
	}
	
	sq = sqrt(SIZE);

	for (i=4;i<=SIZE;i+= 2) {
	status[i] = 1;
	}

	for(i = 3; i <=sq; i+= 2) {
	if(status[i] == 0){
		for(j = 2*i; j <= SIZE; j += i)
			status[j] = 1;
		}
	}
	status[1] = 1;
}
long int fibonacci(){
	do {
		do {

			flag = 0;
			printf("Enter a number (0 < N <= 45): ");
			scanf("%d", &N);
			if ((N <=0) || (N >45))
				flag = 1;
			} while (flag);

		A = 0;
		B = 1;

		printf("Fibonacci Sequence:\n");

		for (k = 1; k <= N; k++) {
			printf("%d th term is : %ld\n", ((k * 2) - 1), A);
			if (((k *2) - 1) == N) break;
			printf("%d th term is : %ld\n", (k * 2), B);
			if ((k * 2) == N) break;
			C = A +  B;
			D = B + C;
			A = C;
			B = D;
		}

	printf("Do you want to continue? (Y/N) : ");
		scanf(" %c", &ch);
	} while((ch == 'y')||(ch == 'Y'));

	printf("Thank you.\n");
	return(1);
}
/* void oscilloscope() {
	gpio_set_function(22, GPIO_FUNC_SIO);
	gpio_set_dir(22, true);
	while(true)
	{
		gpio_put(22,1);
		gpio_put(22,0);
	}
}*/
void reports(void){
	fptr = fopen("capital_report.txt", "w");
	struct profile *ptr1, cap_ship = {"Ophi_Capital",1,0,100,12,31,2022};
	if(fptr != NULL){
		puts("$$$$$$$ Ship Reports: $$$$$$$");
		printf("Would you like to make a report for the Captial Ship?");
		scanf("%c", &flag);
		while(flag == 'y'){
			printf("Enter Captial Ship Name, server serial number, server age and Population: ");
			scanf("%s %d %d %f", cap_ship.name, &cap_ship.svr_no , &cap_ship.age , &cap_ship.popu);
			fprintf(fptr, "%s %d %d %.1f has beed documented.", cap_ship.name, &cap_ship.svr_no, &cap_ship.age, &cap_ship.popu);
		fflush(stdin);
		printf("Any more changes?(y/n): ");
		scanf(" %c", &flag);
		// rewind(fptr);
		}
		/* Close */
		k = fclose(fptr);
		if(k == -1)
			puts("Reports file closing failed.  Attempt Data transfer again.");
		if(k == 0)
			puts("Reports file closed successfully!  Please retrieve your data.");
		}

	else
		puts("$$$$$$$ Ship Reports File Failed opening; verify that you are on the right ship or that no other files are open.");
}

/* Menu Choice Function */
int get_menu_choice()
{
	int selection = 0;
	time_t timer;
	time(&timer);
	// system("bash help");
	
	do
	{
		printf("\n");
		printf("\n - Ophi is Capital Ship Software. \n");
		printf("\n 1 Assembly Code - Under Development");
		printf("\n 2 Open bible.txt");
		printf("\n 3 Fibonacci Sequence");
		printf("\n 4 Print Ship Report");
		printf("\n 5 Pick Prime Number from a list of serial numbers.");
		printf("\n 6 Community Discord- Under Development");
		printf("\n 7 Start Capital Ship Server");
		printf("\n 8 More soon!");
		printf("\n 9 Quit");
		printf("\n");
		printf("\n|=====Enter 1-8 For Selection or 9 to Quit.=====\n");
		printf ("\nLocal time is: %s\n", ctime(&timer));
		scanf("%d", &selection);
	}while (selection < 1 || selection > 9);
	choice = selection;
	return selection;
}

/* Menu Function */
int ophi_menu() {
	char *messages[SIZE] = {"Flagship is on"};
	while (choice != QUIT)
	{
		switch(choice) {

		case 1 :
		printf("\a DNA TESTING PHASE \a\n");
		printf("\a ENTER: \a\n");
		printf("\a UNDER DEVELOPENT \a\n");

		// oscilloscope();
		break;
		
		case 2 :
		printf("\a Opening the bible.txt \a\n");
		file_open();
		break;
		
		case 3 :
		printf("\a The Fibonacci Sequence\a\n");
		fibonacci();
		break;
		
		case 4 :
		printf("\a Captial Ship Reports\a\n");
		reports();
		break;
		
		case 5 :
		printf("Picking prime numbers...\n");
		sieve();
		do {
			printf("\n\nEnter then number (1 <= N <= 1000) : ");
			scanf("%d", &N);
			} while ((N < 1) || (N > 1000));
		printf("\nFollowing numbers are prime in the range : 1 to %d : \n", N);
		for (i = 1; i < N; i++)
			if(status[i]==0) printf("%d\t", i);
		printf("\nThank you.\n");
		break;
		
		case 6 :
		printf("Under Development\n");
		// open_website_part(choice);
		break;
		
		case 7:
		printf("Under Development\n");
		launch();
		break;
		
		case 8 :
		puts(messages[SIZE]);
		break;
		
		// case to catch characters in choice menu ->
		// case get_menu_choice(char) :
		default:
		printf("Thank You!  I can't wait for your next Advancements! \a\n");
		get_menu_choice();
		break;
		}
	}
	return 1;
}

int main() {
	/** Ophi's main purpose is to assist it's human as a companion to the
	 *  internet, the human's envrionment, strange or forgen technology
	 *   & personal technoloy. It is to be completed by the community.
	 * Please use caution when using Ophi to
	 * connect to other divices as it may see the other device as a
	 * threat. */

	/* Main Variables */




	printf("Opening Menu for choices...\n");
	int *ptr = (int *)choice;
	/* Functions */
	get_menu_choice(ptr);
	ophi_menu(choice);
	// struct server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 80, 10);
	printf("\nOphiuchus Solutions LLCP 2023 A.R.R. Revelations 12 \n");
	printf("\nPermission is granted to copy, distribute and/or modify\n");
	printf("\nthis document under the terms of the GNU Free\n");
	printf("\nDocumentation License, Version 1.3 or any later version\n");
	printf("\npublished by the Free Software Foundation. The Invariant Sections.\n");

}
