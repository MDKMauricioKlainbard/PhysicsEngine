cmake_minimum_required(VERSION 3.10)
project(PhysicsEngine VERSION 1.0)

add_library(CorePhysics 
    src/LagrangianSystem.cpp 
    src/SimplePendulum.cpp
)   

target_include_directories(CorePhysics PUBLIC include)

add_executable(Simulator examples/pendulum_demo.cpp)

target_link_libraries(Simulator CorePhysics)