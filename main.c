#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
typedef struct {
    char phone[15];
    char email[50];
} Contact;

typedef struct {
    char name[15];
    Contact contact;
} Parent;

typedef struct {
    char first_name[50];
    char last_name[50];
    int age;
    Contact contact;
    Parent parent;
} Student;

typedef struct {
    int id;
    char name[122];
} Lesson;

typedef struct {
    Lesson lesson;
    Student student;
} Score;

// Global Variables
Student* students = NULL;
int student_count = 0;

Lesson* lessons = NULL;
int lesson_count = 0;

Score* scores = NULL;
int score_count = 0;

// Function Prototypes
void add_student();
void get_students();
void get_student_detail();
void get_student_by_name();
void add_lesson();
void add_score();
void get_lesson_statistics();
void menu();

// Main Function
int main() {
    menu();
    // Free allocated memory before exiting
    free(students);
    free(lessons);
    free(scores);
    return 0;
}

// Function Definitions
void menu() {
    int choice;
    do {
        printf("\n1. Add Student\n2. View Students\n3. View Student Details\n4. Find Student by Name\n5. Add Lesson\n6. Add Score\n7. Get Lesson Statistics\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_student(); break;
            case 2: get_students(); break;
            case 3: get_student_detail(); break;
            case 4: get_student_by_name(); break;
            case 5: add_lesson(); break;
            case 6: add_score(); break;
            case 7: get_lesson_statistics(); break;
            case 8: printf("Exiting...\n"); break;
            default: printf("Invalid choice, try again.\n");
        }
    } while (choice != 8);
}

void add_student() {
    students = realloc(students, (student_count + 1) * sizeof(Student));
    if (!students) {
        printf("Memory allocation failed!\n");
        exit(1); // dasturni ishini yakunlash
    }

    printf("Enter first name: ");
    scanf("%s", students[student_count].first_name);

    printf("Enter last name: ");
    scanf("%s", students[student_count].last_name);

    printf("Enter age: ");
    scanf("%d", &students[student_count].age);

    printf("Enter phone: ");
    scanf("%s", students[student_count].contact.phone);

    printf("Enter email: ");
    scanf("%s", students[student_count].contact.email);

    printf("Enter parent's name: ");
    scanf("%s", students[student_count].parent.name);

    printf("Enter parent's phone: ");
    scanf("%s", students[student_count].parent.contact.phone);

    printf("Enter parent's email: ");
    scanf("%s", students[student_count].parent.contact.email);

    student_count++;
    printf("Student added successfully!\n");
}

// yuqoridagi misoldan qarab bajarish mumkin