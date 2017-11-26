#include "publisher.h"


int main(int argc, char** argv)
{
    Publisher p("super-app", 0, "127.0.0.1", 7222);

    p.publish("hello-from-cpp");

}
