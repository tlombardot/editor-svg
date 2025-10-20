#include <stdlib.h>
#include "utils/windows_user.h"
#include "config/color.h"
#include "components/list.h"




int main(void)
{
    List *list = userInterface();
    system("clear");
    printf(YELLOW "system> " RESET WHITE "shutting down...\n");
    sleep_ms(500);
    printf(YELLOW "goodbye user.\n" RESET);
    sleep_ms(500);
    freeList(list);
    system("clear");
    printf(YELLOW"███╗░░░███╗███████╗███╗░░░███╗░█████╗░██████╗░██╗░░░██╗  ███████╗██████╗░███████╗███████╗██████╗░\n");
    printf("████╗░████║██╔════╝████╗░████║██╔══██╗██╔══██╗╚██╗░██╔╝  ██╔════╝██╔══██╗██╔════╝██╔════╝██╔══██╗\n");
    printf("██╔████╔██║█████╗░░██╔████╔██║██║░░██║██████╔╝░╚████╔╝░  █████╗░░██████╔╝█████╗░░█████╗░░██║░░██║\n");
    printf("██║╚██╔╝██║██╔══╝░░██║╚██╔╝██║██║░░██║██╔══██╗░░╚██╔╝░░  ██╔══╝░░██╔══██╗██╔══╝░░██╔══╝░░██║░░██║\n");
    printf("██║░╚═╝░██║███████╗██║░╚═╝░██║╚█████╔╝██║░░██║░░░██║░░░  ██║░░░░░██║░░██║███████╗███████╗██████╔╝\n");                    printf("╚═╝░░░░░╚═╝╚══════╝╚═╝░░░░░╚═╝░╚════╝░╚═╝░░╚═╝░░░╚═╝░░░  ╚═╝░░░░░╚═╝░░╚═╝╚══════╝╚══════╝╚═════╝░\n");
    return EXIT_SUCCESS;

}
