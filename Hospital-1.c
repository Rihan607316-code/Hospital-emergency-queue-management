#include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient {
    char id[20];
    char name[50];
    int age;
    char emergency[20];
    int priority;
};

struct Patient queue[MAX];
int count = 0;

/* Add Default 4 Patients */
void loadPatients() {

    strcpy(queue[0].id, "BC 2025 503");
    strcpy(queue[0].name, "Rehan");
    queue[0].age = 18;
    strcpy(queue[0].emergency, "emergency");
    queue[0].priority = 3;

    strcpy(queue[1].id, "BC 2025 502");
    strcpy(queue[1].name, "gulsan");
    queue[1].age = 19;
    strcpy(queue[1].emergency, "Normal");
    queue[1].priority = 3;

    strcpy(queue[2].id, "BC 2025 532");
    strcpy(queue[2].name, "sahil");
    queue[2].age = 20;
    strcpy(queue[2].emergency, "Serious");
    queue[2].priority = 3;

    strcpy(queue[3].id, "BC 2025 501");
    strcpy(queue[3].name, "Amar");
    queue[3].age = 21;
    strcpy(queue[3].emergency, "Critical");
    queue[3].priority = 3;

    count = 4;
}

/* Add New Patient */
void addPatient() {

    if (count == MAX) {
        printf("\nQueue is full!\n");
        return;
    }

    struct Patient p;

    printf("\nEnter Patient ID: ");
    scanf(" %[^\n]", p.id);

    printf("Enter Patient Name: ");
    scanf(" %[^\n]", p.name);

    printf("Enter Age: ");
    scanf("%d", &p.age);

    printf("\nEmergency Level:\n");
    printf("1. Critical\n");
    printf("2. Serious\n");
    printf("3. Normal\n");
    printf("Enter choice: ");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        strcpy(p.emergency, "Critical");
        p.priority = 1;
    }
    else if (choice == 2) {
        strcpy(p.emergency, "Serious");
        p.priority = 2;
    }
    else if (choice == 3) {
        strcpy(p.emergency, "Normal");
        p.priority = 3;
    }
    else {
        printf("\nInvalid emergency level!\n");
        return;
    }

    /* Insert according to priority */
    int i = count - 1;

    while (i >= 0 && queue[i].priority > p.priority) {
        queue[i + 1] = queue[i];
        i--;
    }

    queue[i + 1] = p;
    count++;

    printf("\nPatient registered successfully!\n");
}

/* Send Next Patient */
void nextPatient() {

    if (count == 0) {
        printf("\nNo patient in waiting queue.\n");
        return;
    }

    printf("\n========== NEXT PATIENT ==========\n");
    printf("Patient ID   : %s\n", queue[0].id);
    printf("Patient Name : %s\n", queue[0].name);
    printf("Age          : %d\n", queue[0].age);
    printf("Emergency    : %s\n", queue[0].emergency);
    printf("Priority     : %d\n", queue[0].priority);

    /* Remove first patient */
    for (int i = 0; i < count - 1; i++) {
        queue[i] = queue[i + 1];
    }

    count--;

    printf("\nPatient sent to doctor successfully.\n");
}

/* Display Patients */
void displayPatients() {

    if (count == 0) {
        printf("\nNo waiting patients.\n");
        return;
    }

    printf("\n================ WAITING PATIENTS ================\n");

    printf("%-15s %-15s %-5s %-12s %-8s\n",
           "Patient ID", "Name", "Age", "Emergency", "Priority");

    printf("--------------------------------------------------\n");

    for (int i = 0; i < count; i++) {

        printf("%-15s %-15s %-5d %-12s %-8d\n",
               queue[i].id,
               queue[i].name,
               queue[i].age,
               queue[i].emergency,
               queue[i].priority);
    }
}

/* Search Patient */
void searchPatient() {

    if (count == 0) {
        printf("\nNo patients in queue.\n");
        return;
    }

    char id[20];

    printf("\nEnter Patient ID to search: ");
    scanf(" %[^\n]", id);

    for (int i = 0; i < count; i++) {

        if (strcmp(queue[i].id, id) == 0) {

            printf("\n========== PATIENT FOUND ==========\n");
            printf("Patient ID   : %s\n", queue[i].id);
            printf("Patient Name : %s\n", queue[i].name);
            printf("Age          : %d\n", queue[i].age);
            printf("Emergency    : %s\n", queue[i].emergency);
            printf("Priority     : %d\n", queue[i].priority);
            printf("Position     : %d\n", i + 1);

            return;
        }
    }

    printf("\nPatient not found.\n");
}

/* Main */
int main() {

    int choice;

    /* Load 4 patients at program start */
    loadPatients();

    do {

        printf("\n\n==============================================");
        printf("\n     HOSPITAL EMERGENCY QUEUE MANAGEMENT");
        printf("\n==============================================");
        printf("\n1. Patient Registration");
        printf("\n2. Send Next Patient to Doctor");
        printf("\n3. Display Waiting Patients");
        printf("\n4. Search Patient");
        printf("\n5. Total Patients Count");
        printf("\n6. Exit");
        printf("\n==============================================");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addPatient();
                break;

            case 2:
                nextPatient();
                break;

            case 3:
                displayPatients();
                break;

            case 4:
                searchPatient();
                break;

            case 5:
                printf("\nTotal Waiting Patients: %d\n", count);
                break;

            case 6:
                printf("\nThank you! Hospital Queue System Closed.\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}