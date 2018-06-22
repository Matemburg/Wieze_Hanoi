#include <iostream>
#include <conio.h>//getchar()
#include <fstream>

using namespace std;
int lp=0;//globalny licznik przesuniêæ
void hanoi(int lw,int lk, char A, char B, char C )
{
    if (lw>3 && lk > 1 )//rozk³adanie pojedyñczych klocków na s³upki
    {
        cout << A << " " << lw << endl;
        lp++;
        hanoi(lw-1,lk-1, '1', '2', '3' );
        cout << lw << " " << C << endl;
        lp++;
    }
    else if( lk > 0 )// algorym
    {
        hanoi(lw,lk - 1, A, C, B );
        cout << A << " " << C << endl;
        lp++;
        hanoi(lw,lk - 1, B, A, C );
    }
}

int main()
{
    cout << " wybierz try programu \n 1 Tryb manualny \n 2 Tryb badania automatycznego \n";
    int wybor;
    cin >> wybor;
    if (wybor==1)
    {
        cout<<"podaj liczbe krazkow \n";
        int lk;
        cin >> lk;
        cout<<"podaj liczbe wierz \n";
        int lw;
        cin >> lw;
        hanoi(lw,lk,'1','2','3');
        cout<<"liczba rochow wyniosla " << lp << endl;
    }
    else
    {
        ofstream zapis;
        zapis.open("wyniki.txt");
        for (int i=3; i<14; i++)
        {
            for (int j=3; j<9; j++)
            {

                hanoi(j,i, '1', '2', '3' );
              //  zapis<< "liczba krazkow " << i <<  " liczba wierz " << j  << " liczba przesuniec " << lp <<endl;
              zapis<< i <<  " " << j  << " " << lp <<endl;
                lp=0;
            }
        }
    }
    getch();
    return 0;
}
