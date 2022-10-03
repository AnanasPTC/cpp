#include "Random.h"
#include "random.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

mt19937 Random::mt(time(nullptr));

Random::Random(int mini, int maxi, int taille, bool exclusif)
{
    this->mini=mini;
    this->maxi=maxi;
    this->taille=taille;
    this->exclusif=exclusif;

    inversionMaxiMini();
    dis = uniform_int_distribution <int>(this->mini,this->maxi);
    testTaille();
    remplirTab();
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
    return dis(mt);
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
    int alea;
    tabRandom.clear();

    do
    {
        alea=calculValeur();
        if(exclusif)
            while(find(tabRandom.begin(), tabRandom.end(),alea) != tabRandom.end())
                alea=calculValeur();

        tabRandom.push_back(alea);

    }while(static_cast <int>(tabRandom.size()) < taille);
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
    inversionMaxiMini(valMini,valMaxi);
    uniform_int_distribution<int> dis (valMini,valMaxi);
    return dis(mt);
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

void Random::inversionMaxiMini(int & mini,int & maxi)
{
    int tempon;

    if(mini>maxi)
    {
        tempon=mini;
        mini=maxi;
        maxi=tempon;
    }
}
