#include <stdio.h>
#include <string.h>

// Student data arrays
int studentIds[] = {101, 102, 103, /* ... */};
char studentNames[][50] = {"Alice", "Bob", "Charlie", /* ... */};
float studentCgpas[] = {3.8, 3.5, 3.2, /* ... */};

// Function to swap two integers
void swapInt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to swap two floats
void swapFloat(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Function to swap two strings
void swapString(char a[], char b[]) {
    char temp[50];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

// Function to sort students by name using bubble sort
void sortByName(int ids[], char names[][50], float cgpas[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                swapInt(&ids[j], &ids[j + 1]);
                swapString(names[j], names[j + 1]);
                swapFloat(&cgpas[j], &cgpas[j + 1]);
            }
        }
    }
}

// Function to sort students by ID using selection sort
void sortById(int ids[], char names[][50], float cgpas[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (ids[j] < ids[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swapInt(&ids[i], &ids[minIndex]);
            swapString(names[i], names[minIndex]);
            swapFloat(&cgpas[i], &cgpas[minIndex]);
        }
    }
}

// Function to sort students by CGPA using insertion sort
void sortByCGPA(int ids[], char names[][50], float cgpas[], int n) {
    for (int i = 1; i < n; i++) {
        int keyId = ids[i];
        char keyName[50];
        strcpy(keyName, names[i]);
        float keyCgpa = cgpas[i];
        
        int j = i - 1;
        while (j >= 0 && cgpas[j] > keyCgpa) {
            ids[j + 1] = ids[j];
            strcpy(names[j + 1], names[j]);
            cgpas[j + 1] = cgpas[j];
            j--;
        }
        
        ids[j + 1] = keyId;
        strcpy(names[j + 1], keyName);
        cgpas[j + 1] = keyCgpa;
    }
}

int main() {
    int n = sizeof(studentIds) / sizeof(studentIds[0]);

    // Sort by name
    sortByName(studentIds, studentNames, studentCgpas, n);

    // Print sorted by name
    printf("Sorted by Name:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, CGPA: %.2f\n", studentIds[i], studentNames[i], studentCgpas[i]);
    }

    // Sort by ID
    sortById(studentIds, studentNames, studentCgpas, n);

    // Print sorted by ID
    printf("\nSorted by ID:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, CGPA: %.2f\n", studentIds[i], studentNames[i], studentCgpas[i]);
    }

    // Sort by CGPA
    sortByCGPA(studentIds, studentNames, studentCgpas, n);

    // Print sorted by CGPA
    printf("\nSorted by CGPA:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, CGPA: %.2f\n", studentIds[i], studentNames[i], studentCgpas[i]);
    }

    return 0;
}