#include <stdio.h>
#include <iostream>
#include <RC4.h>
#include <vector>

int main(int argc, char **argv)
{
	RC4 hermes;
	vector< unsigned char> cle;
	unsigned int taillecle;
	unsigned char octet = 'a';
	
	cle=hermes.getCle();
	taillecle=hermes.getTailleCle();
	octet=hermes.chiffrage(octet);
	
	cout<<"hello world\n";
	cout<<taillecle<<endl;
	for(unsigned int i=0;i<taillecle;i++)
	{
		cout<<i+1<<":"<<int(cle[i]) << " ";
	}
	cout<<endl;
	hermes.initCodageDecodage();
	octet=hermes.chiffrage(octet);
	cout<<octet<<endl;
	return 0;
}
