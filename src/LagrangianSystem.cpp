#include "LagrangianSystem.h"
#include <stdexcept>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

LagrangianSystem::LagrangianSystem(int dof)
{
    if (!(dof > 0))
    {
        throw invalid_argument("Degrees of freedom must be greater than 0");
    }

    degrees_of_freedom = dof;
    q.resize(get_dof(), 0.0);
    q_dot.resize(get_dof(), 0.0);
    q_ddot.resize(get_dof(), 0.0);
}

LagrangianSystem::~LagrangianSystem()
{
}

void LagrangianSystem::set_state(const vector<double> &q_in, const vector<double> &q_dot_in)
{
    if (q_in.size() != get_dof() || q_dot_in.size() != get_dof())
    {
        throw invalid_argument("Vector length must be equal to DOF of the system");
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

void LagrangianSystem::run_simulation(double t0, double t_max, double dt, string filename)
{
    double t = t0;
    ofstream file;
    bool write_to_file = !filename.empty();

    if (write_to_file)
    {
        file.open(filename);
        if (!file.is_open())
        {
            throw runtime_error("Could not open file: " + filename);
        }
        file << "t";
        for (int i = 0; i < degrees_of_freedom; ++i)
            file << ",q" << i;
        for (int i = 0; i < degrees_of_freedom; ++i)
            file << ",v" << i;
        file << endl;

        cout << "Simulating... saving in " << filename << endl;
    }
    else
    {
        cout << "Simulating... (no output file)" << endl;
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
            file << endl;
        }

        this->compute_accelerations(t);
        this->step_integration(dt);

        t += dt;
    }

    if (write_to_file)
    {
        file.close();
        cout << "Simulation ended." << endl;
    }
}

vector<double> LagrangianSystem::get_q() const
{
    return q;
}

vector<double> LagrangianSystem::get_q_dot() const
{
    return q_dot;
}

int LagrangianSystem::get_dof() const
{
    return degrees_of_freedom;
}

vector<double> LagrangianSystem::get_q_ddot() const
{
    return q_ddot;
}
