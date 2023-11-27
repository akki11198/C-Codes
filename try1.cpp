#include <iostream>
using namespace std;
class player
{
private:
    static int count;

public:
    player()
    {
        count++;
    }
    ~player()
    {
        count--;
    }
    static int get_count()
    {
        return count;
    }
};
int player ::count = 0;
int main()
{
    player p1, p2;
    cout << player ::get_count() << endl;
    player p3;
    cout << player ::get_count() << endl;
    player p4;
    {
        player p5;
        cout << player ::get_count() << endl;
    }
    cout << player ::get_count() << endl;
    return 0;
}