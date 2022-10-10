#include <vector>

using namespace std;

class RC4
{
	public:
	unsigned char chiffrage(unsigned char octet);
	vector<unsigned char> getCle();
	unsigned int getTailleCle();
	void initCodageDecodage();
	RC4(unsigned int tailleCle=0);
	RC4(unsigned char *cle,int tailleCle);
	RC4(vector<unsigned char>cle);
	

	private:
	void genereCle();
	void melangeTableauEtat();
	void swap(unsigned char *vall,unsigned char *val2);
	unsigned int i;
	unsigned int j;
	vector< unsigned char> maCle;
	vector<unsigned char>tableauEtat;
	unsigned int tailleCle;
	const unsigned int tailleTableauEtat;
};

#endif