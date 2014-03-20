#include <iostream>
#include "ot-blaze.h"
#include "ot-blazePriv.h"

void ot_blaze::HelloWorld(const char * s)
{
	 ot_blazePriv *theObj = new ot_blazePriv;
	 theObj->HelloWorldPriv(s);
	 delete theObj;
};

void ot_blazePriv::HelloWorldPriv(const char * s) 
{
	std::cout << s << std::endl;
};
