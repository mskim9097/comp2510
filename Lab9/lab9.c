/*
 * Name: Minsu Kim
 * A-Number: A01424659
 * Lab: Lab 9
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_ITEMS 1024

enum
{
    TYPE_SHORT  = 1,
    TYPE_INT    = 2,
    TYPE_FLOAT  = 3,
    TYPE_CHAR   = 4,
    TYPE_STRING = 5
};

typedef struct Node
{
    void        *data;
    struct Node *next;
} Node;

static int g_type = 0;

void freeList(Node *head)
{
    while (head != NULL)
    {
        Node *tmp = head;
        head      = head->next;

        free(tmp->data);
        free(tmp);
    }
}

void printErrorAndCleanup(FILE *in, FILE *out, Node *head)
{
    fprintf(out, "Error");
    freeList(head);
    fclose(in);
    fclose(out);
}

int compareData(const void *a, const void *b)
{
    if (g_type == TYPE_SHORT)
    {
        short x = *(const short *)a;
        short y = *(const short *)b;
        return (x > y) - (x < y);
    }
    else if (g_type == TYPE_INT)
    {
        int x = *(const int *)a;
        int y = *(const int *)b;
        return (x > y) - (x < y);
    }
    else if (g_type == TYPE_FLOAT)
    {
        float x = *(const float *)a;
        float y = *(const float *)b;
        return (x > y) - (x < y);
    }
    else if (g_type == TYPE_CHAR)
    {
        char x = *(const char *)a;
        char y = *(const char *)b;
        return (x > y) - (x < y);
    }
    else  /* TYPE_STRING */
    {
        const char *x = (const char *)a;
        const char *y = (const char *)b;
        return strcmp(x, y);
    }
}

// Merge sort
Node *splitList(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *second = slow->next;
    slow->next   = NULL;
    return second;
}

Node *mergeLists(Node *a, Node *b)
{
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }

    if (compareData(a->data, b->data) <= 0)
    {
        a->next = mergeLists(a->next, b);
        return a;
    }
    else
    {
        b->next = mergeLists(a, b->next);
        return b;
    }
}

Node *mergeSortList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *second = splitList(head);

    head   = mergeSortList(head);
    second = mergeSortList(second);

    return mergeLists(head, second);
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        return 1;
    }

    FILE *in  = fopen(argv[1], "r");
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

    int type;
    if (fscanf(in, "%d", &type) != 1 ||
        type < TYPE_SHORT || type > TYPE_STRING)
    {
        fprintf(out, "Error");
        fclose(in);
        fclose(out);
        return 0;
    }

    g_type = type;

    int ch;
    while ((ch = fgetc(in)) != '\n' && ch != EOF) {}

    char line[1024];
    if (fgets(line, sizeof(line), in) == NULL)
    {
        fprintf(out, "Error");
        fclose(in);
        fclose(out);
        return 0;
    }
    line[strcspn(line, "\r\n")] = '\0';

    char endLine[32];
    if (fgets(endLine, sizeof(endLine), in) == NULL)
    {
        fprintf(out, "Error");
        fclose(in);
        fclose(out);
        return 0;
    }
    endLine[strcspn(endLine, "\r\n")] = '\0';

    if (strcmp(endLine, "E") != 0)
    {
        fprintf(out, "Error");
        fclose(in);
        fclose(out);
        return 0;
    }

    Node *head = NULL;
    Node *tail = NULL;
    int   count = 0;

    char *token = strtok(line, ",");
    while (token != NULL)
    {
        while (*token == ' ' || *token == '\t')
        {
            token++;
        }

        if (count >= MAX_ITEMS)
        {
            printErrorAndCleanup(in, out, head);
            return 0;
        }

        void *data = NULL;

        if (type == TYPE_SHORT)
        {
            char *end;
            long v = strtol(token, &end, 10);
            if (*end != '\0' || v < SHRT_MIN || v > SHRT_MAX)
            {
                printErrorAndCleanup(in, out, head);
                return 0;
            }
            short *p = malloc(sizeof(short));
            if (p == NULL)
            {
                freeList(head);
                fclose(in);
                fclose(out);
                return 1;
            }
            *p   = (short)v;
            data = p;
        }
        else if (type == TYPE_INT)
        {
            int *p = malloc(sizeof(int));
            if (p == NULL)
            {
                freeList(head);
                fclose(in);
                fclose(out);
                return 1;
            }
            *p   = atoi(token);
            data = p;
        }
        else if (type == TYPE_FLOAT)
        {
            float *p = malloc(sizeof(float));
            if (p == NULL)
            {
                freeList(head);
                fclose(in);
                fclose(out);
                return 1;
            }
            *p   = (float)atof(token);
            data = p;
        }
        else if (type == TYPE_CHAR)
        {
            if (strlen(token) != 1)
            {
                printErrorAndCleanup(in, out, head);
                return 0;
            }
            char *p = malloc(sizeof(char));
            if (p == NULL)
            {
                freeList(head);
                fclose(in);
                fclose(out);
                return 1;
            }
            *p   = token[0];
            data = p;
        }
        else /* TYPE_STRING */
        {
            char *p = malloc(strlen(token) + 1);
            if (p == NULL)
            {
                freeList(head);
                fclose(in);
                fclose(out);
                return 1;
            }
            strcpy(p, token);
            data = p;
        }

        Node *node = malloc(sizeof(Node));
        if (node == NULL)
        {
            free(data);
            freeList(head);
            fclose(in);
            fclose(out);
            return 1;
        }
        node->data = data;
        node->next = NULL;

        if (head == NULL)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            tail       = node;
        }

        count++;
        token = strtok(NULL, ",");
    }

    head = mergeSortList(head);

    Node *cur   = head;
    int   index = 0;

    while (cur != NULL)
    {
        if (index > 0)
        {
            fprintf(out, ",");
        }

        if (type == TYPE_SHORT)
        {
            fprintf(out, "%hd", *(short *)cur->data);
        }
        else if (type == TYPE_INT)
        {
            fprintf(out, "%d", *(int *)cur->data);
        }
        else if (type == TYPE_FLOAT)
        {
            fprintf(out, "%.1f", *(float *)cur->data);
        }
        else if (type == TYPE_CHAR)
        {
            fprintf(out, "%c", *(char *)cur->data);
        }
        else /* TYPE_STRING */
        {
            fprintf(out, "%s", (char *)cur->data);
        }

        cur = cur->next;
        index++;
    }

    fprintf(out, "\n");

    freeList(head);
    fclose(in);
    fclose(out);

    return 0;
}