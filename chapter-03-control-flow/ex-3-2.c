/*
 * Exercise 3-2
 * Write a function escape(t, s) that converts characters like newline and tab
 * into visible escape sequences like \n and \t as it copies the string t to s.
 * Use a switch.
 * Write a function for the other direction as well, converting escape
 * sequences into real characters.
 */

#include <stdio.h>
#include <string.h>


void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
    char input1[] = "\t\n\t h2o\n";
    char output1[20];
    escape(input1, output1);
    printf("%s\n", output1);

    char input2[] = "\\t\\n\\t h2o\\n";
    char output2[20];
    unescape(input2, output2);
    printf("%s\n", output2);

    // Input1 should equal output2
    printf("%d\n", strcmp(input1, output2));
}

/*
 * Replaces escapes with visible escapes.
 * Tab characters for example are replaced with \t
 */
void escape(char s[], char t[])
{   int j = 0;
    for (int i = 0; s[i]; ++i) {
        switch (s[i]) {
        case '\n':
            t[j++] = '\\';
            t[j++] = 'n';
            break;
        case '\t':
            t[j++] = '\\';
            t[j++] = 't';
            break;
        default:
            t[j++] = s[i];
        }
    }
    t[j] = '\0';
}

/*
 * Replaces escape sequences with actual character.
 * For example \t is replaced with an actual tab.
 * 
 * I'm not too fond of incrementing the loop variable i here
 * to skip a backslash in the input.
 */
void unescape(char s[], char t[])
{   
    int j = 0;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == '\\' && s[i+1]) {
            ++i; // Skip backslash
            switch (s[i]) {
            case 'n':
                t[j++] = '\n';
                break;
            case 't':
                t[j++] = '\t';
                break;
            default:
                t[j++] = '\\';
            }
        } else {
            t[j++] = s[i];
        }
    }
    t[j] = '\0';
}

