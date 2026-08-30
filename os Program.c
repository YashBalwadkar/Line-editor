#include <stdio.h>
#include <string.h>

#define MAX 100
#define SIZE 200

char lines[MAX][SIZE];
int count = 0;

/* 1. Insert Line */
void insertLine()
{
    int pos;
    char text[SIZE];

    printf("Enter line number to insert: ");
    scanf("%d", &pos);
    getchar();

    if (pos < 1 || pos > count + 1)
    {
        printf("Invalid line number!\n");
        return;
    }

    /* Shift lines down */
    for (int i = count; i >= pos; i--)
    {
        strcpy(lines[i], lines[i - 1]);
    }

    printf("Enter the line: ");
    fgets(text, SIZE, stdin);

    text[strcspn(text, "\n")] = '\0';

    strcpy(lines[pos - 1], text);

    count++;

    printf("Line inserted successfully!\n");
}


/* 2. Delete Line */
void deleteLine()
{
    int pos;

    if (count == 0)
    {
        printf("No lines available!\n");
        return;
    }

    printf("Enter line number to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count)
    {
        printf("Invalid line number!\n");
        return;
    }

    /* Shift lines up */
    for (int i = pos - 1; i < count - 1; i++)
    {
        strcpy(lines[i], lines[i + 1]);
    }

    count--;

    printf("Line deleted successfully!\n");
}


/* 3. Replace Line */
void replaceLine()
{
    int pos;
    char text[SIZE];

    if (count == 0)
    {
        printf("No lines available!\n");
        return;
    }

    printf("Enter line number to replace: ");
    scanf("%d", &pos);
    getchar();

    if (pos < 1 || pos > count)
    {
        printf("Invalid line number!\n");
        return;
    }

    printf("Enter new line: ");
    fgets(text, SIZE, stdin);

    text[strcspn(text, "\n")] = '\0';

    strcpy(lines[pos - 1], text);

    printf("Line replaced successfully!\n");
}


/* 4. Display Line */
void displayLine()
{
    int pos;

    if (count == 0)
    {
        printf("No lines available!\n");
        return;
    }

    printf("Enter line number to display: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count)
    {
        printf("Invalid line number!\n");
        return;
    }

    printf("\nLine %d: %s\n", pos, lines[pos - 1]);
}


/* 5. Search Word */
void searchWord()
{
    char word[50];
    int found = 0;

    if (count == 0)
    {
        printf("No lines available!\n");
        return;
    }

    getchar();

    printf("Enter word to search: ");
    fgets(word, 50, stdin);

    word[strcspn(word, "\n")] = '\0';

    for (int i = 0; i < count; i++)
    {
        if (strstr(lines[i], word) != NULL)
        {
            printf("Word found in line %d: %s\n",
                   i + 1, lines[i]);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("Word not found!\n");
    }
}


/* Main Function */
int main()
{
    int choice;

    while (1)
    {
        printf("\n========== LINE EDITOR ==========\n");
        printf("1. Insert Line\n");
        printf("2. Delete Line\n");
        printf("3. Replace Line\n");
        printf("4. Display Line\n");
        printf("5. Search Word\n");
        printf("6. Exit\n");
        printf("=================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertLine();
                break;

            case 2:
                deleteLine();
                break;

            case 3:
                replaceLine();
                break;

            case 4:
                displayLine();
                break;

            case 5:
                searchWord();
                break;

            case 6:
                printf("Exiting Line Editor...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}