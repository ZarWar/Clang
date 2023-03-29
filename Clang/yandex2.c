#include <stdio.h>
#include 

typedef struct Rocket_ {
    char state;
    int time;
    int minutes;
} Rocket;

int timeCount(Rocket R, int day, int hour, int minute);
int minuteCount(int day, int hour, int minute);

int main() {
    Rocket Rocket_arr[1000000000] = {0};

    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        char state;
        int time;
        int day;
        int hour;
        int minute;
        unsigned int id;

        char str[1000] = {0};

        scanf("%s", str);
        sscanf(str, "%d %d %d %u %[A-Z]c", &day, &hour, &minute, &id, &state);

        if (state == 'A') {
            Rocket_arr[id].state = 'A';
            Rocket_arr[id].minutes = minuteCount(day, hour, minute);
        } else if (state == 'S' || state == 'C') {
            Rocket_arr[id].time += timeCount(Rocket_arr[id], day, hour, minute);
        }
    }

    int flag = 0;
    for(int i = 0; i < 1000000000; i++) {
        if(Rocket_arr[i].time > 0) {
            if(flag == 0) {
                flag = 1;
            } else {
                printf(" ");
            }
            printf("%d", Rocket_arr[i].time);
        }
    }

    return 0;
}

int timeCount(Rocket R, int day, int hour, int minute) {
    return minuteCount(day, hour, minute) - R.minutes;
}

int minuteCount(int day, int hour, int minute) {
    return (day * 24 * 60) + (hour * 60) + minute;
}