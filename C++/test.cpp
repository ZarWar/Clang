#include <stdio.h>
#include <stdint.h>
#include <sys/socket.h>

int main() {

    int i = 2100;
    int c = i % 4;
    printf("%d\n", c);


    // printf("%d\n", SOMAXCONN);
    // printf("%lu\n", SIZE_MAX);

    // int s = socket(AF_INET, SOCK_DGRAM, 0);
    // printf("%d\n", s);

    // struct sockaddr sa;
}