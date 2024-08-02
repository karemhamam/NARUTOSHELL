/* *******************************************************
   * @File                 : command.c
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
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include "command.h"

/* **************** Include section End *************** */

/* **************** Macros section start *************** */


/* **************** Macros section End ****************** */



/* **************** Definition section start *************** */

void Data_IN(char *input , char **args)
{
    int i = 0 ; 
    for ( i = 0 ; i < Max_Arg ; i++)
    {
        args[i] = strsep(&input ," ");
        if (args[i] == NULL ) break;
    }
}

void prompt()
{

    printf("NARUTO :$ ");
}

void nagato (char **args)
{
    if (args == NULL || args[1] == NULL )
    {
        char cwd [1024];
        if (getcwd(cwd , sizeof(cwd)) != NULL)
        {
            printf("%s\n", cwd);
        }else
        {
            perror("Feh ERROR Hena");
        }
    }else
    {
        printf("error: usage: nagato\n");
    }

}

void neji (char **args)
{
    int i = 0 ; 
    for ( i = 1 ; args[i] != NULL ; i++)
    {
        printf("%s ", args[i]);
    }
    printf("\n");
}

void konan (char **args)
{
    char *source = args[1];
    char *target = args[2];

    if (!source || !target)
    {
        fprintf(stderr , "Usage: cp source target\n");
        return;
    }

    int source_fd = open (source , O_RDONLY);
    if (source_fd < 0 )
    {
        perror ("Feh ERROR Hena");
        return;
    }

    int target_fd ;
    target_fd = open(target , O_WRONLY | O_CREAT | O_EXCL , 0644);
    
    if (target_fd < 0 )
    {
        perror("Feh ERROR Hena");
        close(source_fd);
        return;
    }

    char buffer[1024];
    ssize_t bytes; 
    while ((bytes = read(source_fd , buffer ,sizeof(buffer))) > 0 )
    {
        if (write (target_fd ,buffer , bytes) != bytes)
        {
            perror("Feh ERROR Hena");
            close (source_fd);
            close (target_fd);
            return;
        }    
        if (bytes < 0 )
        {
            perror("Feh ERROR Hena");
        }
        close (source_fd);
        close (target_fd);
    }

}

void shizune (char **args)
{
    char *source = args[1];
    char *target = args[2];

    if (!source || !target)
    {
        fprintf(stderr , "Usage: mv source target \n");
        return;
    }
    if (rename(source,target) < 0 )
    {
        perror("Feh ERROR Hena");
    }
}

