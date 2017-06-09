/*********************************************************
 * Author           : crazy_mad
 * Last modified    : 2017-06-09 13:46
 * Filename         : main.cc
 * Description      : 
 *********************************************************/

#include <iostream>
#include <Socket.h>
#include <net_def.h>

using namespace std;

int main() {
	char buf[BUFSIZE] = { 0 };
	struct SocketData data;
	Socket socket(8080);
	socket.init();
	socket.Bind();
	socket.Listen(10);

	socket.Accept(&data);
	Socket client(data);
	
	socket.Read(&data, buf);
	cout << buf << endl;
	int ret = client.Read(buf);
	if (ret == 0) {
		cout << "对等方关闭套接字" << endl;
		client.Close();
	} else if (ret == -1) {
		cout << "链接异常" << endl;
	} else {
		cout << buf << endl;
	}

	return 0;
}
