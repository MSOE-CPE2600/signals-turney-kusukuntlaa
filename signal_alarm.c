/**
 * File: signal_alarm.c
 * Modified by: Anish Kusukuntla
 * Lab 10: Signals
 * Brief summary of program:
 * I needed to implement the main so that it used an alarm that 
 * went off for 5 seconds. I would print out before that the 
 * alarm is going to start and print out after that the alarm worked.
 */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
void handle_signal() {
    printf("The alarm has gone off for 5 seconds\n");
}

int main(int argc, char* argv[]) {
    //Registers for the signal on alarm
    signal(SIGALRM, handle_signal); 
    printf("Starts the alarm\n");
    alarm(5); //alarms for 5 seconds
    //Sends the alarm to print out if the alarm worked
    if(kill(getpid(), SIGALRM) == -1) {
        perror("Did not execute");
        return -1;
    } else {
        printf("The alarm worked\n");
    }

}
