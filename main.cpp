#include <iostream>
#include "boost/regex.hpp"
#include "zlib.h"

int main2();
int main3();

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Compiled with zlib " << ZLIB_VER_MAJOR << "." << ZLIB_VER_MINOR << std::endl;

    std::string s = "Boost Libraries";
    boost::regex expr{"\\w+\\s\\w+"};
    std::cout << std::boolalpha << boost::regex_match(s, expr) << '\n';
    std::cout << std::noboolalpha << boost::regex_match(s, expr) << '\n';

    main2();
    main3();

    return 0;
}

#include <boost/units/systems/si/energy.hpp>
#include <boost/units/systems/si/force.hpp>
#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/electric_potential.hpp>
#include <boost/units/systems/si/current.hpp>
#include <boost/units/systems/si/resistance.hpp>
#include <boost/units/systems/si/io.hpp>

using namespace boost::units;
using namespace boost::units::si;

quantity<energy>
work(const quantity<force>& F, const quantity<length>& dx)
{
    return F * dx; // Defines the relation: work = force * distance.
}

int main2()
{
    /// Test calculation of work.
    quantity<force>     F(2.0 * newton); // Define a quantity of force.
    quantity<length>    dx(2.0 * meter); // and a distance,
    quantity<energy>    E(work(F,dx));  // and calculate the work done.

    std::cout << "F  = " << F << std::endl
              << "dx = " << dx << std::endl
              << "E  = " << E << std::endl
              << std::endl;

    return 0;
}

#include <Poco/BasicEvent.h>
#include <Poco/Delegate.h>
#include <iostream>

using Poco::BasicEvent;
using Poco::Delegate;

class Source
{
public:
    BasicEvent<int> theEvent;

    void fireEvent(int n)
    {
        theEvent(this, n);
    }
};

class Target
{
public:
    void onEvent(const void* pSender, int& arg)
    {
        std::cout << "onEvent: " << arg << std::endl;
    }
};

int main3()
{
    Source source;
    Target target;

    source.theEvent += Delegate<Target, int>(
        &target, &Target::onEvent);

    source.fireEvent(42);

    source.theEvent -= Delegate<Target, int>(
        &target, &Target::onEvent);

    return 0;
}
