#include "perason.h"

int main()
{
    Person person("Jakey", "Slong");
    person.Show();

    Gunslinger gl("Tidy", "White", 12);
    gl.Show();
    cout << "Gunslinger's nick is " << gl.Draw() << endl;

    PokerPlayer pokerplayer;
    pokerplayer.Show();
    
}