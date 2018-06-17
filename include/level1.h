#ifndef LEVEL1_H
#define LEVEL1_H

#include "baselevel.h"

class Level1 : public BaseLevel {
public:
    Level1();
    virtual void handle_events() override;
    virtual void logic() override;
};

#endif // LEVEL1_H
