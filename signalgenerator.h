#ifndef SIGNALGENERATOR
#define SIGNALGENERATOR

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <limits>
#include <complex>
#include <fstream>
#include <unistd.h>

namespace std
{

    class signalgenerator
    {
        public:

            /// Get precise 2pi value
            const double two_pi = ::atan(1) * 8.0;
            /// Function pointer to jump into circulate
            typedef void (*callbackfun)(const float&);


        private:

          const double amplitude;
          const double frequency;

        public:

          signalgenerator(double, double);
          /// Return sin value
          const double value(const double x);

          /// Generate sin wave
          /// @param[in] total time that the sin wave last
          /// @param[out] void
          void getsinvalue(const float last_time, callbackfun p);

          /// Generate square wave
          /// @param[in] total time that the sin wave last
          /// @param[out] void
          void getsquarewave(const float last_time, callbackfun p);

          /// Callback function
          void callFunction(callbackfun p, double x);
    };
 }


#endif // SIGNALGENERATOR

