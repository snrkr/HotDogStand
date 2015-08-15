#include <iostream>
using namespace std;

class HotDogStand
{
public:
    HotDogStand (int getid,int getsold);
    HotDogStand (int getid) : id(getid), sold(0) { }
    HotDogStand ()  : id(0), sold(0) { }
    void justSold() { sold++; allsold++; }
    int  numSold() { return sold; }
    static int totalSold () { return allsold; }
private:
    int id;
    int sold;
    static int allsold;
};

int HotDogStand::allsold = 0;

int main()
{
    HotDogStand stand1(1,3); // already sold 3 hot dogs
    HotDogStand stand2(2); // none sold yet
    HotDogStand stand3(3,5); // already sold 5
    
    // each stand sells 4 more
    for (int i = 0; i < 4; i++) {
        stand1.justSold();
        stand2.justSold();
        stand3.justSold();
    } // end for
    
    // stand 3 sells 2 extra
    stand3.justSold();
    stand3.justSold();

    cout << "stand 1 has sold " << stand1.numSold() << " hot dog(s)\n";
    cout << "stand 2 has sold " << stand2.numSold() << " hot dog(s)\n";
    cout << "stand 3 has sold " << stand3.numSold() << " hot dog(s)\n";
    cout << "total number of hog dogs sold: "
         << HotDogStand::totalSold() << endl;

    return 0;
}
HotDogStand::HotDogStand (int getid,int getsold)
                :id(getid), sold(getsold)
{ }