void sasuke ( char **args)
{
    if (args == NULL || args[1] == NULL)
    {
        printf(">>>NARUTO SHELL HAS SOME BUILT-IN COMMANDS LIKE : \n");
        printf("1 )  nagato     : print the currnet working directory\n");
        printf("2 )  neji       : print a user input string on stdout\n");
        printf("3 )  konan      : copy a file to another file\n");
        printf("4 )  shizune    : move a file to another place\n");
        printf("5 )  sasuke     : print all the supported command with a brief info about each one\n");
        printf("6 )  orochimaro : print \"バイバイ\" and terminate the shell\n");
        printf("7 )  shisui     : change the currnet working directory\n");
        printf("8 )  kakashi    : return the type of the command built-in or external or unsupported\n");
        printf("9 )  gaara      : print all the environment variables\n");
        printf("10)  sakura     : Lists the last 10 processes with their exit status\n");
        return;
    }else{};

    if (strcmp(args[1] , "nagato") == 0 )
    {
        printf
        ("███▄▄▄▄      ▄████████    ▄██████▄     ▄████████     ███      ▄██████▄   \n"
         "███▀▀▀██▄   ███    ███   ███    ███   ███    ███ ▀█████████▄ ███    ███  \n"
         "███   ███   ███    ███   ███    █▀    ███    ███    ▀███▀▀██ ███    ███  \n"
         "███   ███   ███    ███  ▄███          ███    ███     ███   ▀ ███    ███  \n"
         "███   ███ ▀███████████ ▀▀███ ████▄  ▀███████████     ███     ███    ███  \n"
         "███   ███   ███    ███   ███    ███   ███    ███     ███     ███    ███  \n"
         "███   ███   ███    ███   ███    ███   ███    ███     ███     ███    ███  \n"
         " ▀█   █▀    ███    █▀    ████████▀    ███    █▀     ▄████▀    ▀██████▀   \n"
        ); 
        printf("nagato: Print the current working directory\n");
        printf("nagato  == pwd \n");
        printf("Usage: nagato\n");

    }else if (strcmp(args[1] , "neji") == 0 )
    {
        printf
        ("███▄▄▄▄      ▄████████      ▄█  ▄█   \n"
         "███▀▀▀██▄   ███    ███     ███ ███   \n"
         "███   ███   ███    █▀      ███ ███▌  \n"
         "███   ███  ▄███▄▄▄         ███ ███▌  \n"
         "███   ███ ▀▀███▀▀▀         ███ ███▌  \n"
         "███   ███   ███    █▄      ███ ███   \n"
         "███   ███   ███    ███     ███ ███   \n"
         " ▀█   █▀    ██████████ █▄ ▄███ █▀    \n"
        ); 
        printf("neji: print a user input string on stdout\n");
        printf("neji  = echo \n");
        printf("Usage: echo [your input string]\n");

    }else if (strcmp(args[1] , "konan") == 0 )
    {
        printf
        ("   ▄█   ▄█▄  ▄██████▄  ███▄▄▄▄      ▄████████ ███▄▄▄▄    \n"
         "  ███ ▄███▀ ███    ███ ███▀▀▀██▄   ███    ███ ███▀▀▀██▄  \n"
         "  ███▐██▀   ███    ███ ███   ███   ███    ███ ███   ███  \n"
         " ▄█████▀    ███    ███ ███   ███   ███    ███ ███   ███  \n"
         "▀▀█████▄    ███    ███ ███   ███ ▀███████████ ███   ███  \n"
         "  ███▐██▄   ███    ███ ███   ███   ███    ███ ███   ███  \n"
         "  ███ ▀███▄ ███    ███ ███   ███   ███    ███ ███   ███  \n"
         "  ███   ▀█▀  ▀██████▀   ▀█   █▀    ███    █▀   ▀█   █▀   \n"
         "  ▀                                                      \n"
        ); 
        printf("konan: copy a file to another file\n");
        printf("konan  = cp \n");
        printf("Usage: konan source target\n");

    }else if (strcmp(args[1] , "shizune") == 0 )
    {
        printf
        ("   ▄████████    ▄█    █▄     ▄█   ▄███████▄  ███    █▄  ███▄▄▄▄      ▄████████  \n"
         "  ███    ███   ███    ███   ███  ██▀     ▄██ ███    ███ ███▀▀▀██▄   ███    ███  \n"
         "  ███    █▀    ███    ███   ███▌       ▄███▀ ███    ███ ███   ███   ███    █▀   \n"
         "  ███         ▄███▄▄▄▄███▄▄ ███▌  ▀█▀▄███▀▄▄ ███    ███ ███   ███  ▄███▄▄▄      \n"
         "▀███████████ ▀▀███▀▀▀▀███▀  ███▌   ▄███▀   ▀ ███    ███ ███   ███ ▀▀███▀▀▀      \n"
         "         ███   ███    ███   ███  ▄███▀       ███    ███ ███   ███   ███    █▄   \n"
         "   ▄█    ███   ███    ███   ███  ███▄     ▄█ ███    ███ ███   ███   ███    ███  \n"
         " ▄████████▀    ███    █▀    █▀    ▀████████▀ ████████▀   ▀█   █▀    ██████████  \n"
        ); 
        printf("shizune: move a file to another place\n");
        printf("konan  = mv \n");
        printf("Usage: shizune source target\n");

    }else if (strcmp(args[1] , "orochimaru") == 0 )
    {
        printf
        (                                                                   
            " ▄██████▄     ▄████████  ▄██████▄   ▄████████    ▄█    █▄     ▄█    ▄▄▄▄███▄▄▄▄      ▄████████    ▄████████  ▄██████▄  \n"
            "███    ███   ███    ███ ███    ███ ███    ███   ███    ███   ███  ▄██▀▀▀███▀▀▀██▄   ███    ███   ███    ███ ███    ███ \n"
            "███    ███   ███    ███ ███    ███ ███    █▀    ███    ███   ███▌ ███   ███   ███   ███    ███   ███    ███ ███    ███ \n"
            "███    ███  ▄███▄▄▄▄██▀ ███    ███ ███         ▄███▄▄▄▄███▄▄ ███▌ ███   ███   ███   ███    ███  ▄███▄▄▄▄██▀ ███    ███ \n"
            "███    ███ ▀▀███▀▀▀▀▀   ███    ███ ███        ▀▀███▀▀▀▀███▀  ███▌ ███   ███   ███ ▀███████████ ▀▀███▀▀▀▀▀   ███    ███ \n"
            "███    ███ ▀███████████ ███    ███ ███    █▄    ███    ███   ███  ███   ███   ███   ███    ███ ▀███████████ ███    ███ \n"
            "███    ███   ███    ███ ███    ███ ███    ███   ███    ███   ███  ███   ███   ███   ███    ███   ███    ███ ███    ███ \n"
            " ▀██████▀    ███    ███  ▀██████▀  ████████▀    ███    █▀    █▀    ▀█   ███   █▀    ███    █▀    ███    ███  ▀██████▀  \n"
        ); 
        printf("orochimaru: print \"バイバイ\" and terminate the shell\n");
        printf("orochimaru  = exit \n");
        printf("Usage: orochimaru \n");

    }else if (strcmp(args[1] , "shisui") == 0 )
    {
        printf
        (                                                            
            "   ▄████████    ▄█    █▄     ▄█     ▄████████ ███    █▄   ▄█  \n"
            "  ███    ███   ███    ███   ███    ███    ███ ███    ███ ███  \n"
            "  ███    █▀    ███    ███   ███▌   ███    █▀  ███    ███ ███▌ \n"
            "  ███         ▄███▄▄▄▄███▄▄ ███▌   ███        ███    ███ ███▌ \n"
            "▀███████████ ▀▀███▀▀▀▀███▀  ███▌ ▀███████████ ███    ███ ███▌ \n"
            "         ███   ███    ███   ███           ███ ███    ███ ███  \n"
            "   ▄█    ███   ███    ███   ███     ▄█    ███ ███    ███ ███  \n"
            " ▄████████▀    ███    █▀    █▀    ▄████████▀  ████████▀  █▀   \n"
        ); 
        printf("shisui: change the currnet working directory\n");
        printf("shisui  = cd \n");
        printf("Usage: shisui [directory] \n");

    }else if (strcmp(args[1] , "kakashi") == 0 )
    {
        printf
        (                                                                        
            "   ▄█   ▄█▄    ▄████████    ▄█   ▄█▄    ▄████████    ▄████████    ▄█    █▄     ▄█  \n"
            "  ███ ▄███▀   ███    ███   ███ ▄███▀   ███    ███   ███    ███   ███    ███   ███  \n"
            "  ███▐██▀     ███    ███   ███▐██▀     ███    ███   ███    █▀    ███    ███   ███▌ \n"
            " ▄█████▀      ███    ███  ▄█████▀      ███    ███   ███         ▄███▄▄▄▄███▄▄ ███▌ \n"
            "▀▀█████▄    ▀███████████ ▀▀█████▄    ▀███████████ ▀███████████ ▀▀███▀▀▀▀███▀  ███▌ \n"
            "  ███▐██▄     ███    ███   ███▐██▄     ███    ███          ███   ███    ███   ███  \n"
            "  ███ ▀███▄   ███    ███   ███ ▀███▄   ███    ███    ▄█    ███   ███    ███   ███  \n"
            "  ███   ▀█▀   ███    █▀    ███   ▀█▀   ███    █▀   ▄████████▀    ███    █▀    █▀   \n"
            "  ▀                        ▀                                                       \n"
            
        ); 
        printf("kakashi:  return the type of the command built-in or external or unsupported\n");
        printf("kakashi  = type \n");
        printf("Usage: kakashi [command] \n");

    }else if (strcmp(args[1] , "gaara") == 0 )
    {
        printf
        (                                                  
            "   ▄██████▄     ▄████████    ▄████████    ▄████████    ▄████████ \n"
            "  ███    ███   ███    ███   ███    ███   ███    ███   ███    ███ \n"
            "  ███    █▀    ███    ███   ███    ███   ███    ███   ███    ███ \n"
            " ▄███          ███    ███   ███    ███  ▄███▄▄▄▄██▀   ███    ███ \n"
            "▀▀███ ████▄  ▀███████████ ▀███████████ ▀▀███▀▀▀▀▀   ▀███████████ \n"
            "  ███    ███   ███    ███   ███    ███ ▀███████████   ███    ███ \n"
            "  ███    ███   ███    ███   ███    ███   ███    ███   ███    ███ \n"
            "  ████████▀    ███    █▀    ███    █▀    ███    ███   ███    █▀  \n"
            "                                         ███    ███              \n"
            
        ); 
        printf("gaara:  print all the environment variables\n");
        printf("gaara  = envir \n");
        printf("Usage: gaara [variable] \n");

    }else if (strcmp(args[1] , "sakura") == 0 )
    {
        printf
        (                                                 
            "   ▄████████    ▄████████    ▄█   ▄█▄ ███    █▄     ▄████████    ▄████████ \n"
            "  ███    ███   ███    ███   ███ ▄███▀ ███    ███   ███    ███   ███    ███ \n"
            "  ███    █▀    ███    ███   ███▐██▀   ███    ███   ███    ███   ███    ███ \n"
            "▀███████████ ▀███████████ ▀▀█████▄    ███    ███ ▀▀███▀▀▀▀▀   ▀███████████ \n"
            "         ███   ███    ███   ███▐██▄   ███    ███ ▀███████████   ███    ███ \n"
            "   ▄█    ███   ███    ███   ███ ▀███▄ ███    ███   ███    ███   ███    ███ \n"
            " ▄████████▀    ███    █▀    ███   ▀█▀ ████████▀    ███    ███   ███    █▀  \n"
            "                            ▀                      ███    ███              \n"
            
        ); 
        printf("sakura:  Lists the last 10 processes with their exit status\n");
        printf("sakura  = phist \n");
        printf("Usage: sakura  \n");

    }else if (strcmp(args[1] , "sasuke") == 0 )
    {
        printf
        (   
            "   ▄████████    ▄████████    ▄████████ ███    █▄     ▄█   ▄█▄    ▄████████ \n"
            "  ███    ███   ███    ███   ███    ███ ███    ███   ███ ▄███▀   ███    ███ \n"
            "  ███    █▀    ███    ███   ███    █▀  ███    ███   ███▐██▀     ███    █▀  \n"
            "  ███          ███    ███   ███        ███    ███  ▄█████▀     ▄███▄▄▄     \n"
            "▀███████████ ▀███████████ ▀███████████ ███    ███ ▀▀█████▄    ▀▀███▀▀▀     \n"
            "          ███   ███    ███          ███ ███    ███   ███▐██▄     ███    █▄  \n"
            "   ▄█    ███   ███    ███    ▄█    ███ ███    ███   ███ ▀███▄   ███    ███ \n"
            " ▄████████▀    ███    █▀   ▄████████▀  ████████▀    ███   ▀█▀   ██████████ \n"
            "                                                    ▀                      \n"
            
        ); 
        printf("sasuke:  Lists the last 10 processes with their exit status\n");
        printf("sasuke  = phist \n");
        printf("Usage: sasuke || sasuke [command]  \n");

    }else
    {
        printf("%s is not a supported command, plz enter \"sasuke\" to know the supported commands\n" , args[1]);
    }
}




