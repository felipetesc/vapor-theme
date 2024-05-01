// test syntax colors
#include <cant_include_header.h> //test include error syntax color
#include <stdio.h> // test comment
#include "hello"
#include <regex.h>
#include <stdlib.h>
#include <stdio.h>

/*
    multiline
    bla
    bla
    bla
*/

/*
    /// multiline
    /// bla
    /// bla
    /// bla
*/

regex_t regex;
int reti;
char msgbuf[100];


// code from https://stackoverflow.com/questions/1085083/regular-expressions-in-c-examples
int test_regex()
{
    while(1){
        fgets( msgbuf, 100, stdin );
        reti = regcomp(&regex, "^(-)?([0-9]+)((,|.)([0-9]+))?\n$", REG_EXTENDED);
        if (reti) {
            fprintf(stderr, "Could not compile regex\n");
            exit(1);
        }

        /* Execute regular expression */
        printf("%s\n", msgbuf);
        reti = regexec(&regex, msgbuf, 0, NULL, 0);
        if (!reti) {
            puts("Match");
        }
        else if (reti == REG_NOMATCH) {
            puts("No match");
        }
        else {
            regerror(reti, &regex, msgbuf, sizeof(msgbuf));
            fprintf(stderr, "Regex match failed: %s\n", msgbuf);
            exit(1);
        }

        /* Free memory allocated to the pattern buffer by regcomp() */
        regfree(&regex);
    }

}


int main(int argc, char const *argv[]) {
    int i = 2;
    i = 33 * 33;
    static const char a_const[] = "my correct str const"; // test warning
    const char b_const = "oh no! something is missing! -> [] ";// test error
    printf("Hello, %s  \n", a_const);

    //call ext fn
    test_regex();



}
