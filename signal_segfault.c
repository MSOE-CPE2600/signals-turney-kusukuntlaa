/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Anish Kusukuntla
 * Lab 10: Signals
 * Brief summary of modifications:
 * I needed to register the signal for SIGSEGV on segmentation fault. 
 * I would use kill(getpid(), SIGKILL) to have the program exit for
 * ending the program. Otherwise, the program would print out segmentation violation
 * due to the dereferencing happening. 
 * Observations on the questions:
 * I observe that the signal goes into a infinite for loop while registering
 * signal(SIGSEGV, handle_signal) if I do not exit in handle_signal. This is happening
 * because the signal resets the signal handler to the default behavior after it is
 * used. The program would keep resuming when there is a segmentation fault.
 */


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
//Would have the handle_signal print out there is 
//segmentation violation and then ends the process using a kill.
void handle_signal() {
    printf("There is some segmentation violation\n");
    if(kill(getpid(), SIGKILL) == -1){
        perror("Error processing the SIGSEGV");
        
    } 
    
}
int main (int argc, char* argv[]) {
    // Declare a null pointer
    int* i = NULL;
    //Registers for the signal
    signal(SIGSEGV, handle_signal);
    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);
    
    printf("killed\n");
    // Return to exit the program
    return 0;
}