#include <stdio.h>
#include <string.h>
#include <signal.h>


/*
    Variable i is declared globally and used in main() and signal handler. 
    Value of i is set through signal SIGUSR2.
    We expect the value to take effect but it doesn't as the compiler optimze it.
    Compiler will optimize the value of i in main() if variable is not declared as volatile.
    We need compile code with O2/3 to see effect. 
*/

volatile int i = 0;

void signalHandler(int sig)
{
    switch(sig)
    {
        case SIGUSR2:
            i = 1;
            printf("In signal handler for SIGUSR2\n");
            break;

        case SIGINT:
            printf("In signal handler for SIGINT\n");
            break;
        default:
            printf("Signal is not handled\n");
    }

    return;
}

/* Install signal handler */
int signalHandlerInstall(void)
{
    struct sigaction sa;

    memset(&sa, 0, sizeof(sa));

    /* Install signal handler to make a clean shutdown */
    sa.sa_handler = signalHandler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    if (sigaction(SIGINT, &sa, NULL) < 0) {
        printf("Failed to install signal handler for SIGINT\n");
    }
    if (sigaction(SIGUSR2, &sa, NULL) < 0) {
        printf("Failed to install signal handler for SIGUSR2\n");
    }

    return 0;
}

int main()
{
    signalHandlerInstall();
    while(0 == i)
    {
    }
    return 0;
}
