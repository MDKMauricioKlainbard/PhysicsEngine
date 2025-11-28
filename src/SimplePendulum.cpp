#include "SimplePendulum.h"
#include <cmath>
#include <stdexcept>
using namespace std;

SimplePendulum::SimplePendulum(double length, double gravity) : LagrangianSystem(1)
{
    if (!(length > 0) || !(gravity > 0))
    {
        throw invalid_argument("Length and gravity must be positive");
    }

    L = length;
    g = gravity;
}

SimplePendulum::~SimplePendulum()
{
}

void SimplePendulum::compute_accelerations(double t)
{
    double theta = q[0];
    q_ddot[0] = -(get_g() / get_L()) * sin(theta);
}

double SimplePendulum::get_L() const
{
    return L;
}

double SimplePendulum::get_g() const
{
    return g;
}