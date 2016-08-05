/// Test signal generator
#include <signalgenerator.h>

using namespace std;

void plotvalue(const float& a)
{
    std::cout << std::setprecision(4) << a << endl;
}

int main(int argc, char* argv[])
{
     signalgenerator sinwave(8.0,2);
     sinwave.getsinvalue(4.3,plotvalue);
     signalgenerator squarewave(7.0,1.5);
     squarewave.getsquarewave(4,plotvalue);
    return 0;
}
