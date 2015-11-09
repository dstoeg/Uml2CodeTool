#ifndef UAGGREGATION_H
#define UAGGREGATION_H

#include "uReference.h"

class uAggregation : public uReference
{
public:
    uAggregation(uInheritable * reference, uAccess access);
};

#endif // UAGGREGATION_H
