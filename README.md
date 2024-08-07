# NARUTO Shell

Welcome to NARUTO, a custom shell with built-in commands inspired by characters from the Naruto universe. 
This shell supports various commands for basic file operations, environment management, and process tracking.

![WhatsApp Image 2024-08-02 at 00 40 37_50c98fe4](https://github.com/user-attachments/assets/8f01a615-7142-450b-9cb7-e287c892c092)

## Features

- **Custom Commands**: Execute custom shell commands inspired by Naruto characters.
- **File Operations**: Copy and move files with ease.
- **Environment Management**: Print environment variables and change directories.
- **Process Tracking**: List the last 10 processes with their exit statuses.
- **Command Information**: Get information about built-in, external, and unsupported commands.

## Supported Commands

1. **nagato**: Print the current working directory.
   - Usage: `nagato`
   - Equivalent to the `pwd` command.
     
![WhatsApp Image 2024-08-02 at 00 45 54_3a73ea0d](https://github.com/user-attachments/assets/ae78a878-b71c-4456-9359-53b1ce2ac6b9)

2. **neji**: Print a user input string on stdout.
   - Usage: `neji [your input string]`
   - Equivalent to the `echo` command.

![WhatsApp Image 2024-08-02 at 00 45 54_461246c3](https://github.com/user-attachments/assets/bc0b2c39-ff11-4728-b520-6956f5b88259)


3. **konan**: Copy a file to another file.
   - Usage: `konan source target`
   - Equivalent to the `cp` command.


![WhatsApp Image 2024-08-02 at 00 45 54_87b38fe6](https://github.com/user-attachments/assets/29e9f339-62ed-49e9-b73d-6cf6cdbdcca9)


4. **shizune**: Move a file to another place.
   - Usage: `shizune source target`
   - Equivalent to the `mv` command.


![WhatsApp Image 2024-08-02 at 00 45 53_8e912a2f](https://github.com/user-attachments/assets/40d9edc8-6978-4bbd-85ec-e39df04bb861)


5. **sasuke**: Print all the supported commands with a brief info about each one.
   - Usage: `sasuke`
   - Equivalent to the `help` command.
     
![WhatsApp Image 2024-08-02 at 15 45 01_24074101](https://github.com/user-attachments/assets/e87f0790-4efe-49e5-a5fc-1e5b60cf02db)


6. **orochimaru**: Print "バイバイ" and terminate the shell.
   - Usage: `orochimaru`
   - Equivalent to the `exit` command.

![WhatsApp Image 2024-08-02 at 00 45 53_ccf52604](https://github.com/user-attachments/assets/23729cc8-7f84-499a-940d-174fd6daf91a)


7. **shisui**: Change the current working directory.
   - Usage: `shisui [directory]`
   - Equivalent to the `cd` command.

![WhatsApp Image 2024-08-02 at 00 45 53_02d0ac77](https://github.com/user-attachments/assets/d2a168e5-3824-4eec-9fd2-171e8693d13f)


8. **kakashi**: Return the type of the command (built-in, external, or unsupported).
   - Usage: `kakashi [command]`
   - Equivalent to the `type` command.
     
![WhatsApp Image 2024-08-02 at 00 45 52_0f9d1d14](https://github.com/user-attachments/assets/40375c30-9468-4680-ba2a-18722546c168)


9. **gaara**: Print all the environment variables.
   - Usage: `gaara`
   - Equivalent to the `printenv` command.
     
![WhatsApp Image 2024-08-02 at 00 45 52_12bc476b](https://github.com/user-attachments/assets/ec520a20-1213-43c9-bd7f-971b532da15e)


10. **sakura**: Lists the last 10 processes with their exit status.
    - Usage: `sakura`
    - Equivalent to the `phist` command.
      
![WhatsApp Image 2024-08-02 at 00 45 52_cea2c2fa](https://github.com/user-attachments/assets/d06d46bf-2439-4443-a91a-d942980826e4)


## Installation

1. Clone the repository and compile the code: ``bash git clone (https://github.com/karemhamam/NARUTOSHELL/tree/master)

## Compilation

To compile the shell program, use the following command:

``bash gcc -o myShell My_shell.c command.c

## Usage

To use the NARUTO shell, compile the source code and run the executable. You can then type any of the supported commands to perform the corresponding actions.

## Contributing

Contributions are welcome! 
If you have suggestions for new features or improvements, feel free to open an issue or submit a pull request.

## License

mahamedhamam15@gmail.com

