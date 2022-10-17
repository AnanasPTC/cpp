#include "RC4.h"
#include <iostream>
#include "random.h"

RC4::RC4(unsigned int tailleCle=0)
{
	if(tailleCle==0)
	{
		tailleCle=Random::valeurUnique(40,255);
	}
	genereCle();
}

RC4::RC4(unsigned char* cle,int taille)
{
	
}

RC4::RC4(vector<unsigned char> cle)
{
	
}

unsigned char RC4::chiffrage(unsigned char octet)
{
	i=(i+1)%tailleTableauEtat;
	j=(j+tableauEtat[i])%tailleTableauEtat;
	swap(tableauEtat[i],tableauEtat[j]);
	n=(tableauEtat[i]+tableauEtat[j])%tailleTableauEtat;
	
	octet=octet ^ tableauEtat[n];
}

void RC4::genereCle()
{
	
}

vector<unsigned char> RC4::getCle()
{
	return cle;
}

unsigned int RC4::getTailleCle()
{
	return tailleCle;
}

void RC4::initCodageDecodage()
{
	for(int i=0;i<tailleTableauEtat-1;i++)
	{
		tableauEtat[i]=i
	}
}

void RC4::melangeTableauEtat()
{
	j=0;
	for(int i=0;i<tailleTableauEtat-1;i++)
	{
		indiceCle=i%tailleCle;
		j=(j+tableauEtat[i]+maCle[indiceCle])%tailleTableauEtat;
		swap(tableauEtat[i],tableauEtat[j]);
	}
	i=0;
	j=0;
}

void RC4::swap(unsigned char* val1,unsigned char* val2)
{
	int inter;
	inter=val1;
	val1=val2;
	val2=inter;
}

