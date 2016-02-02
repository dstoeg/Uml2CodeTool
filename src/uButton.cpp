#include "uButton.h"

uButton &uButton::getInstance()
{
    static uButton mInstance;
    return mInstance;
}

uButton::uButton(){

}

