#include <stdio.h>
#include <string.h>

struct student {
    char Name[50];
    char USN[20];
    int age;
    float cgpa;
};
typedef struct student stud;

void Disp(stud *s) {
    printf("\nName: %s\tUSN: %s\tAge: %d\tCGPA: %.2f\n", s->Name, s->USN, s->age, s->cgpa);
}

void input(stud *s) {
    while (getchar() != '\n'); // Clear input buffer
    printf("Name: ");
    fgets(s->Name, sizeof(s->Name), stdin);
    s->Name[strcspn(s->Name, "\n")] = 0; // Remove trailing newline

    printf("USN: ");
    fgets(s->USN, sizeof(s->USN), stdin);
    s->USN[strcspn(s->USN, "\n")] = 0; // Remove trailing newline

    printf("Age: ");
    scanf("%d", &s->age);
    printf("CGPA: ");
    scanf("%f", &s->cgpa);
}

void dispWithCGPA(stud *std, int n, float target) {
    printf("\nStudents with CGPA >= %.2f:\n", target);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (std[i].cgpa >= target) {
            Disp(&std[i]);
            found = 1;
        }
    }
    if (!found) {
        puts("No students with the specified CGPA.");
    }
}

int main() {
    int n;
    float target;

    printf("Enter number of students: ");
    scanf("%d", &n);

    stud student[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        input(&student[i]);
    }

    printf("\nStudent details:\n");
    for (int i = 0; i < n; i++) {
        Disp(&student[i]);
    }

    printf("\nEnter target CGPA: ");
    scanf("%f", &target);
    dispWithCGPA(student, n, target);

    return 0;
}
