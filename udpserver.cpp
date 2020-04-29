#include <iostream>
#include "socketbase.h"


#if 0
int main()
{
    UDPSocketServerBase server;
    server.init("127.0.0.1", 9800);
    char* recvbuf = new char[100];

    while (1)
    {
        memset(recvbuf, 0, sizeof(recvbuf));
        if (server.recvData(recvbuf, 100) != 0) { // 接收状态不正确
            break;
        }
        if (strcmp(recvbuf, "20") == 0)
            break;
        std::cout << "Server receive##   " << recvbuf << "   ##\n";
    }

    delete[] recvbuf;
    server.close();
    system("pause");
    return 0;
}
#endif

