#include <stdio.h>
#include <cs50.h>
//func main
int main(void)
{   //get users name
    string name = get_string("What's your name? ");
    // print hello to user
    printf("hello, %s\n", name);
}
