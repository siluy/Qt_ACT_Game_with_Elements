#include "Throwable.h"

bool Throwable::isThrown() const{
    return thrown;
}

void Throwable::endThrown(){
    thrown = false;
}

void Throwable::startThrown(){
    thrown = true;
}
