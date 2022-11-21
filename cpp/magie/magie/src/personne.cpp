#include "Personne.h"
#include "iostream"

const int Personne::AGE_MAXI = 120;

Personne::Personne(std::string nom, int age)
{
    this->nom = nom;
    if (!this->setAge(age)) {
        this->age = AGE_DEFAUT;
    }
}

Personne::~Personne()
{
    //dtor
}
int Personne::getAge()
{
    return this->age;
}

void Personne::sePresenter()
{
    std::cout << "Bonjour, je m'appelle " + this->nom;

    if (this->getAge() != -1) {
        std::cout << "Et mon age et de " << this->getAge();
    }

    std::cout << std::endl;
}

bool Personne::setAge(int age)
{
    bool vraixAge = false;
    if ( (this->AGE_MAXI > age) && (this->AGE_MINI < age) ) {
        this->age = age;
        vraixAge = true;
    }
    return vraixAge;
}

std::string Personne::getNom()
{
    return this->nom;
}
