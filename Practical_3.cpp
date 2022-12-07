#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
main(void)
{
    int a;
    cout << "Hello" << endl;
    cout << "I am exec.c called by execvp()" << endl;
    cout << "In fork command" << endl;
    a = fork();
    wait(NULL);

    if (a > 0)
    {
        cout << "Parent PID is " << getpid();
        cout << "Parent PPID is " << getppid();
    }
    if (a == 0)
    {
        cout << "Child PID is " << getpid();
        cout << "Child PPID is" << getppid();
    }
    cout << "Work Done" << endl;
    sleep(4);
    cout << "Work Accomplished" << endl;
}