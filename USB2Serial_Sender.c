#include <stdio.h>
#include <bios.h>
#include <conio.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
 
 
#define RTS 0x02
#define COM1       0
#define    COM4       3
#define CURRCOM      COM4
#define DATA_READY 0x100
#define TRUE       1
#define FALSE      0
 
 
#define SETTINGS ( 0xE0 | 0x03 | 0x00 | 0x00)
 
 
int main(void)
{
   int in, out, status, DONE = FALSE,nextfile = 1;
   char c;
   FILE *fp,*fp1;
   unsigned long count = 0,shiftcount = 0;
   clock_t start,end;
 
 
   start = clock();
 
 
   clrscr();
 
 
   fp = fopen("C:/TC/pic.jpg","rb");
   fp1 = fopen("C:/TC/pic.jpg","rb");
 
 
   fseek(fp1,0L,2);
   count = ftell(fp1) + 1;
 
 
   bioscom(0, SETTINGS, CURRCOM);
 
 
  /*  while(!feof(fp1))
    {
    c = fgetc(fp1);
    count++;
    } */
 
 
 
 
   printf("No. of Cheracters = %lu\n",count);
 
 
 
 
    bioscom(1,count,CURRCOM);
 
 
    bioscom(1,count>>8,CURRCOM);
 
 
    bioscom(1,count>>16,CURRCOM);
 
 
    bioscom(1,count>>24,CURRCOM);
 
 
   cprintf("\n... BIOSCOM [ESC] to exit ...\n");
   while (!DONE)
   {
      status = bioscom(3, 0, CURRCOM);
      if (status & DATA_READY)
      {
        out = bioscom(2,0,CURRCOM);
 
 
        if(!feof(fp))
        {
            c = fgetc(fp);
            bioscom(1,c,CURRCOM);
            putch(c);
        }
      }
 
 
     if (kbhit())
     {
        if ((in = getch()) == '\x1B')
           DONE = TRUE;
     }
   }
   fclose(fp);
 
 
   end = clock();
   printf("\nTotal time = %d\n",(end - start)/CLK_TCK);
 
 
   return 0;
}
