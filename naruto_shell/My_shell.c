/* *******************************************************
   * @File                 : My_shell.c
   * @Author               : mohamed bahget hamam
   * @Brief                : shell v2.0
   * @gmail                : mahamedhamam15@gmail.com
   *******************************************************
*/


/* **************** Include section start *************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
#include "command.h"
/* **************** Include section End *************** */

/* **************** macros section start *************** */


/* **************** macros section End *************** */



int main()
{
    char input[Max_Data_Size];
    char *args[Max_Arg];
    const char *naruto = 
    "\n"
    "███▄▄▄▄      ▄████████    ▄████████ ███    █▄      ███      ▄██████▄   \n"
    "███▀▀▀██▄   ███    ███   ███    ███ ███    ███ ▀█████████▄ ███    ███  \n"
    "███   ███   ███    ███   ███    ███ ███    ███    ▀███▀▀██ ███    ███  \n"
    "███   ███   ███    ███  ▄███▄▄▄▄██▀ ███    ███     ███   ▀ ███    ███  \n"
    "███   ███ ▀███████████ ▀▀███▀▀▀▀▀   ███    ███     ███     ███    ███  \n"
    "███   ███   ███    ███ ▀███████████ ███    ███     ███     ███    ███  \n"
    "███   ███   ███    ███   ███    ███ ███    ███     ███     ███    ███  \n"
    " ▀█   █▀    ███    █▀    ███    ███ ████████▀     ▄████▀    ▀██████▀   \n";
    printf("%s", naruto);
    while (1)
    {
        prompt();
        if (fgets(input , Max_Data_Size , stdin) == NULL)
        {
            perror("Feh ERROR Hena");
            continue;
        }   
        
        input[strcspn(input,"\n")] = 0 ;

        if (strcmp (input , "") == 0 ) continue;
        Data_IN(input, args);
        if (strcmp (args[0],"nagato") == 0)
        {
            nagato();
        }else if (strcmp (args[0] , "neji") == 0)
        {
            neji(args);
        }else if (strcmp (args[0], "konan") == 0 )
        {
            konan(args);
        }else if (strcmp (args[0], "shizune") == 0 )
        {
            shizune(args);
        }else if (strcmp (args[0] , "orochimaru") == 0)
        {
            orochimaru(args);
        }else if ( strcmp (args[0], "sasuke") == 0 )
        {
            sasuke(args);
        }else if ( strcmp (args[0], "shisui") == 0 )
        {
            shisui(args);

        }else if ( strcmp (args[0], "kakashi") == 0 )
        {
            kakashi(args);

        }else if ( strcmp (args[0], "gaara") == 0 )
        {
            gaara(args);

        }else if ( strcmp (args[0] , "sakura") == 0)
        {
            sakura(args);
        }
        else
        {
            execute_command(args);
        }
    }


  return 0 ;
}


/* **************** Definition section start *************** */



/* ************** Definition section End *************** */



/* *******************************************************
   @User                 @Date             @time
   *******************************************************
   mohamed hamam         31july2024         1:22 pm

*/

