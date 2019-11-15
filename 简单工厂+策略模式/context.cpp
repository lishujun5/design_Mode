#include "context.h"
double context::ContextInterface(double amount)
{
    return strategy->AlgorithmInterrace(amount);
}