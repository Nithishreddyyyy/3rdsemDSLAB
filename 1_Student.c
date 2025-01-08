#include <stdio.h>
#include <string.h>

struct student {
    char Name[50];
    char USN[20];
    int age;
    float cgpa;
};
typedef struct student stud;
void Disp(stud *s){
    printf("\nName: %s\tUSN: %s\tAge: %d\tCGPA: %.2f\n",s->Name,s->USN,s->age,s->cgpa);
}

void input(stud *s){
    while(getchar() != '\n');

    printf("Name : ");
    fgets(s->Name , sizeof(s->Name),stdin);
    s->Name[strcmp(s->Name,"\n")]=0;

    printf("USN: ");
    fgets(s->USN, sizeof(s->USN),stdin);
    s->USN[strcmp(s->USN,"\n")] = 0;

    printf("Age: ");
    scanf("%d",&s->age);

    printf("CGPA: ");
    scanf("%f",&s->cgpa);
}

void dispwithcgpa(stud * std, int n , float target){
    printf("\nStudents with CGPA:");
    int found = 0;

    for (int i = 0; i<n ; i++){
        if(std[i].cgpa >= target){
            printf("\nStudent");
            Disp(&std[i]);
            found = 1;
        }
    }
    if (found == 0){
        puts("no students with CGPA");
    }
}

int main(){
    int n;
    float target;

    printf("Enter number of students:");
    scanf("%d",&n);
    stud student[n];

    for (int i = 0; i < n ; i++){
        printf("Enter details for students %d",i+1);
        input(&student[i]);
    }

    printf("Student details are: ");
    for (int i = 0 ; i<n ; i++){
        Disp(&student[i]);
    }
    printf("enter target:");
    scanf("%f",&target);

    dispwithcgpa(student, n,target);

    return 0;
}
