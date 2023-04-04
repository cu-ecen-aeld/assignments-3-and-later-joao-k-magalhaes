//Alternative program to the script "writer.sh" created in 
//assignment 1

#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MY_LOG LOG_USER

int main(int argc, char *argv[]){

//Report errors in case of the number of arguments passed
//not be appropriate
  
  openlog(NULL, 0, MY_LOG);

  if(argc < 2){
    syslog(LOG_ERR, "Error: The number of parameters were not specified correctly: %d", argc);
    return 1;
  }

//Receives the arguments, the name of the file to be written 
//and the string, wich will be stored in the file

  const char *WRITEFILE = argv[1];
  const char *WRITESTR = argv[2];

if(argv[2] == NULL){
  syslog(LOG_ERR, "Error: Write string is not specified");
  return 1;
}

//Opens the file and tests for erros during the opening

  int fd = open(WRITEFILE, O_WRONLY | O_CREAT | O_TRUNC, 777);

  if(fd == -1){
    syslog(LOG_ERR, "Error: The file %s could not be opened", WRITEFILE);
  }

//Writes to the target file 

  if(write(fd,WRITESTR, strlen(WRITESTR)) == -1){
    syslog(LOG_ERR, "Error: Could not write %s to the file %s", WRITESTR, WRITEFILE);
    return 1;
  }

//Prints the debug messages in the log and close the file
   
  syslog(LOG_DEBUG, "Writing \"%s\" to %s", WRITESTR, WRITEFILE);
  close(fd);
}