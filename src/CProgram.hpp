#ifndef CPROGRAM_HPP
#define CPROGRAM_HPP
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cctype>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <memory>
#include <functional>
#include <stdexcept>
#include <fstream>
#include "CInterface.hpp"
#include "CTable.hpp"
//=================================================================================================
using namespace std;
/**
 * @brief The class represents a program
*/
class CProgram
{
public:
    /**
     * @brief Calls up the start menu and reacts depending on the user's choice
    */
    void Start ( void );
    /**
     * @brief Launches part of the program working with the table and responds to user commands
    */
    void Run ( void );
    
private:

    CInterface p_Menu;
    CTable     p_Table;
};
//=================================================================================================
#endif
