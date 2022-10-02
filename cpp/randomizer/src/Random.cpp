#include "Random.h"
#include "random.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

Random::Random(int mini, int maxi, int taille, bool exclusif)
{

}

Random::~Random()
{
    //dtor
}

void Random::inversionMaxiMini()
{
    if (mini>maxi)
    {
        int temp;
        temp=mini;
        mini=maxi;
        maxi=temp;
    }
}

int Random::calculValeur()
{

}

void Random::testTaille()
{
    if (exclusif ==true)
    {
        int nbele;
        nbele=maxi-mini;
        nbele++;
        setTaille(nbele);
    }
}

int Random::getMaxi() const
{
    return maxi;
}

int Random::getMini() const
{
    return mini;
}

vector<int> Random::getTableau() const
{
    return tabRandom;
}

int Random::getTaille() const
{
    return taille;
}

void Random::remplirTab()
{

}

void Random::setMaxi(int maxi)
{
    this->maxi = maxi;
    remplirTab();
}

void Random::setMini(int mini)
{
    this->mini = mini;
    remplirTab();
}

void Random::setTaille(int taille)
{
    this->taille = taille;
    remplirTab();
}

int Random::valeurUnique(int valMini,int valMaxi)
{

}

int Random::operator[](int indice) const
{
    int reponse;
    if (indice>taille-1)
    {
        reponse=-1;
    }
    else
    {
        reponse=tabRandom[indice];
    }
    return reponse;
}
