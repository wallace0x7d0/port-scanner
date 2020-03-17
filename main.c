#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(){
	char ip[] = "127.0.0.1";
	int start  = 5000,
		end    = 5001;

	struct sockaddr_in saddr;
	int saddr_size = sizeof(saddr);

	struct sockaddr_in caddr = {

		.sin_family = AF_INET,
		.sin_addr.s_addr = inet_addr(ip)
	};

	int client = socket(AF_INET, SOCK_STREAM, 0);

	for (int i = start; i <= end; ++i){
		caddr.sin_port = htons(i);
		int status = connect (client, (struct sockaddr *)&caddr, sizeof (caddr));

		if(status == 0){
			printf("Porta %i aberta\n", i);
		}else {
			printf("Porta %i fechada\n", i);
		}

		close(client);
		close(status);
	}

	return 0;
}