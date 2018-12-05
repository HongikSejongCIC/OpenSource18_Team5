#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "server.h"
#include "client.h"

int main(void)
{
				int Choice;
HERE:
				printf("1. 메시지 수신\n 2. 메시지 전송\n");
				printf("동작을 입력하세요 : ");
				scanf("%d", &Choice);
				switch(Choice){
				case 1:
								printf("메시지를 수신합니다.\n");
								client(1601);
								break;
				case 2:
								printf("메시지를 전송합니다.\n");
								server(1601);
								break;
				default:
								goto HERE;
								break;
				}
}
