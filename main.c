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
    int score;
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
    int score;
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
            case 7: get_lesson_statistics(); break;
            default: printf("Invalid choice, try again.\n");
        }
    } 
    
while (choice != 8);               // 8 kiritganda dastur o'chishi uchun
}

void add_student() {
    students = realloc(students, (student_count + 1) * sizeof(Student));    // realloc orqali xotira kengaytrildi
    if (!students) {
        printf("Memory allocation failed!\n");
        exit(1); 
    }
    
    // studentni malumotlarini kiritadi 

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

    // student_count qushilgan talabalr sonini hisoblab boradi 

    student_count++;                                 
    printf("Student added successfully!\n");
}
void get_students(){             // O'quvchilar ro'yatini chiqaradi 
    if (student_count > 0){  // talabalar kiritilgan bulsa ishlaydigan qilib shart qo'yib oldik aks holda talaba kiritshni suraydi
        printf(" ID   | First Name | Last Name | Age | Phone        | Email                    | Parent's Name | Parent's Phone | Parent's Email");
        printf("---------------------------------------------------------------------------------------------------------------------------------\n");
            for (int  i = 0; i < student_count; i++){    
                printf("%-3d", i + 1);
                printf("| %-10s ", students[i].first_name);
                printf("| %-9s ", students[i].last_name);
                printf("| %-3d ", students[i].age);
                printf("| %-12s ", students[i].contact.phone);
                printf("| %-23s ", students[i].contact.email);
                printf("| %-13s ", students[i].parent.name);
                printf("| %-14s ", students[i].parent.contact.phone);
                printf("| %s\n", students[i].parent.contact.email);
            }
        }
        
        else{
            printf("O'quvchilar  yo'q");   // Agar o'quvchilar kiritilmagan bo'lsa 
        }
        
    
} void get_student_detail(){            // O'quvchining to'liq ma'lumotlarini chiqaradigan funksiya 
    int id;
    printf("O'quvchining ID sini kiriting :");      // O'quvchining id si orqali uning ma'lumotlarini chiqaradi 
    scanf("%d",&id);

    // Agar talabar 0 dan ko'p bulsa uning maluumaotlarini chiqarib beradigan vunkisya va shart

    if (id-1 <= student_count && student_count != 0){
        printf("First Name: %s\n", students[id - 1].first_name);
        printf("Last Name : %s\n", students[id - 1].last_name);
        printf("Age : %d\n", students[id - 1].age);
        printf("Phone: %s\n", students[id - 1].contact.phone);
        printf("Email: %s\n", students[id - 1].contact.email);
        printf("Parent's Name: %s\n", students[id - 1].parent.name);
        printf("Parent's Phone: %s\n", students[id - 1].parent.contact.phone);
        printf("Parent's Email: %s\n", students[id - 1].parent.contact.email);
    }
    else  printf("Bunday ID raqamda o'quvchi mavjud emas ");     // Agar o'quvchining ID si no'to'g'ri bo'lsa 

}void get_student_by_name(){        // O'quvchini ismi bo'yicha qidiriish
    char search[40];
    printf("Talabaning ismini kiriting ");
    scanf("%s",search);

    
    for (int i = 0; i < student_count; i++){
        if (strstr(students[i].first_name,search)){         // Qidirilgan o'quvchiga mosligini teklshiradi 
                printf(" ID   | First Name | Last Name | Age | Phone        | Email                    | Parent's Name | Parent's Phone | Parent's Email");
                printf("%-3d", i + 1);
                printf("| %-10s ", students[i].first_name);
                printf("| %-9s ", students[i].last_name);
                printf("| %-3d ", students[i].age);
                printf("| %-12s ", students[i].contact.phone);
                printf("| %-23s ", students[i].contact.email);
                printf("| %-13s ", students[i].parent.name);
                printf("| %-14s ", students[i].parent.contact.phone);
                printf("| %s\n", students[i].parent.contact.email);
        }

        // Qidirilganda talaba chiqmagan holatda bu shartimiz ishlaydi 
        else {
            printf("Ayni vaqtda bunday o'quvchi yo'q");
        
        }
        
        
    }

}void add_lesson(){             // Yangi dars qo'shildi
    lessons = realloc(lessons,(lesson_count+1)*sizeof(Lesson));   // realoc orqali joy kengaytirildi 
    if (!lessons){
        printf("Memory allocation failed!\n");    
        exit(1);
    }

    // Darslarni qushish uchun 

    printf("Dars mavzusini kiriting :");
    scanf("%s",lessons[lesson_count].name);
    lesson_count ++;                    
    printf("Lesson added successfully!\n");

}void list_lessons(){   // Darslarni jadval kurinishida chiqarishni taminlaydi            
    
    printf("%-3s| %-64s|\n", "ID", "Name");
    for(int i = 0; i < 56; i++){
        printf("-");
    }
    printf("\n");
    for(int i = 0; i < lesson_count; i++){
        printf("%-3d| %-1s\n", lessons[i].id, lessons[i].name);
    }
}

void list_scores(){               
    
    printf("%-3s| %-15s| %-15s| %-5s| %s\n",
        "ID", "First Name", "Last Name", "Score", "Lesson name"
    );
    
    for(int i = 0; i < student_count; i++) 
    printf("-");
    printf("\n");
    for(int i = 0; i < score_count; i++){
        printf("%-3d| %-15s| %-15s| %-5d| %s\n",
            i, scores[i].student.first_name,
            scores[i].student.last_name, scores[i].score,
            scores[i].lesson.name
        );
    }

}


