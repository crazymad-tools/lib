/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-05-07 14:31
 * Filename         : main.cc
 * Description      : 
 *********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

char buf[2048];
char response[] = "HTTP/1.1 200 OK\r\n"
				"Date: Sun, 07 May 2017 12:04:27 GMT\r\n"
				"Server: Apache/2.4.6 (CentOS) PHP/5.4.16\r\n"
				"Last-Modified: Fri, 31 Mar 2017 10:06:59 GMT\r\n"
				"ETag: \"3d7-54cded174cf1b\"\r\n"
				"Accept-Ranges: bytes\r\n"
				"Content-Length: 18\r\n"
				"Keep-Alive: timeout=5, max=100\r\n"
				"Connection: Keep-Alive\r\n"
				"Content-Type: text/html; charset=UTF-8\r\n"
				"\r\n"
				"<h1>crazy_mad</h1>";

int main() {
	//freopen("data", "w", stdout);
	//printf("hello world!\n");
	socklen_t len = sizeof(sockaddr_in);
	struct sockaddr_in server_addr, client_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(8080);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int client_fd, server_fd = socket(AF_INET, SOCK_STREAM, 0);
	int on = 1;
	assert(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof on) != -1);
	assert(bind(server_fd, (struct sockaddr*)&server_addr, sizeof server_addr) != -1);
	/*if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof server_addr) == -1) {
		perror("bind:");
		exit(1);
	}*/
	listen(server_fd, 10);
	while (true) {
		bzero(&client_addr, sizeof client_addr);
		client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &len);
		printf("a new connection!\n");
		read(client_fd, buf, sizeof buf);
		printf("%s", buf);
		write(client_fd, response, sizeof response);
		close(client_fd);
		fflush(stdout);
	}

	return 0;
}

