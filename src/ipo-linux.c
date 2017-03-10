#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void ipo_usage(void);

int main(int argc, char *argv[])
{
	unsigned int sockfd, portno, i;
	unsigned short ipo_loop_error;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	if (argc < 3) {
		ipo_usage();
		exit(1);
	}

	printf("Scanning host %s\n", argv[1]);

	i = 2;
	for ( i; i<argc; i++ ) {

		ipo_loop_error = 0;

		//Set port number
		portno = atoi(argv[i]);

		//Create socket
		sockfd = socket(AF_INET, SOCK_STREAM, 0);
		if (sockfd < 0)  {
			fprintf(stderr, "Error creating socket.\n");
			ipo_loop_error = 1;
		}

		//Get hostname.
		server = gethostbyname(argv[1]);
		if (server == NULL) {
			fprintf(stderr, "Could not resolve host %s.\n", argv[1]);
			ipo_loop_error = 1;
		}

		//If we have a socket or hostname error, skip this.
		if ( ipo_loop_error != 1 ) {

			//Build the connection.
			bzero((char *) &serv_addr, sizeof(serv_addr));
			serv_addr.sin_family = AF_INET;
			bcopy((char *)server->h_addr, 
					(char *)&serv_addr.sin_addr.s_addr,
					server->h_length);
			serv_addr.sin_port = htons(portno);

			if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)  {
				fprintf(stderr, "Port %i closed.\n", portno);
			} else {
				printf("Port %i is open!\n", portno);
			}

		}

		//Close the connection
		close(sockfd);

	}
	return 0;

}

void ipo_usage()
{
	fprintf(stderr,"Usage: ipo [host] [port]\n");
}
