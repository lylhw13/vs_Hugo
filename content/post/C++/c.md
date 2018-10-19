---
title: "C"
date: 2018-08-25T11:07:55+08:00
draft: true
---

# Read 2 integers from user input in C

参考<https://stackoverflow.com/questions/21323253/read-2-integers-from-user-input-in-c>

```c
#include <stdio.h>
#include <ctype.h>

#define MAX_STR_LEN (50)

int main(void)
{
    char str[MAX_STR_LEN] = {0};
    int num1, num2;

    printf("Enter two numbers: ");
    fgets(str, MAX_STR_LEN, stdin);

    for(int i = 0; i < MAX_STR_LEN; i++)
    {
        if(!isdigit(str[i]) && (!isspace(str[i])) && (str[i] != '\0'))
        {
            if((i != 0) && (str[i - 1] != ' ') && ((str[i] != '+') || (str[i] != '-')))
            {
                printf("'%c' is bogus! I'm self destructing!", str[i]);
                return -1;
            }
        }

        if((str[i] == '\n') || (str[i] == '\0'))
            break;
    }

    sscanf(str, "%d%d", &num1, &num2);
    printf("You entered %d and %d. Good job.  Pat yourself on the back.", num1, num2);

    return 0;
}
```

The logic is as follows:

1, Read user input as a generic string.

2, Search string for offending characters or character sequences

3, If none, parse string accroingly.
