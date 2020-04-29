#pragma once
#include <winsock.h>

#define      BUF_SIZE     1024


class SocketBase
{
public:
	SocketBase() :
		ipaddr_(nullptr), port_(8888),
		precv_buf_(nullptr), psend_buf_(nullptr),
		s_server_(NULL), s_client_(NULL) {
		memset(&server_addr_, 0, sizeof(server_addr_));
		memset(&client_addr_, 0, sizeof(server_addr_));
	}
	SocketBase(const char* ipaddr, int port) :
		ipaddr_(ipaddr), port_(port),
		precv_buf_(nullptr), psend_buf_(nullptr),
		s_server_(NULL), s_client_(NULL) {
		memset(&server_addr_, 0, sizeof(server_addr_));
		memset(&client_addr_, 0, sizeof(server_addr_));
	}

	virtual ~SocketBase() {}

	virtual int init(const char* ipaddr, int port);

	virtual int close();

protected:
	const char* ipaddr_;
	int port_;
	char* precv_buf_, * psend_buf_;

	// 定义服务端套接字，接受请求套接字
	WSADATA wsadata_;
	SOCKET s_server_;
	SOCKET s_client_;
	//服务端地址客户端地址
	SOCKADDR_IN server_addr_;
	SOCKADDR_IN client_addr_;
};


class TCPSocketServerBase : public SocketBase
{
public:
	TCPSocketServerBase() {}
	virtual ~TCPSocketServerBase() {}

	int init(const char* ipaddr, int port) override;

	int recvData(void* _byte, size_t _len);
};

class TCPSocketClientBase : public SocketBase
{
public:
	TCPSocketClientBase() {}
	virtual ~TCPSocketClientBase() {}

	int init(const char* ipaddr, int port) override;

	int sendData(void* _byte, size_t _len);
};


class UDPSocketServerBase : public SocketBase
{
public:
	UDPSocketServerBase() {}
	virtual ~UDPSocketServerBase() {}

	virtual int init(const char* ipaddr, int port) override;

	int recvData(void* _byte, int _len);
};

class UDPSocketClientBase :public SocketBase
{
public:
	UDPSocketClientBase() {}
	virtual ~UDPSocketClientBase() {}

	virtual int init(const char* ipaddr, int port) override;

	int sendData(void* _byte, size_t _len);
};

