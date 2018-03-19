/*
 * Copyright (c) 2018 Maarten Los
 * See LICENSE.rst for details.
 */

#include <iostream>
#include <stdlib.h>

#include <inbus/publisher.h>

int main(int argc, char** argv)
{
    if(argc < 3)
    {
        std::cerr << "Usage: " << argv[0] << " <message> <app-name> [<app-type>]" << std::endl;
        exit(1);
    }

    int appType = 0;
    if(argc == 4)
    {
        appType = atoi(argv[3]);
    }
         
    Publisher p(argv[2]);

    p.publish(argv[1], appType);
}
