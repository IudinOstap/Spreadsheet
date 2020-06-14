#ifndef CDIGIT_HPP
#define CDIGIT_HPP
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
#include "CCell.hpp"
//=================================================================================================
using namespace std;
/**
 * @brief The abstract parent class that represents digit cell - CDigit
 */
class CDigit : public CCell
{
public:
    /**
     * @brief Constructor CCell: c_Content = "", d_Content = 0, PersonalConfig = false;
     */
    CDigit ( void ) : CCell () { Type = "digit";  }
    /**
     * @brief Constructor CCell: c_Content = "content", d_Content = stod ( contnent ), PersonalConfig = false;
     */
    CDigit ( const string & content );
    /**
     * @brief Constructor CCell: c_Content = to_string( content ) (without 0 at end), d_Content =  contnent , PersonalConfig = false;
     */
    CDigit ( const double & content );
    CDigit ( const CDigit & x);
    /**
     * @brief Abstract method that print one CDigitl line to the output stream
     * @param[in] ostream & Out - output stream
     * @param[in] const int & height - number of line for print
     * @param[in] const int & width - width of output line
     * @param[in] const int & height_max - height of this cell
     * @param[in] bool right - right align
     * @param[in] bool top - top align
     * @param[in] bool HorMid - horizontal center align
     * @param[in] bool VertMid - vertical center align
     * @return output stream with printed line
     */
    ostream & Print_Cell_Line ( ostream & Out,const int & height,const int & width,const int & height_max, bool right, bool top, bool HorMid, bool VertMid ) override;
    /**
     * @brief Abstract method that clone CDigit
     * @return pointer to copy of this CDigit
     */
    CDigit * Clone ( void ) const override { return new CDigit { *this }; }
    
};
//=================================================================================================

#endif
