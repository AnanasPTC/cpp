#pragma once
#include <vector>

using namespace std;

class RC4
{
public:
	unsigned char chiffrage(unsigned char octet);
	vector< unsigned char> getCle();
	unsigned int getTailleCle();
	void initCodageDecodage();
	RC4(unsigned int tailleCle = 0);
	RC4(unsigned char *cle, int tailleCle);
	RC4(vector<unsigned char>cle);

private:

};


