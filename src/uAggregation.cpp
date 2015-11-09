#include "uAggregation.h"

// "has-a" relationship, by reference
uAggregation::uAggregation(uInheritable * reference, uAccess access) : uReference(reference, access)
{
    refereceSymbol = "*";
}
