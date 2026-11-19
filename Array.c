#include <stdio.h>

struct Student {
    int rollno;
    char name[50];
    int marks[3];
    int total;
    float percentage;
};

int main() {
    struct Student s[100];
    int n, i, j;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &s[i].rollno);

        printf("Enter Name: ");
        // Added a space before %49 to consume the leftover newline from the previous scanf
        scanf(" %49[^\n]", s[i].name); 

        s[i].total = 0;

        for (j = 0; j < 3; j++) {
            printf("Enter marks in subject %d: ", j + 1);
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        s[i].percentage = s[i].total / 3.0;
    }

    printf("\n------ STUDENT RESULTS ------\n");

    for (i = 0; i < n; i++) {
        printf("\nRoll Number: %d", s[i].rollno);
        printf("\nName: %s", s[i].name);
        printf("\nTotal Marks: %d", s[i].total);
        printf("\nPercentage: %.2f%%", s[i].percentage);

        if (s[i].percentage >= 40) {
            printf("\nResult: PASS\n");
        } else {
            printf("\nResult: FAIL\n");
        }
    }

    return 0;
}
