// main.c
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void catch_interrupt(int sig) {
  printf("Interrupting...\n");
}

int main() {
  // define a signal handler register
  // note that although we didn't ask it to terminate (we only did a printf), since 
  // signal hanlder is registered, process can be terminated by SIGINT (^C)
  //signal(SIGINT, catch_interrupt);
  // comment above line out, your process doesn't have signal handler registered and wont' handl ^C anymore
  sleep(20);
  return 0;
}