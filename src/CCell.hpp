#ifndef CCell_HPP
#define CCell_HPP
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
//=================================================================================================
using namespace std;
/**
 * @brief The abstract parent class that represents cell - CCell
 */
class CCell
{
public:
    /**
     * @brief Constructor CCell: c_Content = "", d_Content = 0, PersonalConfig = false;
     */
    CCell ( void );
    virtual ~CCell () = default;
    CCell ( const string & content );
    /**
     * @brief Abstract method that print one CCell line to the output stream
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
    virtual ostream & Print_Cell_Line ( ostream & Out,const int & height,const int & width,const int & height_max, bool right, bool top, bool HorMid, bool VertMid) = 0;
    /**
     * @brief Abstract method that clone CCell
     *  @return pointer to copy of this CCell
     */
    virtual CCell * Clone ( void ) const = 0;
  //  virtual void SetText ( const string & new_cont ) = 0;

    int c_Width;
    int c_Height;
    int LineInd,CharInd;
    int c_Empty;               // count empty string, we need this when we have centr align
    string c_Content;          // contnent of cell in string
    double d_Content;          // content of cel in double ( 0 for CText and CEmpty )
    
    string Type;               // type of cell
    
    bool c_Right;              // align to the right
    bool c_Top;                // align to the top
    bool c_HorMid;             // align to the horizontal centr
    bool c_VertMid;            // align to the vertical centr
    bool PersonalConfig;       // did the user set alignment for this cell
    
};

//=================================================================================================
#endif
