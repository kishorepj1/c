#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NO_OF_DAYS 7

typedef struct {
    char *name_of_day;
    int date_of_day;
    char *activity_descr;
} CALENDER;

void create_calender(CALENDER a[], int i, char name[], int date, char activity[]) {
    a[i].name_of_day = (char *) malloc(strlen(name) + 1);
    strcpy(a[i].name_of_day, name);
    a[i].date_of_day = date;
    a[i].activity_descr = (char *) malloc(strlen(activity) + 1);
    strcpy(a[i].activity_descr, activity);
}

void read_calender(CALENDER a[]) {
    int i, date;
    char name[10], activity[10];
    for (i = 0; i < NO_OF_DAYS; i++) {
        scanf("%s", name);
        scanf("%d", &date);
        scanf("%s", activity);
        create_calender(a, i, name, date, activity);
    }
}

void print_weeks_activity(CALENDER a[]) {
    int i;
    printf("Weeks activity\n");
    for (i = 0; i < NO_OF_DAYS; i++) {
        printf("%-10s : %s\n", a[i].name_of_day, a[i].activity_descr);
    }
}

void free_memory(CALENDER a[]) {
    int i;
    for (i = 0; i < NO_OF_DAYS; i++) {
        free(a[i].name_of_day);
        free(a[i].activity_descr);
    }
}

int main() {
    CALENDER a[NO_OF_DAYS];
    printf("Name Date Activity\n");
    read_calender(a);
    print_weeks_activity(a);
    free_memory(a);
    return 0;
}
