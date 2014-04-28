#include "prey.h"

Prey::Prey() : Organism()
{
    Genotype = 'O';
}

void Prey::breed(Organism *&target)
{

}

void Prey::move(Organism *&target)
{
    if(target)
        qDebug() << "ERROR : Your prey move to non empty grid";
    target = this;
}

void Prey::print()
{
    cout << "Prey(" << steps << ")";
}

Prey::~Prey(){}