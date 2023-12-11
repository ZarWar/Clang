#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define STATUS_400 "сервер обнаружил в запросе клиента синтаксическую ошибку. Появился в HTTP/1.0."
#define STATUS_401 "для доступа к запрашиваемому ресурсу требуется аутентификация. В заголовке ответ должен содержать поле WWW-Authenticate с перечнем условий аутентификации. Иными словами, для доступа к запрашиваемому ресурсу клиент должен представиться, послав запрос, включив при этом в заголовок сообщения поле Authorization с требуемыми для аутентификации данными. Если запрос уже включает данные для авторизации, ответ 401 означает, что в авторизации с ними отказано."
#define STATUS_402 "сервер обнаружил в запросе клиента синтаксическую ошибку. Появился в HTTP/1.0."

void question(char *status, char *status_explanation, char *check);

int main() {

    while(true) {

        int count = 0;

        switch (count) {

        case 0:
            question("400", STATUS_400, "Bad Request");
            count++;

        case 1:
            question("401", STATUS_401, "Unauthorized");
            count++;

        default:
            count = 0;
        }

    }

}

void question(char *status, char *status_explanation, char *check) {

    char answer[30] = "\0";
    int  i = 0;    
    char c;

    printf("%s ? :\n", status);

    while( (c = getchar()) != '\n' ) {
        answer[i++] = c;
    }

    if (strcmp(answer, check) == 0) {
        sleep(1);
        printf("%s\n\n", status_explanation);
        sleep(1);
    }

}