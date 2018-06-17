#ifndef LEVEL3_H
#define LEVEL3_H

#include "baselevel.h"

class Level3 : public BaseLevel
{
public:
    Level3();
    virtual void handle_events() override;
    virtual void logic() override;
};

#endif // LEVEL3_H
