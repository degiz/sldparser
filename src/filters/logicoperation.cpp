#include "logicoperation.h"

namespace automap {

void LogicOperation::add(Operation operation)
{
    _operations.push_back(operation);
}

}