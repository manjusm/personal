#include <stdio.h>
#include <string.h>
#include <signal.h>

void signalHandler(int sig)
{
    switch(sig)
    {
        case SIGUSR2:
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
    int i = 0;
    signalHandlerInstall();
    while(1)
    {
        i++;
    }
    return 0;
}
