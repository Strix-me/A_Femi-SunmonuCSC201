#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char *mem_alloc;
    mem_alloc = malloc(15* sizeof(char));
    if(mem_alloc ==NULL)
    {
        printf("Couldn't allocate requested memory\n");
    }
    else
    {
        strcpy(mem_alloc, "Pan-Atlantic");
    }

    printf("Dynamically Allocated memory : %s\n", mem_alloc);
    free(mem_alloc);
}
