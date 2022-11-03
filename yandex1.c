#include <stdio.h>
#include <string.h>

int sumNumbers(int N);

int main() {
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        char str[1000];
        char name[16]={0};
        char surname[16]={0};
        char patronymic[16]={0};
        int day, month, year;
        int distinctChar = 0;

        scanf("%s", str);
        if(i > 0) {
            printf(" ");
        }
        sscanf(str, "%[a-zA-Z],%[a-zA-Z],%[a-zA-Z],%d,%d,%d", surname, name, patronymic, &day, &month, &year);

        // printf("%s %s %s %d %d %d\n", surname, name, patronymic, day, month, year);
       
        char hash[256] = {0};
    
        for(int j = 0; j < strlen(name); j++) {
            hash[name[j]] = 1;
        }
    
        for(int j = 0; j < strlen(surname); j++) {
            hash[surname[j]] = 1;
        }
    
        for(int j = 0; j < strlen(patronymic); j++) {
            hash[patronymic[j]] = 1;
        }

        for(int j = 0; j < 256; j++) {
            if(hash[j] == 1) {
                distinctChar++;
            }
        }

        int date64 = (sumNumbers(day) + sumNumbers(month)) * 64;

        int sur256 = (surname[0] - 64) * 256;

        int heximal = date64 + sur256 + distinctChar;
        if(heximal >= 0x1000) {
            heximal %= 0x1000;
        }
        printf("%0.3X", heximal);
    }

    return 0;
}

int sumNumbers(int N) {
    if(N < 10) {
        return N;
    } else if (N > 10 && N < 20) {
        return N - 10 + 1;
    } else if (N > 20 && N < 30) {
        return N - 20 + 2;
    } else if (N == 31) {
        return 4;
    } else {
        return N/10;
    }
}