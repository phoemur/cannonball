#ifndef LEVEL4_H
#define LEVEL4_H

#include "baselevel.h"

class Level4 : public BaseLevel
{
public:
    Level4();
    virtual void handle_events() override;
    virtual void logic() override;
};

#endif // LEVEL4_H
