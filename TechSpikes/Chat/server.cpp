#include<stdio.h>
#include<string.h>	//strlen
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr
#include<unistd.h>	//write
#include <cstring>

#define SERVER_PORT 5502
#define SERVER_PORT2 502
#define IN_BUF_LEN 300


int main()
{
	int socket_desc, socket_desc2 , new_socket, new_socket2 , c, c2, in, in2, out, out2;
	int control_access=0;
	struct sockaddr_in server, server2 , client, client2;
	char in_buf[IN_BUF_LEN], *out_buf, in_buf2[IN_BUF_LEN], *out_buf2;
	
	//Create socket
	socket_desc = socket(PF_INET , SOCK_STREAM , IPPROTO_TCP);
	if (socket_desc == -1)
	{
		printf("Could not create socket...\n");
		return -1;
	}


	socket_desc2 = socket(PF_INET , SOCK_STREAM , IPPROTO_TCP);
	if (socket_desc2 == -1)
	{
		printf("Could not create socket...\n");
		return -1;
	}


	
	
	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(SERVER_PORT);

	server2.sin_family = AF_INET;
	server2.sin_addr.s_addr = INADDR_ANY;
	server2.sin_port = htons(SERVER_PORT2);
	
	//Bind
	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
		printf("Bind failed...\n");
		return 1;
	}

	if( bind(socket_desc2,(struct sockaddr *)&server2 , sizeof(server2)) < 0)
	{
		printf("Bind failed...\n");
		return 1;
	}

	
	//Listen
	listen(socket_desc , 3);
	listen(socket_desc2 , 3);
	
	//Accept and incoming connection
	printf("Waiting for incoming connections at port %d...\n", SERVER_PORT);
	
	c = sizeof(struct sockaddr_in);
	if( (new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) < 0 )
	{
		
		printf("Accept failed...\n");
		return -1;
	}
	else
		printf("Connection accepted: Client: %s, Port: %d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
			
	
	bzero(in_buf, IN_BUF_LEN);

	printf("Waiting for incoming connections at port %d...\n", SERVER_PORT2);

	c = sizeof(struct sockaddr_in);
	if( (new_socket2 = accept(socket_desc2, (struct sockaddr *)&client2, (socklen_t*)&c)) < 0 )
	{
		
		printf("Accept failed...\n");
		return -1;
	}
	else
		printf("Connection accepted: Client: %s, Port: %d\n", inet_ntoa(client2.sin_addr), ntohs(client2.sin_port));
			
	
	bzero(in_buf2, IN_BUF_LEN);
	
	
	// Waiting data from the client
	

	while(true){


		if(control_access == 0){
				in = recv(new_socket, in_buf , IN_BUF_LEN, 0);
				if( in < 0)
				{
					printf("Recv failed..\n");
					return -1;
			
				}
			else{
				printf("Client1: %s\n", in_buf);
				control_access = 1;

			}
			}
			else{
				printf("Wait for Client2 move\n");
				memset(in_buf, 0, IN_BUF_LEN);
			}
			
			if(control_access == 1){
				in = recv(new_socket2, in_buf2 , IN_BUF_LEN, 0);
				if( in < 0)
				{
					printf("Recv failed..\n");
					return -1;
				
				}
			else{
				printf("Client2: %s\n", in_buf2);
				control_access = 0;
			

			}
			}
			else{
				printf("Wait for Client 1 move\n");
				memset(in_buf2, 0, IN_BUF_LEN);
		}


		
		


	}
	
	close(socket_desc);
	
	
	return 0;
}