#ifndef RANDOM_H
#define RANDOM_H
#include <vector>
#include <random>
#include <vector>

using namespace std ;

class Random
{
    public:
        Random(int mini, int maxi, int taille, bool exclusif=false);
        ~Random();
        int 	getMaxi () const;
        int 	getMini () const;
        vector< int > 	getTableau () const;
        int 	getTaille () const;
        int 	operator[] (int indice) const;
        void 	remplirTab ();
        void 	setMaxi (int maxi);
        void 	setMini (int mini);
        void 	setTaille (int taille);

        static int 	valeurUnique (int valMini, int valMaxi);

    protected:

    private:
        int 	calculValeur ();
        void 	inversionMaxiMini ();
        void 	testTaille ();
        uniform_int_distribution<int> dis;
        static void 	inversionMaxiMini (int &mini, int &maxi);
        bool    exclusif;
        int     maxi;
        int     mini;
        vector<int>     tabRandom;
        int     taille;

        static mt19937 mt;

};

#endif // RANDOM_H
