#include <stdio.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFSIZE 5

int main(int argc, char **argv) {
    int MasterSocket = socket(
        AF_INET,
        SOCK_STREAM,
        IPPROTO_TCP);
    
    struct sockaddr_in SockAddr;
    SockAddr.sin_family = AF_INET;
    SockAddr.sin_port =  htons(12345);
    SockAddr.sin_addr.s_addr =  htonl(INADDR_ANY); // 0.0.0.0
    bind(MasterSocket, (struct sockaddr *)(&SockAddr), sizeof(SockAddr)); // заменить это на что-то другой (struct sockaddr *)(&SockAddr)

    listen(MasterSocket, SOMAXCONN);

    /* здесь я вынес дескриптор SlaveSocket перед "бесконечным" циклом while, 
       чтобы внутри цикла он не создавался заново */
    int SlaveSocket = accept(MasterSocket, 0, 0);

    /* также инициализировал Buffer перед циклом, чтобы внутри цикла
       лишь стирать данные вниутри него */
    char Buffer[BUFFSIZE] = {'\0'};

    while(1) {
        for(int i = 0; i < BUFFSIZE; i++) {
            if(Buffer[i] == '\0') { // типа "умная" очистка, не прогоняет Buffer целиком, а только до первого "нуля"
                break;
            }
            Buffer[i] = ('\0');
        }
        
        recv(SlaveSocket, Buffer, BUFFSIZE, MSG_WAITALL);
        printf("recv '%s'\n", Buffer);
        send(SlaveSocket, Buffer, BUFFSIZE, MSG_WAITALL);
        printf("send '%s'\n", Buffer);

        /* чтобы закрыть соединение, пишу слово 'close' */
        if(Buffer[0] == 'c' &&
           Buffer[1] == 'l' &&
           Buffer[2] == 'o' &&
           Buffer[3] == 's' &&
           Buffer[4] == 'e'
        ) {
            shutdown(SlaveSocket, SHUT_RDWR);
            close(SlaveSocket);
            shutdown(MasterSocket, SHUT_RDWR); // этот сокет закрывается неправильно
            close(MasterSocket);
            break;
        }

        printf("%s", Buffer);
    }

    return 0;
}