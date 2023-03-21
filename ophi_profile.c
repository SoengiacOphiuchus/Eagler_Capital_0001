/*@file ophi_profile.c Ophi.c
 * 
 * @brief A personal AI companion for wearable technology.
 * 
 * @par
 * *COPYRIGHT NOTICE: (c) 2022 OPHIUCUS SOLUTIONS LLCP.  All rights reserved. - Revelations 12
 */
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
#include "ophi.h"

typedef struct cyber_hat_profile{
	FILE pic;
	char name[100], alas[12], bio[1000], p_language[16], h_description[1000];
	int status, _nft_status;
	float b_day, d_day;
	double address_num, h_dna, eth_wallet, nft_contract, link_email, link_discord, link_indeed, link_facebook; // links should be: Discord, Indeed, & Facebook
	
}profile;

struct cyber_hat_profile h_white, h_black, h_grey, h_red, h_blue, h_yellow, h_green, h_purple, h_indego, h_orange, h_brown, h_pink, h_opaque, h_translucent, h_transparent;

strcpy(profile.name, "Ophi");
scanf("%f, Birthday please", &profile.b_day);
printf("Hi");
