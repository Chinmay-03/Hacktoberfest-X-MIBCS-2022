//Vedarth Jayant Khandve 26 SE B 29 AUGUST 2022

#include<stdio.h>
#include<string.h>

void main()
{
char string[50];
int i, len;

printf("Enter your string:");
fgets(string,50,stdin);

printf("Your string is:");
puts(string);

len= strlen(string)-1;

for(i=0;i<=len;i++)

{
printf("%c",string[len-i]);
}

printf("\n");


}




