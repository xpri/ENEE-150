#include <stdio.h>
#include <math.h>

struct Polar {
    double radius;
    double theta; // in radians
};

struct Rectangular {
    double rectx;
    double recty;
};

void polarToRectangular(double radius, double theta, double *rectx, double *recty) {
    *rectx = radius * cos(theta);
    *recty = radius * sin(theta);
}

void rectangularToPolar(double rectx, double recty, double *radius, double *theta) {
    *radius = sqrt(rectx * rectx + recty * recty);
    *theta = atan2(recty, rectx);
}

void displayMenu() {
    printf("Menu:\n");
    printf("1. Convert Polar to Rectangular\n");
    printf("2. Convert Rectangular to Polar\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 1) {
            double radius, theta, rectx, recty;
            printf("Enter radius: ");
            scanf("%lf", &radius);
            printf("Enter theta (in radians): ");
            scanf("%lf", &theta);

            polarToRectangular(radius, theta, &rectx, &recty);
            printf("Rectangular form: x = %.2lf, y = %.2lf\n", rectx, recty);
        } else if (choice == 2) {
            double rectx, recty, radius, theta;
            printf("Enter x: ");
            scanf("%lf", &rectx);
            printf("Enter y: ");
            scanf("%lf", &recty);

            rectangularToPolar(rectx, recty, &radius, &theta);
            printf("Polar form: radius = %.2lf, theta = %.2lf radians\n", radius, theta);
        } else if (choice != 3) {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    printf("Exiting program. Goodbye!\n");
}
