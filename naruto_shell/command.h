
#ifndef COMMAND_H
#define COMMAND_H

#define Max_Data_Size (1024)
#define Max_Arg       (128)
#define MAX_HISTORY    (10)

void prompt();
void Data_IN(char *input , char **args);
void nagato();
void neji (char **args);
void konan (char **args);
void shizune (char **args);
void sasuke ( char **args);
void execute_command(char **args);
int orochimaru (char **args);
int shisui ( char **args);
int kakashi (char **args);
int gaara (char **args);
int sakura (char **args);


#endif

