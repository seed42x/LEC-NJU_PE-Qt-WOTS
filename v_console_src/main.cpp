#include"General.h"
#include"System.cpp"

int main()
{
    System* sys = new System();
    sys->exec();
    delete sys;
    return 0;
}