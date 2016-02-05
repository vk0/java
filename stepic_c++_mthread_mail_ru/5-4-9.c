// Задача на безымянные каналы.

// Пусть у нас есть длинная команда вида:

// who | sort | uniq -c | sort -nk1

// Надо ее прочитать из STDIN, выполнить и STDOUT записать в файл /home/box/result.out

// Вы должны создать Makefile в домашнем каталоге.

// Тестовая система выполнит make. Она ожидает, что появится файл исполняемый файл - /home/box/shell. После чего она исполнит его несколько раз, подавая на STDIN разные строчки и проверяя result.out.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

char * fileout = "/home/box/result.out";
//who | sort | uniq -c | sort -nk1


int run_command (char * cmd)
{
    size_t len = strlen (cmd);
    char file_name [len];
    memset(file_name, 0, len * sizeof(char));

    int cur_index = 0;
    int opt_start = 0;
    for (size_t i=0; i<len; i++)
    {
        if (cmd[i] != ' ')
        {
            file_name[cur_index] = cmd[i];
            cur_index ++;
        }
        else
        {
            if (cur_index != 0)
            {
                opt_start = i;
                break;
            }
        }
    }

    char * args [len];
    args[0] = file_name;
    int next_arg = 1;

    if (opt_start !=0 )
    {
        int we_add = 0;
        for (int i=opt_start; i<len; i++)
        {
            if (cmd[i] == ' ')
            {
                if (we_add)
                {
                    cmd[i] = '\0';
                    we_add = 0;
                }
            }
            else
            {
                if (!we_add)
                {
                    args[next_arg] = &(cmd[i]);
                    next_arg++;
                    we_add = 1;
                }
            }
        }
    }

    args[next_arg] = NULL;

    return execvp (file_name, args);
}

int
spawn_proc (int in, int out, char *cmd)
{
  pid_t pid;

  if ((pid = fork ()) == 0)
    {
      if (in != 0)
        {
          dup2 (in, 0);
          close (in);
        }

      if (out != 1)
        {
          dup2 (out, 1);
          close (out);
        }

      return run_command(cmd);
    }

  return pid;
}

int
fork_pipes (int n, char * cmd[])
{
  int i;
  pid_t pid;
  int in, fd [2];

  /* The first process should get its input from the original file descriptor 0.  */
  in = 0;

  /* Note the loop bound, we spawn here all, but the last stage of the pipeline.  */
  for (i = 0; i < n - 1; ++i)
    {
      pipe (fd);

      /* f [1] is the write end of the pipe, we carry `in` from the prev iteration.  */
      spawn_proc (in, fd [1], cmd[i]);

      /* No need for the write end of the pipe, the child will write here.  */
      close (fd [1]);

      /* Keep the read end of the pipe, the next child will read from there.  */
      in = fd [0];
    }

  /* Last stage of the pipeline - set stdin be the read end of the previous pipe
     and output to the original file descriptor 1. */
  if (in != 0)
    dup2 (in, 0);

    int fildes = open(fileout, O_RDWR|O_CREAT|O_TRUNC, 0666);
    if (fildes == -1) { /* bad file name */ perror("demo"); exit(1);}
    dup2(fildes,1);   /* copy fildes to 1 */
    close(fildes);    /* conserve file descriptors by closing excess one */


  /* Execute the last stage with the current process. */
  return run_command(cmd[i]);
}


int main (int argc, char **argv)
{
    char *input = NULL;
    size_t alloc_len = 0;

    ssize_t len = getline (&input, &alloc_len, stdin);
    if (input[len-1] == '\n')
    {
        input[len-1] = '\0';
        len--;
    }

    if (len != -1)
    {
        int cmd_num = 1;
        char * cmds[len/2];
        cmds[0] = input;

        for (ssize_t i=0; i<len-1; i++)
        {
            if (input[i] == '|')
            {
                cmds[cmd_num] = &(input[i+1]);
                cmd_num ++;
                input[i] = '\0';
            }
        }

        fork_pipes (cmd_num, cmds);
    }
    else
    {
        fprintf (stderr,"read error\n");
    }

    free(input);
    return 0;
}
