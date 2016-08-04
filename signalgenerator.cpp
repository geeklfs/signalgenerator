#include <signalgenerator.h>

namespace std
{
    signalgenerator::signalgenerator(const double a = 1.0, const double f = 1.0) : amplitude(a), frequency(f)
    {

    }
    const double signalgenerator::value(const double x)
    {
      if(x < 0 )
      {
        return 0;
      }
      else
      {
        return amplitude * ::sin((two_pi * frequency) * x);
      }
    }

    void signalgenerator::getsinvalue(const float last_time, callbackfun p)
    {
        const int point = 100; //show 100 point in every period
        ofstream file("out_sin.cvs");
        if (!file.is_open())
        {
            std:cout<<"open file error."<<endl;
        }
        file << amplitude << "," << frequency << endl;
        for(int i = 0; i < last_time * point - 1; i++)
        {
            const double x = static_cast<double>(i) / point;
            usleep(int(1000000/point));  //delay ms
            callFunction(p,signalgenerator::value(x));
            //std::cout << x << "," << signalgenerator::value(x) << endl;
            //file << std::setprecision(4) << x << "," << signalgenerator::value(x) << endl;
        }
    }

    void signalgenerator::getsquarewave(const float last_time, callbackfun p)
    {
        const int point = 100;
        unsigned char up = 1;
        float out_value = signalgenerator::amplitude;
        ofstream file("out_square.cvs");
        if (!file.is_open())
        {
            std:cout<<"open file error."<<endl;
        }
        file << amplitude << "," << frequency << endl;
        for(int i = 0; i < last_time * point - 1; i++)
        {
            const double x = static_cast<double>(i) / point;
            usleep(int(1000000/point));
            if(int(2.0*signalgenerator::frequency*i/point)%2==0)
            {
                out_value = signalgenerator::amplitude;
            }
            else
            {
                out_value = -signalgenerator::amplitude;
            }
            callFunction(p,out_value);
            //std::cout << x << "," << out_value << endl;
            //file << std::setprecision(4) << x << "," << out_value << endl;
        }
    }
    void signalgenerator::callFunction(callbackfun p, double x)
    {
        p(x);
    }
}
