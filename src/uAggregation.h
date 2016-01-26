#ifndef UAGGREGATION_H
#define UAGGREGATION_H

#include "uReference.h"

/**
 * @brief The uAggregation class symbolizes an Uml Aggregation
 */

class uAggregation : public uReference
{
public:
    //Constructor
    uAggregation(uInheritable * reference, uAccess access);
};

#endif // UAGGREGATION_H
