#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


COORD c = {0, 0};
void setxy(int x, int y)
{
    c.X=x; c.Y=y; //Set X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main()
{

   int x=20, y=10, ch1, ch2;
   printf("Press UP, DOWNM RIGHT, LEFT Arrow Key..\n");
   printf("Press X to exit game... \n");
   ch1 = getch();
   ch2 = 0;

   if(ch1 == 0xE0)
    /*when accepting arrow key,function must be called twice; first call
    returns 0/0xE0; second call returns actual key code
    */
   {
        setxy(x,y);
        while(ch2 != 'X')
        {
            ch2 = getch();
            switch(ch2)
            {
                case 72:
                    setxy(x,y--);
                    printf("%c",2);
                    break;
                case 80:
                    setxy(x,y++);
                    printf("%c",2);
                    break;
                case 75:
                    setxy(x--,y);
                    printf("%c",2);
                    break;
                case 77:
                    setxy(x++,y);
                    printf("%c",2);
                    break;
                default:
                    break;
            };
        }
   }
   else
    printf("key pressed: %d %c\n", ch1, ch2);
   system("pause");
   return 0;
}







