#ifndef SYSTEM_H
#define SYSTEM_H

#include "General.h"
#include "Usr.h"


class System
{
private:
    static Usr* cur_usr_;
public:
    System();
    static void set_cur_usr(Usr* usr) { cur_usr_ = usr; }
    static Usr* get_cur_usr() { return cur_usr_; }
};

#endif // SYSTEM_H
