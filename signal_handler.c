/** 
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by: Anish Kusukuntla
 * Lab 10: Signals
 * Brief summary of modifications:
 * In signal_handler.c, I needed to print out that the signal is being sent over.
 * Then I needed to replace the exit(1) with a kill command just so that I could send
 * the signal. I used SIGKILL in the kill command so that I could end the infinite while
 * loop. 
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal() {
    printf("Received a signal\n");
    //exit(1);
    if(kill(getpid(), SIGKILL) == -1){
        perror("Error sending the signal");
    } 
}

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);

    printf("Signal is being sent to the process.\n");
     
    
    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}