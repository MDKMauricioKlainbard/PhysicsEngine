#ifndef LAGRANGIAN_SYSTEM_H
#define LAGRANGIAN_SYSTEM_H
#include <vector>
#include <string>

class LagrangianSystem
{
public:
    LagrangianSystem(int num_degrees_of_freedom);
    virtual ~LagrangianSystem();

    virtual void compute_accelerations(double t) = 0;

    void set_state(const std::vector<double> &q, const std::vector<double> &q_dot);
    void run_simulation(double t0, double t_max, double dt, std::string filename = "");

    std::vector<double> get_q() const;
    std::vector<double> get_q_dot() const;
    std::vector<double> get_q_ddot() const;

    int get_dof() const;

protected:
    virtual void step_integration(double dt);
    std::vector<double> q;
    std::vector<double> q_dot;
    std::vector<double> q_ddot;

private:
    int degrees_of_freedom;
};

#endif