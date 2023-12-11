#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define STATUS_400 "сервер обнаружил в запросе клиента синтаксическую ошибку. Появился в HTTP/1.0."
#define STATUS_401 "для доступа к запрашиваемому ресурсу требуется аутентификация. В заголовке ответ должен содержать поле WWW-Authenticate с перечнем условий аутентификации. Иными словами, для доступа к запрашиваемому ресурсу клиент должен представиться, послав запрос, включив при этом в заголовок сообщения поле Authorization с требуемыми для аутентификации данными. Если запрос уже включает данные для авторизации, ответ 401 означает, что в авторизации с ними отказано."
#define STATUS_402 "сервер обнаружил в запросе клиента синтаксическую ошибку. Появился в HTTP/1.0."

int main() {
    char answer[30] = "\0";
    char test[30] = "\0";
    int  check = 0;
    int  u = 0;
    int  i;
    char c;
    char b;

    while (true) {

        // стираем данные из массивов
    
        for (int j = 0; j < 30; j++) {
            answer[j] = '\0';
            test[j] = '\0';
        }



        // запрашиваем ответ

        printf("400 ?\n");
        printf("Please, type your answer: ");

        i = 0;
        while( (c = getchar()) != '\n' && c != EOF ) {
            answer[i++] = c;
        }
        printf("answer = '%s'\n", answer);



        // проверяем правильность ответа

        while ((strcmp(answer, "Bad Request") != 0)) {

            if (check == 0) {
                sleep(1);
                printf("Wrong. Retry? y/n: ");
            } else {
                check = 0;
            }

            b = getchar();

            if (b  == 'y') {
                fflush(stdin);
                sleep(1);
                printf("\n");
                break;
            } else if (b == 'n') {
                fflush(stdin);
                sleep(1);
                break;
            } else {
                check = 1;
                fflush(stdin);
                sleep(1);
                printf("Please, input only 'y' or 'n': ");
                continue;
            }
        }

        // выводим правильный ответ

        if ((strcmp(answer, "Bad Request") == 0)) {
            sleep(1);
            printf("\nYour were right! The description is:\n%s\n\n", STATUS_400);
            sleep(1);
        }
    }
}