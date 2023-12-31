#include "methodtr.h"

QPair<Trajectories, Trajectories> MethodTR::start(const LotkaVolterraEquation &eq) const {
    std::mt19937 gen;
    uint seed = std::chrono::system_clock::now().time_since_epoch().count();
    gen.seed(seed);
    std::normal_distribution<double> dist(0., dev);
    QPair<Trajectories, Trajectories> result;
    double dt = static_cast<double>(deltaT) / 1000;
    for(uint j = 0; j < m; ++j) {
        double A = eq.getStartA();
        double B = eq.getStartB();
        double vA = A;
        double vB = B;
        result.first.push_back(QVector<double>());
        result.second.push_back(QVector<double>());
        for(uint i = X; i < T; i += deltaT) {
            double dW1 = dist(gen) * sqrt(dt);
            double dW2 = dist(gen) * sqrt(dt);

            A += (eq.A(vA, B) + eq.prodA(B) * (A - vA)) * dt + dW1;
            B += (eq.B(A, vB) + eq.prodB(A) * (B - vB)) * dt + dW2;

            result.first[j].push_back(A);
            result.second[j].push_back(B);
        }
    }
    return result;
}
