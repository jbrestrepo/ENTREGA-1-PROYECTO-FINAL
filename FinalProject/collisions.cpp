#include "collisions.hpp"

double compute_fvelProjCol (double velproj, double mass1, double mass2)
{
    double fvelProy;

    fvelProy = (((mass1 - mass2)*velproj)/(mass1 + mass2));

    return fvelProy;
}

double compute_fvelTargCol (double velproj, double mass1, double mass2)
{
    double fvelTar;

    fvelTar = ((2*mass1*velproj)/(mass1 + mass2));

    return fvelTar;
}
