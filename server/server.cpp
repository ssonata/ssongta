#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int server_socket = socket(PF_INET,SOCK_STREAM,0);
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("192.168.38.199");
	server_address.sin_port = htons(8000);

	bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));
	if(listen(server_socket, 5) == -1)
	{
		cout<<"listen is error"<<endl;
		exit(-1);
	}
	while(1)
	{
		unsigned int client_size = sizeof(client_address);
		int client_socket = accept(server_socket,(struct sockaddr*)&client_address, &client_size);
		int sock_opt;

		if(setsockopt(client_socket,SOL_SOCKET,SO_REUSEADDR,&sock_opt,sizeof(sock_opt)) == -1)
		{
			cout<<"setsockopt is error"<<endl;
			exit(-1);
		}
		if(client_socket == -1)
		{
			cout<<"client accpet is error"<<endl;
			exit(-1);
		}
		char message_in[1024];
		char message_out[1024];
		memset(message_in,0,1024);
		memset(message_out,0,1024);
		
		read(client_socket, message_in, sizeof(message_in));
		cout<<"client message:"<<message_in<<endl;

		if(!strncmp(message_in,"quit", 4))
		{
			write(client_socket, "bye bye", 8);
			close(client_socket);
			break;
		}
		snprintf(message_out, sizeof(message_out), "%s:%s",message_in,"OK");
		write(client_socket, message_out, sizeof(message_out));
		close(client_socket);
	}
}
