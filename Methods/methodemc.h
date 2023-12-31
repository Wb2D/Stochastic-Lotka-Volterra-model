#ifndef METHODEMC_H
#define METHODEMC_H

#include "Method.h"

class MethodEMC : public Method
{
public:
    MethodEMC(const uint &T, const uint &k, const uint &m, const uint &X, const double &dev) :
        Method(T, k, m, X, dev) {}

    QPair<Trajectories, Trajectories> start(const LotkaVolterraEquation&) const override;
};

#endif // METHODEMC_H
