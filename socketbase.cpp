#include "socketbase.h"
#include <iostream>

#pragma comment(lib, "ws2_32.lib")


int SocketBase::init(const char* ipaddr, int port)
{
	psend_buf_ = new char[BUF_SIZE];
	precv_buf_ = new char[BUF_SIZE];

	// initialize socket library
	if (WSAStartup(MAKEWORD(2, 2), &wsadata_)) {
		std::cout << "socket init failed.\n";
		WSACleanup();
		return -1;
	}
	std::cout << "socket init success.\n";

	// check if have a new version
	if (LOBYTE(wsadata_.wVersion) != 2 || HIBYTE(wsadata_.wHighVersion) != 2) {
		std::cout << "socket lib version doesn't match.\n";
		WSACleanup();
		return -2;
	}
	std::cout << "socket lib version match success.\n";

	// fill server info
	server_addr_.sin_family = AF_INET;
	server_addr_.sin_addr.S_un.S_addr = inet_addr(ipaddr);
	server_addr_.sin_port = htons(port);
	return 0;
}

int SocketBase::close()
{
	delete[] psend_buf_;
	psend_buf_ = nullptr;
	delete[] precv_buf_;
	precv_buf_ = nullptr;

	// close socket
	closesocket(s_server_);
	closesocket(s_client_);
	WSACleanup();
	return 0;
}

int TCPSocketServerBase::init(const char* ipaddr, int port)
{
	// 调用父类方法对通用变量做初始化
	SocketBase::init(ipaddr, port);

	// create socket
	s_server_ = socket(AF_INET, SOCK_STREAM, 0);
	if (s_server_ == INVALID_SOCKET) {
		printf("socket() failed ,Error Code:%d/n", WSAGetLastError());
		WSACleanup();
		return -3;
	}

	if (bind(s_server_, (SOCKADDR*)&server_addr_, sizeof(SOCKADDR)) == SOCKET_ERROR) {
		std::cout << "bind failed.\n";
		WSACleanup();
		return -3;
	}
	std::cout << "socket bind success.\n";

	// setting socket to listen
	if (listen(s_server_, SOMAXCONN) < 0) {
		std::cout << "set listen failed.\n";
		WSACleanup();
		return -5;
	}
	std::cout << "set listen success.\n";
	std::cout << "server listenning ...\n";

	// accept connection request
	int len = sizeof(SOCKADDR);
	s_client_ = accept(s_server_, (SOCKADDR*)&client_addr_, &len);
	if (s_client_ == SOCKET_ERROR) {
		std::cout << "connect failed!\n";
		WSACleanup();
		return -6;
	}
	return 0;
}

int TCPSocketServerBase::recvData(void* _byte, size_t _len)
{
	if (recv(s_client_, (char*)_byte, (int)_len, 0) < 0) {
		std::cout << "receive failed!\n";
		return -1;
	}
	if (send(s_client_, "received.\n", sizeof("received.\n"), 0) < 0) {
		std::cout << "send failed!\n";
		return -2;
	}
	return 0;
}

int TCPSocketClientBase::init(const char* ipaddr, int port)
{
	SocketBase::init(ipaddr, port);

	s_server_ = socket(AF_INET, SOCK_STREAM, 0);
	if (s_server_ == INVALID_SOCKET) {
		printf("socket() failed, Error Code:%d/n", WSAGetLastError());
		WSACleanup();
		return -3;
	}

	if (connect(s_server_, (SOCKADDR*)&server_addr_, sizeof(SOCKADDR)) == SOCKET_ERROR) {
		std::cout << "server connect failed!\n";
		WSACleanup();
		return -4;
	}
	std::cout << "server connect success!\n";
	return 0;
}

int TCPSocketClientBase::sendData(void* _byte, size_t _len)
{
	memset(precv_buf_, 0, BUF_SIZE);
	if (send(s_server_, (char*)_byte, (int)_len, 0) < 0) {
		std::cout << "send failed!\n";
		return -1;
	}
	if (recv(s_server_, precv_buf_, BUF_SIZE, 0) < 0) {
		std::cout << "receive failed!\n";
		return -2;
	}
	std::cout << "receive server message: " << precv_buf_ << "\n";
	return 0;
}

int UDPSocketServerBase::init(const char* ipaddr, int port)
{
	SocketBase::init(ipaddr, port);
	s_server_ = socket(AF_INET, SOCK_DGRAM, 0);

	if (bind(s_server_, (SOCKADDR*)&server_addr_, sizeof(SOCKADDR)) == SOCKET_ERROR) {
		std::cout << "bind failed!\n";
		WSACleanup();
		return -3;
	}
	std::cout << "socket bind success.\n";
	return 0;
}

int UDPSocketServerBase::recvData(void* _byte, int _len)
{
	if (recvfrom(s_server_, (char*)_byte, BUF_SIZE, 0, (SOCKADDR*)&client_addr_, &_len) == SOCKET_ERROR) {
		std::cout << "receive failed!\n";
		return -1;
	}
	if (sendto(s_server_, "received.\n", sizeof("received.\n"),
		0, (SOCKADDR*)&client_addr_, _len) < 0) {
		std::cout << "send failed!\n";
		return -2;
	}
	return 0;
}

int UDPSocketClientBase::init(const char* ipaddr, int port)
{
	SocketBase::init(ipaddr, port);
	s_client_ = socket(AF_INET, SOCK_DGRAM, 0);
	if (s_client_ == INVALID_SOCKET) {
		printf("socket() failed, Error Code:%d/n", WSAGetLastError());
		WSACleanup();
		return -1;
	}
	return 0;
}

int UDPSocketClientBase::sendData(void* _byte, size_t _len)
{
	if (sendto(s_client_, (char*)_byte, (int)_len, 0, (sockaddr*)&server_addr_, sizeof(server_addr_)) == SOCKET_ERROR) {
		printf("recvfrom() failed:%d/n", WSAGetLastError());
		return -1;
	}
	return 0;
}

