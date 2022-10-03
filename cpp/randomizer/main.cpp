#include <iostream>
#include "Random.h"

using namespace std;

int main()
{
    Random hestia(0,150,20,false);
    cout <<"max:"<< hestia.getMaxi() << endl;
    cout <<"min:"<< hestia.getMini() << endl;
    cout <<"taille:"<< hestia.getTaille() << endl;
    vector<int> tableau;
    tableau=hestia.getTableau();
    for(int i=0; i<20; i++)
    {
        cout<<tableau[i]<<endl;
    }
    cout <<"operator:"<< hestia[0] << endl;
    hestia.setMaxi(10);
    hestia.setMini(5);
    hestia.setTaille(10);
    hestia.valeurUnique(0,10);
    cout <<"max:"<< hestia.getMaxi() << endl;
    cout <<"min:"<< hestia.getMini() << endl;
    cout <<"taille:"<< hestia.getTaille() << endl;
    cout <<"operator:"<< hestia[0] << endl;
    return 0;
}
