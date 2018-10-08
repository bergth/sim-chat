#include "socketobj.h"

#include <cstdlib>
#include <iostream>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h> 

using namespace std;


Socketobj::Socketobj()
{
    if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        cerr << "Fail initialisation socket" << endl;
        exit(1);
    }
}


void Socketobj::co(std::string addr, int port)
{
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if(inet_pton(AF_INET, addr.c_str(), &serv_addr) <= 0)
    {
        cerr << "Invalid addr format" << endl;
        exit(1);
    }

    if( connect(fd,(const struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        cerr << "Connection failed" << endl;
        exit(1);
    }
}

