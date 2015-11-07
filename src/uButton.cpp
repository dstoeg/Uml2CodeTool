#include "uButton.h"

uButton* uButton::getInstance()
{
    if(mInstance == 0)
        mInstance = new uButton();

    return mInstance;
}


