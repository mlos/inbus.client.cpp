/*
 * Copyright (c) 2017 Maarten Los
 * See LICENSE.rst for details.
 */
#ifndef _INBUS_PUBLISHER_H_
#define _INBUS_PUBLISHER_H_

#include <string>

class Publisher
{
public:
    Publisher(const std::string& appKey, int appCode, const std::string& serverIp, int serverPort);
    virtual~Publisher();

    bool publish(const std::string& payload);

protected:
    Publisher(const Publisher& other);
    Publisher& operator=(const Publisher& other);
    

private:
    std::string toOutgoingMessage(const std::string& payload);

    std::string m_appKey;
    int m_appCode;
    std::string m_ip;
    int m_port;
};

#endif /* _INBUS_PUBLISHER_H_ */
