#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

char *getPath(char* req) {
    int i = 0;
    
    while (req[i++] != ' ');
    
    char *path = (char *) calloc(128, sizeof(char));
    int y = 0;

    while (req[i] != ' ') { path[y++] = req[++i]; }

    path[--y] = '\0';

    return path;
}

char *getContent(char *path) {
    FILE *fp;

    char *content = (char *) calloc(8192, sizeof(char));

    if((fp = fopen(path, "r")) == NULL) {
        strcat(content,  "Cannot open file.\n\0");
        return content;
    }

    int i = 0;
    char c;
    while ((c = getc(fp)) != EOF) {
        content[i++] = c;
    }

    fclose(fp);

    return content;
}

char *constructResp(char *content) {
    char *resp = (char *) calloc(8192, sizeof(char));

    sprintf(resp,  "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: %li\n\n", strlen(content));

    strcat(resp, content);    
    strcat(resp, "\n\n\0");
    printf("%s", resp);

    return resp;
}

int main(int argc, char **argv) {
    int MasterSocket = socket(
        AF_INET,
        SOCK_STREAM,
        IPPROTO_TCP);

    struct sockaddr_in SockAddr;
    SockAddr.sin_family = AF_INET;
    SockAddr.sin_port =  htons(12348);
    SockAddr.sin_addr.s_addr =  htonl(INADDR_ANY); // 0.0.0.0
    bind(MasterSocket, (struct sockaddr*)(&SockAddr), sizeof(SockAddr));

    listen(MasterSocket, SOMAXCONN);

    while(1) {
        int SlaveSocket = accept(MasterSocket, 0, 0);

        char buffer[1024];
        recv(SlaveSocket, buffer, 1024, MSG_NOSIGNAL);
        printf("%s\n", buffer);

        char *path    = getPath(buffer);
        char *content = getContent(path); 
        char *resp    = constructResp(content);

        send(SlaveSocket, resp, strlen(resp), MSG_NOSIGNAL);
        shutdown(SlaveSocket, SHUT_RDWR);

        free(path);
        free(content);
        free(resp);

        close(SlaveSocket);
    }

    return 0;
}