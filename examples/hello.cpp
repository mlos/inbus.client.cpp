/*
 * Copyright (c) 2018 Maarten Los
 * See LICENSE.rst for details.
 */

#include <iostream>
#include <inbus/publisher.h>

int main(int argc, char** argv)
{
    std::cout << "NOTE: Make sure you have a subscriber running for 'hello-app'" << std::endl;

    Publisher p("hello-app");
    p.publish("hello,world");
}
