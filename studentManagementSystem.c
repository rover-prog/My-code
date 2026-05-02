#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student
{
    char StudentName[50];
    int StudentId;
    float StudentCGPA;
} Student;
typedef struct Student_Container
{
    Student *Point;
    int Size;
    int active_Count;
} Student_Container;
void InitializeContainer(Student_Container *student, int initialSize);
void AddStudent(Student_Container *student, Student s);
void DeleteStudentByID(Student_Container *student, int id);
void SortByID(Student_Container *student);
void SortByName(Student_Container *student);
void SortByCGPA(Student_Container *student);
void PrintStudents(const Student_Container *student);
void FreeContainer(Student_Container *student);
int main()
{

    int size = 0, option = 0, id = 0;
    Student_Container student;
    Student STu;
    printf("Enter initial size: ");
    scanf("%d", &size);
    InitializeContainer(&student, size);
    while (1)
    {
        printf("\n1. Add a new student");
        printf("\n2. Delete a student record by Student ID");
        printf("\n3. Sort student records by ID");
        printf("\n4. Sort student records by Name");
        printf("\n5. Sort student records by CGPA");
        printf("\n6. Print all student records");
        printf("\n7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        getchar();
        if (option == 7)
            break;
        switch (option)
        {
        case 1:
            printf("Enter Name: ");
            fgets(STu.StudentName, 50, stdin);
            STu.StudentName[strcspn(STu.StudentName, "\n")] = '\0'; // Newline character remove
            printf("Enter Id: ");
            scanf("%d", &STu.StudentId);
            printf("Enter CGPA: ");
            scanf("%f", &STu.StudentCGPA);
            AddStudent(&student, STu);
            break;
        case 2:
            printf("Enter Id to Delete: ");
            scanf("%d", &id);
            DeleteStudentByID(&student, id);
            break;
        case 3:
            SortByID(&student);
            break;
        case 4:
            SortByName(&student);
            break;
        case 5:
            SortByCGPA(&student);
            break;
        case 6:
            PrintStudents(&student);
            break;
        default:
            printf("Invalid input...");
            break;
        }
    }
    FreeContainer(&student);
    return 0;
}
void InitializeContainer(Student_Container *student, int initialSize)
{
    student->Point = (Student *)malloc(sizeof(Student) * initialSize);
    if (student->Point == NULL)
        exit(EXIT_FAILURE);
    student->Size = initialSize;
    student->active_Count = 0;
}
void AddStudent(Student_Container *student, Student STu)
{
    Student *storeTemp;
    if (student->active_Count == student->Size)
    {
        storeTemp = (Student *)realloc(student->Point, (sizeof(Student) * (2 * student->Size)));
        if (storeTemp == NULL)
        {
            return;
        }
        else
        {
            student->Point = storeTemp;
            student->Size = (2 * student->Size);
        }
    }
    student->Point[student->active_Count] = STu;
    student->active_Count++;
}
void DeleteStudentByID(Student_Container *student, int id)
{
    int index = -1;
    for (int i = 0; i < student->active_Count; i++)
    {
        if (student->Point[i].StudentId == id)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        for (int i = index; i < student->active_Count - 1; i++)
        {
            student->Point[i] = student->Point[i + 1];
        }
        student->active_Count--;
    }
}
void SortByID(Student_Container *student)
{
    Student key;
    int i, j;
    for (i = 1; i < student->active_Count; i++)
    {
        key = student->Point[i];
        j = i - 1;
        while (j >= 0 && student->Point[j].StudentId > key.StudentId)
        {
            student->Point[j + 1] = student->Point[j];
            j = j - 1;
        }
        student->Point[j + 1] = key;
    }
}
void SortByName(Student_Container *student)
{
    Student key;
    int i, j;
    for (i = 1; i < student->active_Count; i++)
    {
        key = student->Point[i];
        j = i - 1;
        while (j >= 0 && strcmp(student->Point[j].StudentName, key.StudentName) > 0)
        {
            student->Point[j + 1] = student->Point[j];
            j = j - 1;
        }
        student->Point[j + 1] = key;
    }
}
void SortByCGPA(Student_Container *student)
{
    Student key;
    int i, j;
    for (i = 1; i < student->active_Count; i++)
    {
        key = student->Point[i];
        j = i - 1;
        while (j >= 0 && student->Point[j].StudentCGPA < key.StudentCGPA)
        {
            student->Point[j + 1] = student->Point[j];
            j = j - 1;
        }
        student->Point[j + 1] = key;
    }
}
void PrintStudents(const Student_Container *student)
{
    printf("\n\t--- Student Records ---\n");
    printf("%-20s | %-10s | %s\n", "Name", "ID", "CGPA");
    printf("---------------------------------------------\n");
    for (int i = 0; i < student->active_Count; i++)
    {
        printf("%-20s | %-10d | %.2f\n", student->Point[i].StudentName, student->Point[i].StudentId, student->Point[i].StudentCGPA);
    }
    printf("---------------------------------------------\n");
}
void FreeContainer(Student_Container *student)
{
    free(student->Point);
    student->Point = NULL;
    student->active_Count = 0;
    student->Size = 0;
}