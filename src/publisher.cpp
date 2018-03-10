/*
 * Copyright (c) 2017,2018 Maarten Los
 * See LICENSE.rst for details.
 */
#include "version.h"

#include "publisher.h"

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sstream>


Publisher::Publisher(const std::string& appKey,
                     const std::string& serverIp,
                     int serverPort) :
     m_appKey(appKey), m_ip(serverIp), m_port(serverPort)
{
}

Publisher::~Publisher()
{
}

bool Publisher::publish(const std::string& payload, int appType)
{
    int sock;
    if((sock = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
        return false;

    struct sockaddr_in serverAddr;
    bzero((char*)&serverAddr, sizeof(serverAddr));
    serverAddr.sin_addr.s_addr = inet_addr(m_ip.c_str());
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(m_port);

    std::string message = toOutgoingMessage(payload, appType);
    return (sendto(sock, 
                (void*)message.c_str(), message.length(), 0, 
                (struct sockaddr*)&serverAddr, sizeof(serverAddr)) >= 0);
}

std::string Publisher::toOutgoingMessage(const std::string& payload, int appType)
{
    std::stringstream json;

    json << "{" 
        << "\"version\":1,"
        << "\"opcode\":3,"
        << "\"application\":[\"" << m_appKey << "\", " << appType << "],"
        << "\"address\":[\"\",0],"
        << "\"payload\":\"" << payload << "\""
        <<  "}";

    return json.str();
}
