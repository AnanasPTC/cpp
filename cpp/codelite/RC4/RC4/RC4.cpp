#include "RC4.h"
#include <iostream>
#include "random.h"

RC4::RC4(unsigned int tailleCle):tailleTableauEtat(256)
{
	this->tailleCle = tailleCle;
	if(tailleCle == 0)
	{
		this->tailleCle=Random::valeurUnique(40,255);
	}
	genereCle();
	this->tableauEtat.resize(tailleTableauEtat);
	initCodageDecodage();
}

RC4::RC4(unsigned char* cle,int taille):tailleTableauEtat(256)
{
	copy(cle, cle+taille, maCle.begin());
	this->tailleCle=taille;
	initCodageDecodage();
}

RC4::RC4(vector<unsigned char> cle):tailleTableauEtat(256)
{
	this->maCle=cle;
	this->tailleCle=cle.size();
	initCodageDecodage();
}

unsigned char RC4::chiffrage(unsigned char octet)
{
	unsigned int n;
	i=(i+1)%tailleTableauEtat;
	j=(j+tableauEtat[i])%tailleTableauEtat;
	swap(&tableauEtat[i],&tableauEtat[j]);
	n=(tableauEtat[i]+tableauEtat[j])%tailleTableauEtat;
	
	octet=octet ^ tableauEtat[n];
	return octet;
}

void RC4::genereCle()
{
	Random ares(1,255,tailleCle,false);
	vector<int> cle=ares.getTableau();
	maCle.resize(cle.size());
	copy(cle.begin(),cle.end(),maCle.begin());
}

vector<unsigned char> RC4::getCle()
{
	return maCle;
}

unsigned int RC4::getTailleCle()
{
	return tailleCle;
}

void RC4::initCodageDecodage()
{
	for(unsigned int i=0;i<tailleTableauEtat;i++)
	{
		tableauEtat[i]=i;
	}
	melangeTableauEtat();
}

void RC4::melangeTableauEtat()
{
	unsigned int indiceCle;
	j=0;
	for(unsigned int i=0;i<tailleTableauEtat;i++)
	{
		indiceCle=i%tailleCle;
		j=(j+tableauEtat[i]+maCle[indiceCle])%tailleTableauEtat;
		swap(&tableauEtat[i],&tableauEtat[j]);
	}
	i=0;
	j=0;
}

void RC4::swap(unsigned char* val1,unsigned char* val2)
{
	unsigned char inter;
	inter=*val1;
	*val1=*val2;
	*val2=inter;
}

