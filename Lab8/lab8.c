#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char lName[50];
    char fName[50];
    char studentNum[20];
    int  midGrade;
    int  finalGrade;
} Student;

void swap(Student *a, Student *b) 
{
    Student tmp = *a;
    *a = *b;
    *b = tmp;
}

int comesBefore(const Student *x, const Student *y) 
{
    int r = strcmp(x->lName, y->lName);
    if (r) return r < 0;
    r = strcmp(x->fName, y->fName);
    if (r) return r < 0;
    r = strcmp(x->studentNum, y->studentNum);
    if (r) return r < 0;
    if (x->midGrade != y->midGrade)   return x->midGrade < y->midGrade;
    if (x->finalGrade != y->finalGrade) return x->finalGrade < y->finalGrade;

    return 0;
}

void selectionSort(Student arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (comesBefore(&arr[j], &arr[min])) {
                min = j;
            }
        }
        if (min != i) swap(&arr[min], &arr[i]);
    }
}

int main(int argc, char **argv){

    if (argc != 3)
    {
        return 1;
    }

    FILE *in = fopen(argv[1], "r");
    if (in == NULL)
    {
        return 1;
    }

    FILE *out = fopen(argv[2], "w");
    if (out == NULL)
    {
        fclose(in);
        return 1;
    }

    int option;
    if (fscanf(in, "%d", &option) != 1 || option < 1 || option > 5) 
    {
        fprintf(out, "Error");
        fclose(in);
        fclose(out);
        return 0;
    }

    int count = 0;
    int c;

    while ((c = fgetc(in)) != EOF) {
        if (c == '\n') {
            count++;
        }
    }

    rewind(in);

    // code to put student list
    if (fscanf(in, "%d", &option) != 1 || option < 1 || option > 5) 
    {
        fprintf(out, "Error");
        fclose(in);
        fclose(out);

        return 0;
    }

    Student *students = malloc(count * sizeof(Student));
    if (count > 0 && students == NULL) 
    {
        fprintf(out, "Error");
        fclose(in); 
        fclose(out);

        return 0;
    }

    int n = 0;
    char last[50];

    while(fscanf(in, "%49s", last) == 1 && strcmp(last, "E") != 0)
    {
        if (n >= count) 
        {
            fprintf(out, "Error");
            free(students); 
            fclose(in); 
            fclose(out);

            return 0;
        }

        if (fscanf(in, "%49s %19s %d %d",
               students[n].fName,
               students[n].studentNum,
               &students[n].midGrade,
               &students[n].finalGrade) != 4) 
        {
            fprintf(out, "Error");
            free(students); 
            fclose(in); 
            fclose(out);

            return 0;
        }

        strcpy(students[n].lName, last);

        if (students[n].lName[0] == '\0' || students[n].fName[0] == '\0') 
        {
            fprintf(out, "Error");
            free(students); 
            fclose(in); 
            fclose(out);

            return 0;
        }

        char *id = students[n].studentNum;
        int ok = (strlen(id) == 8 && id[0] == 'A');

        for (int i = 1; ok && i < 8; i++) 
        {
            if (id[i] < '0' || id[i] > '9') ok = 0;
        }
        if (!ok) 
        {
            fprintf(out, "Error");
            free(students); 
            fclose(in); 
            fclose(out);

            return 0;
        }

        if (students[n].midGrade < 0 || 
            students[n].midGrade > 100 ||
            students[n].finalGrade < 0 || 
            students[n].finalGrade > 100) 
        {
            fprintf(out, "Error");
            free(students); 
            fclose(in); 
            fclose(out);

            return 0;
        }

        n++;
    }

    Student *filtered = NULL;
    int fcount = 0;

    if (n > 0) 
    {
        filtered = malloc(n * sizeof(Student));
        if (!filtered) 
        {
            fprintf(out, "Error");
            free(students); 
            fclose(in); 
            fclose(out);
            
            return 0;
        }
    }

    for (int i = 0; i < n; i++) 
    {
        double avg = (students[i].midGrade + students[i].finalGrade) / 2.0;

        int keep = 0;
        switch (option) {
            case 1: keep = (avg >= 90.0); break;
            case 2: keep = (avg >= 80.0 && avg < 90.0); break;
            case 3: keep = (avg >= 70.0 && avg < 80.0); break;
            case 4: keep = (avg >= 60.0 && avg < 70.0); break;
            case 5: keep = (avg < 60.0); break;
        }

        if (keep) 
        {
            filtered[fcount++] = students[i];
        }
    }

    free(students);
    students = filtered;
    n = fcount;

    selectionSort(students, n);

    for (int i = 0; i < n; i++) 
    {
        fprintf(out, "%s %s %s %d %d\n",
                students[i].lName,
                students[i].fName,
                students[i].studentNum,
                students[i].midGrade,
                students[i].finalGrade);
    }

    fclose(in);
    fclose(out);
    free(students);

    return 0;
}