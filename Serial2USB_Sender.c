#include <stdio.h>
#include <bios.h>
#include <conio.h>
 
 
#define COM1       0
#define DATA_READY 0x100
#define TRUE       1
#define FALSE      0
 
 
#define SETTINGS ( 0xE0 | 0x03 | 0x00 | 0x00)
 
 
int main(void)
{
   int in, out, status, DONE = FALSE,i=0;
   char c;
   FILE *fp,*fp1;
   unsigned long count = 0,shiftcount = 0;
 
 
   clrscr();
 
 
   fp = fopen("C:/TC/pic.jpg","rb"); //opened for reading actual content
   fp1 = fopen("C:/TC/pic.jpg","rb"); //opened for reading the size of file
 
 
   fseek(fp1,0L,2);
   count = ftell(fp1) + 1; // file size
 
 
   bioscom(0, SETTINGS, COM1); // initializing the port
 
 
   printf("No. of Characters = %lu\n",count);
 
 
// since bioscom function can send or receive only 8bits at a time, am sending file size in
    4 rounds so that we can send at max of 4GB file.
 
 
   bioscom(1,count,COM1); // sneding 1st lower 8bits 
 
 
   bioscom(1,count>>8,COM1); // sending 2nd set of lower 8bits
 
 
   bioscom(1,count>>16,COM1); // sending 3rd set of lower 8bits
 
 
   bioscom(1,count>>24,COM1); // sending upper 8 bits
 
 
   cprintf("... BIOSCOM [ESC] to exit ...\n");
   while (!DONE)
   {
      status = bioscom(3, 0, COM1);// get the status of port
      //printf("%d",status);
      if (status & DATA_READY) //checks if data is ready
      {
        out = bioscom(2, 0, COM1); // receives the ack
        if(!feof(fp))
        {
            c = fgetc(fp); //read character by character from file
            bioscom(1,c,COM1);//send character to receiver
            putch(c);//display
        }
     }
 
 
//to interrupt
     if (kbhit())
     {
        if ((in = getch()) == '\x1B')
           DONE = TRUE;
     }
   }
   fclose(fp);
   return 0;
}
