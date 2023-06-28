#include <stdio.h>
#include <string.h>
#include “passwords.h” // Contains the global adminpass
	
int main (int argc, char *argv [])
{
    int access = 0;
	    char password[8];
	
	    printf("Please enter a password: ");
	    scanf("%s", password);
	
	    if (strncmp (password, adminpass, 8) == 0)
        access = 1;
	    if (access > 0)
	        printf("Access Granted!\n");
	}
	
/*	main.c:3:10: error: #include expects "FILENAME" or <FILENAME>
 #include “passwords.h” // Contains the global adminpass
          ^
main.c: In function 'main':
main.c:13:29: error: 'adminpass' undeclared (first use in this function)
      if (strncmp (password, adminpass, 8) == 0)
                             ^~~~~~~~~
main.c:13:29: note: each undeclared identifier is reported only once for each function it appears in

[Compilation failed with exit code 1]*/
