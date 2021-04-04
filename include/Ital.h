#ifndef ITAL_H
#define ITAL_H

#include "Targy.h"

class Ital : public Targy
{
    int eleteroPlusz;

    public:
        Ital();
        Ital(std::string,int,int,int,int,int);
        virtual ~Ital();

        int getEleteroPlusz() {return eleteroPlusz;}
        void setEleteroPlusz(int EleteroPlusz) {eleteroPlusz = EleteroPlusz;}
        Targy& clone() const;
};

std::ostream& operator<<(std::ostream&, const Ital&);

#endif // ITAL_H
