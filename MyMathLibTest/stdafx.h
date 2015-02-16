
#ifndef STD_AFX_H
#define STD_AFX_H

#define _VARIADIC_MAX 10

#if _MSC_VER >= 1700
#pragma comment(lib, "gtestx64.lib")
#pragma comment(lib, "gtestdx64.lib")

#elif _MSC_VER >= 1600
#pragma comment(lib, "gtestdx86.lib")

#endif


#include <iostream>
#include <gtest\gtest.h>


#endif