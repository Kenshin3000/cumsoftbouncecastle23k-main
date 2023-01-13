#include <stdio.h>
#include <bios.h>
#include <conio.h>
 
 
#define COM4       3
#define DATA_READY 0x100
#define TRUE       1
#define FALSE      0
 
 
#define SETTINGS ( 0xE0 | 0x03 | 0x00 | 0x00)
 
 
int main(void)
{
   int in, out, status;
   char c;
   FILE *fp;
   unsigned long shiftcount1=0,shiftcount2=0,shiftcount3=0,shiftcount4=0;
   unsigned long count = 0, DONE = 1;
 
 
   clrscr();
 
 
   fp = fopen("C:/TC/pic1.jpg","wb");// file opened for writing
 
 
   bioscom(0, SETTINGS, COM4);//initialize tyhe port
   cprintf("... BIOSCOM [ESC] to exit ...\n");
//receives all the 32 bits of file size sent from sender
   shiftcount1 = bioscom(2,0,COM4);
   shiftcount2 = bioscom(2,0,COM4);
   shiftcount3 = bioscom(2,0,COM4);
   shiftcount4 = bioscom(2,0,COM4);
 
 
//send an ack
   bioscom(1,'x',COM4);
 
 
   count = shiftcount1 | (shiftcount2<<8) | (shiftcount3<<16) | (shiftcount4<<24);
 
 
   printf("shift4 = %lu\tshift3 = %lu\tshift2 = %lu\tshift1 = %lu\n",shiftcount4,shiftcount3,shiftcount2,shiftcount1);
   printf("File Size = %lu\n",count);
 
 
//loop till the size of the file
   while (DONE < count)
   {
      status = bioscom(3, 0, COM4);// check the status
     // printf("%d",status);
      if (status & DATA_READY)//check for data ready at the port
      {
        out = bioscom(2, 0, COM4);//receive the data
        DONE++;
        fputc(out,fp);
        putch(out);
        bioscom(1,'x',COM4);//send an ack
      }
 
 
 
 
     if (kbhit())
     {
        if ((in = getch()) == '\x1B')
        break;
     }
   }
   fclose(fp);
   return 0;
}
