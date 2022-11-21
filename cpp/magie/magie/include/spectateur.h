#ifndef SPECTATEUR_H
#define SPECTATEUR_H
#include <string>


class spectateur
{
    public:
        spectateur(string nom, int age, unsigned short argent=ARGENT_MAXI);
        virtual ~spectateur();
        void arriverSurScene();
        void sePresenter();


    protected:
        Personne (string nom, int age=AGE_DEFAUT)

    private:
        unsigned short argent;

        static const int ARGENT_MAXI=99;
};

#endif // SPECTATEUR_H
