#include "spectateur.h"
#include <iostream>

spectateur::spectateur(string nom, int age, unsigned short argent=ARGENT_MAXI)
{
    this->nom=nom;
    this->age=age;
    this->argent=ARGENT_MAXI
}

spectateur::~spectateur()
{
    //dtor
}

arriverSurScene()
{
    cout<<"le spectateur"<<this->nom<<"arrive sur scène";

}

sePresenter()
{
    cout<<"Bonjour,je m'appelle"<<this->nom;
}


