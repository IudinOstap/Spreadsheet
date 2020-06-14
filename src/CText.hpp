#ifndef CTEXT_HPP
#define CTEXT_HPP
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
 * @brief The abstract parent class that represents text cell - CText
 */
class CText : public CCell
{
public:
    /**
     * @brief Constructor CText: c_Content = "", d_Content = 0, PersonalConfig = false;
     */
    CText ( void ) : CCell () { Type = "text"; }
    CText ( const CText & x );
    /**
     * @brief Constructor CText:  c_Content = "content", d_Content = 0, PersonalConfig = false;
     */
    CText ( const string & content);
    /**
     * @brief Method that print one CText line to the output stream
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
    ostream & Print_Cell_Line ( ostream & out,const int & height,const int & width,const int & height_max,  bool right, bool top, bool HorMid, bool VertMid) override;
    /**
     * @brief Method that clone CText
     * @return Pointer to copy of this CText
     */
    CText * Clone ( void ) const override { return new CText { *this }; }
        
};
//=================================================================================================
#endif
