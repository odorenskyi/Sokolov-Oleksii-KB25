#ifndef MODULESSOKOLOV_H
#define MODULESSOKOLOV_H

class ClassLab12_Sokolov {
private:
    double edge;

public:
    ClassLab12_Sokolov(double a = 1.0);
    bool setEdge(double a);
    double getEdge() const { return edge; }
    double getVolume() const { return edge * edge * edge; }
};

ClassLab12_Sokolov::ClassLab12_Sokolov(double a) {
    if (!setEdge(a)) {
        edge = 1.0;
    }
}

bool ClassLab12_Sokolov::setEdge(double a) {
    if (a > 0.0) {
        edge = a;
        return true;
    }
    return false;
}

#endif // MODULESSOKOLOV_H
