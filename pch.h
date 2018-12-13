#ifndef PCH_H
#define PCH_H
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using string = std::string;
// LOG
#if 1
#define LOG(x) std::cout<<"\n"<<x<<"\n";
#else
#define LOG(x);
#endif // LOG




#endif // !PCH_H
