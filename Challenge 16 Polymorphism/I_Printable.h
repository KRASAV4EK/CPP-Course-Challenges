#ifndef _I_PRINTABLE_
#define _I_PRINTABLE_

#include <iostream>

class I_Printable {
public:
    virtual void print(std::ostream &os) const = 0;
    virtual ~I_Printable() = default;
};

#endif // _I_PRINTABLE_
