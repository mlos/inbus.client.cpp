/*
 * Copyright (c) 2017,2018 Maarten Los
 * See LICENSE.rst for details.
 */
#ifndef _INBUS_PUBLISHER_H_
#define _INBUS_PUBLISHER_H_

#include <string>

/*!
    \brief Publishes messages to Inbus.
    Refer to <http://inbus.readthedocs.io> for more information.
*/
class Publisher
{
public:
    /*!
        \brief Instantiates an Inbus publisher
        \param appKey Application key
        \param serverIp Inbus server IP
        \param serverPort Inbus server port
    */
    Publisher(const std::string& appKey, 
              const std::string& serverIp = "127.0.0.1",
              int serverPort = 7222);

    virtual~Publisher();
    
    /*!
        \brief Publishes a message to Inbus
        \param payload Payload
        \param appType Application type
        \returns true is sending succeeded
    */
    bool publish(const std::string& payload, int appType = 0);

protected:
    Publisher(const Publisher& other);
    Publisher& operator=(const Publisher& other);
    

private:
    std::string toOutgoingMessage(const std::string& payload, int appType);

    std::string m_appKey;
    std::string m_ip;
    int m_port;
};

#endif /* _INBUS_PUBLISHER_H_ */
