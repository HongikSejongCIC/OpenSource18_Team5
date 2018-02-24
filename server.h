#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

void error_handling(char * message)
{
				fputs(message, stderr);
				fputc('\n', stderr);
				exit(1);
}

void server(int port)
{
				int serv_sock;
				int clnt_sock;
				struct sockaddr_in serv_addr;
				struct sockaddr_in clnt_addr;
				int clnt_addr_size;
				char message[300];

				//서버 소켓 생성
				serv_sock = socket(PF_INET, SOCK_STREAM, 0);
				if(serv_sock == -1)
								error_handling("Socket ERROR");

				memset(&serv_addr, 0, sizeof(serv_addr));

				serv_addr.sin_family = AF_INET;
				serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
				serv_addr.sin_port = htons(port);

				//소켓에 주소 할당
				if(bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
								error_handling("bind ERROR");
				
				//연결 요청 대기상태로 진입
				if(listen(serv_sock, 5) == -1)
								error_handling("listen ERROR");

				clnt_addr_size = sizeof(clnt_addr);

				//연결 요청 수락
				clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr,&clnt_addr_size);

				if(clnt_sock == -1)
								error_handling("accept ERROR");

				//데이터 전송
				printf("메세지를 입력하세요: ");
	  		scanf("%s", message);
				write(clnt_sock, message, sizeof(message));
				printf("메시지 전송이 완료되었습니다");

				//연결 종료
				close(clnt_sock);

				return;
}

