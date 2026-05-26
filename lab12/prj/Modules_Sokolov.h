#ifndef MODULESSOKOLOV_H
#define MODULESSOKOLOV_H

class ClassLab12_Sokolov {
private:
    double edge;

public:
    ClassLab12_Sokolov(double a = 1.0) {
        if (!setEdge(a)) {
            edge = 1.0;
        }
    }

    bool setEdge(double a) {
        if (a > 0.0) {
            edge = a;
            return true;
        }
        return false;
    }

    double getEdge() const {
        return edge;
    }

    double getVolume() const {
        return edge * edge * edge;
    }
};

#endif // MODULESSOKOLOV_H
