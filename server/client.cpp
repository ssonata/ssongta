#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <string>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main()
{
	while(1)
	{
		int client_socket = socket(PF_INET, SOCK_STREAM,0);

		struct sockaddr_in server_address;
		memset(&server_address,0,sizeof(struct sockaddr_in));
		server_address.sin_family = AF_INET;
		server_address.sin_addr.s_addr = inet_addr("192.168.38.199");
		server_address.sin_port = htons(8000);

		if(connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == 0)
		{
			cout<<"connect is error"<<endl;
			exit(-1);
		}
		char message_in[1024];
		char message_out[1024];
		memset(message_in, 0, 1024);
		memset(message_out,0, 1024);

		fgets(message_out, 1024, stdin);
		write(client_socket, message_out, sizeof(message_out));

		if(!strncmp(message_out,"quit",4))
		{
			close(client_socket);
			break;
		}

		int str_len = read(client_socket, message_in, sizeof(message_in));
		cout<<"Server Message:"<<message_in<<endl;
		close(client_socket);
	}
	return 0;
}