int orochimaru (char **args)
{   
    if (args == NULL || args[1] == NULL)
    {
        printf("バイバイ\n");
        exit(0);
        return 0 ;
    }else
    {
        printf("error: usage: orochimaru\n");
    }

}

int shisui ( char **args)
{
    if ( args[1] == NULL)
    {
        fprintf(stderr , "cd: expected argument to \"cd\"\n");
    }else if (chdir(args[1]) != 0 )
    {
        perror("cd error");
    }else{};
    return 1 ;
}

int is_external(const char *command) {
    char *path_env = getenv("PATH");
    if (path_env == NULL) {
        return 0;
    }
   
    char *path_env_copy = strdup(path_env);
    if (path_env_copy == NULL) {
        perror("strdup");
        return 0;
    }

    
    char *dir = strtok(path_env_copy, ":");
    while (dir != NULL) {
        
        char command_path[1024];
        snprintf(command_path, sizeof(command_path), "%s/%s", dir, command);
        
        
        struct stat st;
        if (stat(command_path, &st) == 0 && (st.st_mode & S_IXUSR)) {
            free(path_env_copy);
            return 1; 
        }

        dir = strtok(NULL, ":");
    }

    free(path_env_copy);
    return 0;
}

int kakashi (char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr , "type: expected argument to 'type' \n");
        return 1 ;

    }
    const char *built_in_commands[]={"konan", "shizune" , "nagato" , "neji" , "sasuke" , "orochimaru" , "shisui" , "kakashi" , "gaara" , "sakura"};
    size_t num_built_in = sizeof(built_in_commands)/sizeof(built_in_commands[0]);
    ssize_t i = 0 ;
    for ( i = 0 ; i < num_built_in ;i++)
    {
        if (strcmp(args[1] , built_in_commands[i]) == 0 )
        {
            printf("'%s' is a shell built-in command\n" , args[1]);
            return 1; 
        }
    }
    if (is_external(args[1]))
    {
        printf("'%s' is an external command\n" , args[1]);
    }else
    {
        printf("'%s' is an unsupported command\n", args[1]);
    }
    return 1 ;
}

