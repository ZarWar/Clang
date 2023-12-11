#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define STATUS_400 "сервер обнаружил в запросе клиента синтаксическую ошибку. Появился в HTTP/1.0."
#define STATUS_401 "для доступа к запрашиваемому ресурсу требуется аутентификация. В заголовке ответ должен содержать поле WWW-Authenticate с перечнем условий аутентификации. Иными словами, для доступа к запрашиваемому ресурсу клиент должен представиться, послав запрос, включив при этом в заголовок сообщения поле Authorization с требуемыми для аутентификации данными. Если запрос уже включает данные для авторизации, ответ 401 означает, что в авторизации с ними отказано."
#define STATUS_402 "сервер обнаружил в запросе клиента синтаксическую ошибку. Появился в HTTP/1.0."

void question(char);

int main() {

    while(true) {

        char answer[30] = "\0";
        int count = 0;
        char c;
        int i = 0;

        switch (count) {

            case 0:
                printf("400 ? :\n");

                while( (c = getchar()) != '\n' ) {
                    answer[i++] = c;
                }

                if (strcmp(answer, "Bad Request") == 0) {
                    sleep(1);
                    printf("%s\n\n", STATUS_400);
                } else {
                    printf("Try again (y/n)\n");

                    if((c = getchar()) == 'y') {
                        break;
                    } else {
                        count++;
                    }
                }

                for (i = 0; i < sizeof(answer); i++) {
                    answer[i] = '\0';
                }

            case 1:
                printf("401 ? :\n");

                while( (c = getchar()) != '\n' ) {
                    answer[i++] = c;
                }

                if (strcmp(answer, "Unauthorized") == 0) {
                    sleep(1);
                    printf("%s\n\n", STATUS_401);
                } else {
                    printf("Try again (y/n)\n");

                    if((c = getchar()) == 'y') {
                        ;
                    } else {
                        count++;
                        break;
                    }
                }

            case 2:
                printf("402 ? :\n");

                while( (c = getchar()) != '\n' ) {
                    answer[i++] = c;
                }

                if (strcmp(answer, "Payment Required") == 0) {
                    sleep(1);
                    printf("предполагается использовать в будущем[когда?]. В настоящий момент[когда?] не используется. Этот код предусмотрен для платных пользовательских сервисов, а не для хостинговых компаний. Имеется в виду, что эта ошибка не будет выдана хостинговым провайдером в случае просроченной оплаты его услуг. Зарезервирован, начиная с HTTP/1.1.\n\n");
                } else {
                    printf("Try again (y/n)\n");

                    if((c = getchar()) == 'y') {
                        ;
                    } else {
                        count++;
                    }
                }

            default:
                count = 0;
        }

    }

}

void question(char) {

    char answer[30] = "\0";
    int count = 0;
    char c;
    int i = 0;    

    printf(" ? :\n");

    while( (c = getchar()) != '\n' ) {
        answer[i++] = c;
    }

    if (strcmp(answer, "Unauthorized") == 0) {
        sleep(1);
        printf("%s\n\n", STATUS_401);
    } else {
        printf("Try again (y/n)\n");

        if((c = getchar()) == 'y') {
            ;
        } else {
            count++;
        }
    }

}