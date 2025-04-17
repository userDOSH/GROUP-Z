#include <stdio.h>

enum ExerciseType { RUNNING = 1, SWIMMING, CYCLING };


int calculateCalories(enum ExerciseType type, int duration) {
    switch (type) {
        case RUNNING:
            return duration * 10;
        case SWIMMING:
            return duration * 8;
        case CYCLING:
            return duration * 6;
        default:
            return 0;
    }
}

void displayResults(enum ExerciseType type, int duration, int calories) {
    char *exerciseName;
    switch (type) {
        case RUNNING:
            exerciseName = "Running";
            break;
        case SWIMMING:
            exerciseName = "Swimming";
            break;
        case CYCLING:
            exerciseName = "Cycling";
            break;
        default:
            exerciseName = "Unknown";
    }

    printf("\n--- Exercise Summary ---\n");
    printf("Type       : %s\n", exerciseName);
    printf("Duration   : %d minutes\n", duration);
    printf("Calories   : %d kcal\n", calories);
    printf("------------------------\n");
}

int main() {
    int type, duration;
    char choice;

    do {
        printf("\nSelect Exercise Type:\n");
        printf("1. Running\n");
        printf("2. Swimming\n");
        printf("3. Cycling\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &type);

        if (type < 1 || type > 3) {
            printf("Invalid exercise type . Try again.\n");
            continue;
        }

        printf("Enter duration in minutes: ");
        scanf("%d", &duration);

        int calories = calculateCalories((enum ExerciseType)type, duration);
        displayResults((enum ExerciseType)type, duration, calories);

        printf("Do you want to enter another entry?\n 1.yes\n 2.NO\n: ");
        scanf(" %c", &choice);

    } while (choice == '1' || choice == '1');

    printf("Thank you for using the Z.GROUP Fitness!\n");

    return 0;
}