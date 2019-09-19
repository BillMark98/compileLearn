# Notes general
the code is based on the book **Compilers: Principles, Techniques and Tools
## Programming 
1. global variable should be defined in `.c` file  
and in the `.h` file use the syntax `extern ...`   
2. functions should be defined in the `global.h` file  
so that different files can share the API  
3. some libraries should be included:  
`string.h` for `strcpy`  
`stdlib.h` for `exit`  
