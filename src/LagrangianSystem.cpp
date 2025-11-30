#include "LagrangianSystem.h"
#include <stdexcept>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

LagrangianSystem::LagrangianSystem(int dof)
{
    if (!(dof > 0))
    {
        throw std::invalid_argument("Degrees of freedom must be greater than 0");
    }

    degrees_of_freedom = dof;
    q.resize(get_dof(), 0.0);
    q_dot.resize(get_dof(), 0.0);
    q_ddot.resize(get_dof(), 0.0);
}

LagrangianSystem::~LagrangianSystem()
{
}

void LagrangianSystem::set_state(const std::vector<double> &q_in, const std::vector<double> &q_dot_in)
{
    if (q_in.size() != get_dof() || q_dot_in.size() != get_dof())
    {
        throw std::invalid_argument("Vector length must be equal to DOF of the system");
    }

    q = q_in;
    q_dot = q_dot_in;
}

void LagrangianSystem::step_integration(double dt)
{
    for (int i = 0; i < degrees_of_freedom; ++i)
    {
        q_dot[i] += q_ddot[i] * dt;
        q[i] += q_dot[i] * dt;
    }
}

void LagrangianSystem::run_simulation(double t0, double t_max, double dt, std::string filename)
{
    double t = t0;
    std::ofstream file;
    bool write_to_file = !filename.empty();

    if (write_to_file)
    {
        file.open(filename);
        if (!file.is_open())
        {
            throw std::runtime_error("Could not open file: " + filename);
        }
        file << "t";
        for (int i = 0; i < degrees_of_freedom; ++i)
            file << ",q" << i;
        for (int i = 0; i < degrees_of_freedom; ++i)
            file << ",v" << i;
        file << std::endl;

        std::cout << "Simulating... saving in " << filename << std::endl;
    }
    else
    {
        std::cout << "Simulating... (no output file)" << std::endl;
    }

    while (t < t_max)
    {
        if (write_to_file)
        {
            file << t;
            for (double val : q)
                file << "," << val;
            for (double val : q_dot)
                file << "," << val;
            file << std::endl;
        }

        this->compute_accelerations(t);
        this->step_integration(dt);

        t += dt;
    }

    if (write_to_file)
    {
        file.close();
        std::cout << "Simulation ended." << std::endl;
    }
}

std::vector<double> LagrangianSystem::get_q() const
{
    return q;
}

std::vector<double> LagrangianSystem::get_q_dot() const
{
    return q_dot;
}

int LagrangianSystem::get_dof() const
{
    return degrees_of_freedom;
}

std::vector<double> LagrangianSystem::get_q_ddot() const
{
    return q_ddot;
}
