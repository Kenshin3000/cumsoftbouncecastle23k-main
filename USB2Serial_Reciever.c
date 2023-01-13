#include <stdio.h>
#include <bios.h>
#include <conio.h>
#include<time.h>
 
 
#define COM1       0
#define DATA_READY 0x100
#define TRUE       1
#define FALSE      0
 
 
#define SETTINGS ( 0xE0 | 0x03 | 0x00 | 0x00)
 
 
int main(void)
{
   int in, out, status;
   char c;
   FILE *fp;
   int y = 0,esc;
   unsigned long count=0,shiftcount1 = 0,shiftcount2 = 0,shiftcount3 = 0,shiftcount4 = 0, DONE = 1;
 
 
   clock_t start,end;
 
 
   start = clock();
 
 
   clrscr();
 
 
   fp = fopen("C:/TC/pic1.jpg","wb");
 
 
   bioscom(0, SETTINGS, COM1);
   cprintf("... BIOSCOM [ESC] to exit ...\n");
 
 
   shiftcount1 = bioscom(2,0,COM1);
   shiftcount2 = bioscom(2,0,COM1);
   shiftcount3 = bioscom(2,0,COM1);
   shiftcount4 = bioscom(2,0,COM1);
 
 
   bioscom(1,'x',COM1);
 
 
   count = shiftcount1 | (shiftcount2<<8) | (shiftcount3<<16) | (shiftcount4<<24);
 
 
   printf("shift4 = %lu\tshift3 = %lu\tshift2 = %lu\t shift1 = %lu\n",shiftcount4,shiftcount3,shiftcount2,shiftcount1);
   printf("file size = %lu\n",count);
 
 
   while (DONE < count)
   {
      status = bioscom(3, 0, COM1);
      //printf("%d",status);
      if (status & DATA_READY)
      {
        out = bioscom(2, 0, COM1);
        DONE++;
        fputc(out,fp);
        putch(out);
        bioscom(1,'x',COM1);
      }
 
 
 
 
     if (kbhit())
     {
        if ((in = getch()) == '\x1B')
           break;
     }
   }
   fclose(fp);
 
 
   end = clock();
   printf("\nTotal time = %f\n",(end - start)/CLK_TCK);
 
 
   return 0;
}
