# 
file (STRINGS VERSION.txt VERSION )
file (WRITE src/version.h  "const char *inbus_client_library_version=\"Version: ${VERSION}\";\n\n")
cmake_minimum_required (VERSION 2.6)
project (abc)

add_library(inbusclient src/publisher.cpp)
