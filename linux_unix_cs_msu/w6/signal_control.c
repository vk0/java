// В следующем примере программа завершит работу, когда три раза будет нажата комбинация Ctrl-C. Предполагается, что функция signal поддерживает семантику BSD, то есть программа будет работать без изменений на операционных системах семейства BSD и на Linux

#include <stdio.h>
#include <signal.h>
int cnt = 0;
void sigint_handler(int signo)
{
    printf("Ctrl-C pressed %d times\n", cnt);
    if (++cnt == 3) {
        signal(SIGINT, SIG_DFL);
        raise(SIGINT);
    }
}
int main(void)
{
    signal(SIGINT, sigint_handler);
    while (1) {
        printf("Some string to print\n");
        sleep(1);
    }
    return 0;
}