int gaara (char **args)
{
    if (args[1] == NULL)
    {
        extern char **environ;
        for (char **env = environ; *env != NULL; env++) 
        {
            printf("%s\n", *env);
        }
    } else
    {
        char *value = getenv(args[1]);
        if (value != NULL) 
        {
            printf("%s\n", value);
        } else 
        {
            printf("%s: No such environment variable\n", args[1]);
        }
    }
    return 1 ; 
}
typedef struct 
{
    int status;
    pid_t pid;
} process_info;

process_info process_history[MAX_HISTORY];

int history_index = 0;

int sakura (char **args)
{
    for (int i = 0; i < MAX_HISTORY; i++) 
    {
        if (process_history[i].pid != 0) 
        {
            printf("PID: %d, Exit Status: %d\n", process_history[i].pid, process_history[i].status);
        }
    }
    return 1 ;
}

void add_to_history(pid_t pid, int status)
{
    process_history[history_index].pid = pid;
    process_history[history_index].status = status;
    history_index = (history_index + 1) % MAX_HISTORY;
}

void execute_command(char **args)
{
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        
        if (execvp(args[0], args) == -1)
        {
            perror("exec error");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        
        perror("fork error");
    } else {
        
        do 
        {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        add_to_history(pid, status);
    }
    
}



/* ************** Definition section End ************************ */



/* *******************************************************
   @User                 @Date               @time 
   *******************************************************
   mohamed hamam         31july2024          1:22pm
   mohamed hamam         2 aug 2024          4:50pm

*/

