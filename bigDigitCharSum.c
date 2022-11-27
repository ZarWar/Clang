#include <stdio.h>

int main() {
    char value1[10] = {0};
    char value2[10] = {0};
    char value3[10] = {0};
    
    int countDigits = 0;
    int digit1;
    int digit2;
    int digit3;

    scanf("%s", value1);
    scanf("%s", value2);

    for(int i = strlen(value1); i >= 0; i--) {
        while(countDigits < 5 && value1[i] != '\0' || countDigits < 5 && value2[i] != '\0') {
            countDigits++;
            if(countDigits == 5) {
                value3;
            }
            digit1 = value1[i];
            digit2 = value2[i];
            digit3 = digit1 + digit2;
            if(digit3 % 10 != 0) {
                
            }

        }
    }

    
    printf("%s %s\n", value1, value2);

    return 0;
}