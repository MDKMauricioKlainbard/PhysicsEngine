#ifndef SIMPLE_PENDULUM_H
#define SIMPLE_PENDULUM_H
#include "LagrangianSystem.h"
#include <vector>

class SimplePendulum : public LagrangianSystem
{
public:
    SimplePendulum(double length, double gravity = 9.81);
    virtual ~SimplePendulum();

    virtual void compute_accelerations(double t) override;

    double get_L() const;
    double get_g() const;

private:
    double L;
    double g;
};

#endif
