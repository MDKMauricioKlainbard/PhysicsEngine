#include <iostream>
#include <vector>
#include <cmath>
#include <exception>
#include "SimplePendulum.h"

int main()
{
    try
    {
        SimplePendulum pendulum(1.0, 9.81);
        pendulum.set_state({3.14159 / 4.0}, {0.0});
        pendulum.run_simulation(0.0, 10.0, 0.01, "pendulum_data.csv");
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}