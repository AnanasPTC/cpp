/**
*   \file random.cpp
*   \brief Tableau de nombres aléatoires.
*
*   Permet de disposer d'un tabeau de valeurs aléatoires évolutif.
*/
/**************************** Inclusion de fichier ****************************/
#include "random.h"
#include <stdlib.h>
#include <time.h>
#include <algorithm>

mt19937 Random::mt(time(nullptr));

/**
*   Initialise les attributs et remplit le tableau.
*
*   \param [in] mini valeur mini possible.
*   \param [in] maxi valeur maxi possible.
*   \param [in] taille taille du tableau.
*   \param [in] exclusif valeur unique ou non.
*/
/******************************************************************************/
Random::Random(int mini,int maxi,int taille,bool exclusif)
{

    this->maxi = maxi;
    this->mini = mini;
    this->taille = taille;
    this->exclusif = exclusif;

    //mt.seed(time(nullptr));
    inversionMaxiMini();
    dis = uniform_int_distribution <int>(this->mini,this->maxi);
    testTaille();
    remplirTab();
}


/**
*   Si mini > maxi les inverse
*
*   \param [in] mini valeur mini.
*   \param [in] maxi valeur maxi.
*/
/******************************************************************************/
void Random::inversionMaxiMini(int & mini,int & maxi)
{
    int inter;

    if(mini>maxi)
    {
        inter=mini;
        mini=maxi;
        maxi=inter;
    }
}

/**
*   Si mini > maxi les inverse
*/
/******************************************************************************/
void Random::inversionMaxiMini()
{
    int inter;

    if(mini>maxi)
    {
        inter=mini;
        mini=maxi;
        maxi=inter;
    }
}

/**
*   Rempli le tableau en tenant compte de la valeur de exclusif (valeur unique ou non)
*/
/******************************************************************************/
void Random::remplirTab()
{
    int aleatoire;
    tabRandom.clear();

    do
    {
        aleatoire=calculValeur();
        if(exclusif)
            while(find(tabRandom.begin(), tabRandom.end(),aleatoire) != tabRandom.end())
                aleatoire=calculValeur();

        tabRandom.push_back(aleatoire);

    }
    while(static_cast <int>(tabRandom.size()) < taille);
}


/**
*   Si exclusif est vrai test la taille du tableau et le repositionne si trop grand.
*/
/******************************************************************************/
void Random::testTaille()
{
    if(exclusif)
        if(maxi - mini + 1 < taille)
            taille = maxi - mini + 1;
}


/**
*   Calcul une valeur aléatoire dans la fourchette (maxi et mini).
*
*   \return valeur calculée.
*/
/******************************************************************************/
int Random::calculValeur()
{
     return dis(mt);
}


/**
*   Retourne une valeur aléatoire dans la fourchette spécifiée.
*
*   \param [in] mini minimum de la fourchette.
*   \param [in] maxi maximum de la fourchette.
*
*   \return donnée calculée.
*/
/******************************************************************************/
int Random::valeurUnique(int mini,int maxi)
{
    inversionMaxiMini(mini,maxi);

    uniform_int_distribution<int> dis(mini,maxi);

    return dis(mt);
}


/**
*   Retourne la taille du tableau.
*
*   \return taille du tableau.
*/
/******************************************************************************/
int Random::getTaille()const
{
    return taille;
}


/**
*   Modifie la valeur maxi et reremplit le tableau.
*
*   \param [in] taille nouvelle taille du tableau.
*/
/******************************************************************************/
void Random::setTaille(int taille)
{
    this->taille = taille;
    testTaille();
    remplirTab();
}

/**
*   Retourne la valeur maxi possible.
*
*   \return valeur maxi possible.
*/
/******************************************************************************/
int Random::getMaxi()const
{
    return maxi;
}

/**
*   Modifie la valeur maxi et reremplit le tableau.
*
*   \param [in] maxi nouvelle valeur maxi.
*/
/******************************************************************************/
void Random::setMaxi(int maxi)
{
    this->maxi = maxi;
    inversionMaxiMini();
    dis = uniform_int_distribution <int>(this->mini,this->maxi);
    testTaille();
    remplirTab();
}


/**
*   Retourne la valeur mini possible.
*
*   \return valeur mini possible.
*/
/******************************************************************************/
int Random::getMini()const
{
    return mini;
}

/**
*   Modifie la valeur mini et reremplit le tableau.
*
*   \param [in] mini nouvelle valeur mini.
*/
/******************************************************************************/
void Random::setMini(int mini)
{
    this->mini = mini;
    inversionMaxiMini();
    dis = uniform_int_distribution <int>(this->mini,this->maxi);
    testTaille();
    remplirTab();
}

/**
*   Retourne la valeur présente dans la case dont l'indice est spécifié.
*
*   \param [in] indice indice de la case.
*
*   \return valeur de la case.
*
*   \remarks si l'indice est hors tableau on retourne -1.
*/
/******************************************************************************/
int Random::operator[](int indice)const
{
    int res = -1;

    if(indice < taille)
        res = tabRandom[indice];
    return res;
};


/**
*   Retourne le tableau.
*
*   \return tableau des valeurs aléatoires.
*/
/******************************************************************************/
vector <int> Random::getTableau() const
{
    return tabRandom;
}
