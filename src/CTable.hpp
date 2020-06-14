#ifndef CTABLE_HPP
#define CTABLE_HPP
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
#include <fstream>
#include <memory>
#include <functional>
#include <stdexcept>
#include "CCell.hpp"
#include "CEmpty.hpp"
#include "CDigit.hpp"
#include "CText.hpp"
//=================================================================================================
/**
 * @brief The class that represents table - CTable
*/
class CTable
{
public:
    /**
     * @brief Constructor make a empty table,
     */
    CTable ( void );
    /**
     * @brief Constructor make a  table  table of the given sizes with a empty cells,
     * @param[in] const int & Height -  table height
     * @param[in] const int & Width  -  table width
     */
    CTable ( const int & Height, const int & Width );
    /**
     * @brief Print table to output stream
     * @param[in] ostream & out - output stream
     */
    ostream & PrintTable ( ostream & out );
    /**
     * @brief Set a new content to the [Height ,Width] cell, return false if [Height,Width] is outside
     * @param[in] const int & Height -  cell height
     * @param[in] const int & Width  -  cell width
     * @param[in] const CCell & content - new content for cell
     */
    bool SetCell ( const int & Height, const int & Width ,const CCell & content );
    /**
     * @brief Returns the pointer to the cell, Returns the pointer to the [0,0] cell if [Height,Width] is outside the table
     * @param[in] const int & Height -  cell height
     * @param[in] const int & Width  -  cell width
     */
    CCell & GetCell ( const int & Height, const int & Width );
    
    bool t_Right;              // align to the right
    bool t_Top;                // align to the top
    bool t_HorMid;             // align to the horizontal centr
    bool t_VertMid;            // align to the vertical centr
    
    string TabelName;          
    int t_Width;
    int t_Height;
    map< pair <int,int>, shared_ptr<CCell> > t_Table;
    /**
     * @brief Sets text context to the given cell
     * @param[in] string & input - String with cell address
     * @param[in] bool & done - Done = true if the installation was successful , else done = false
     */
    void SetTextContnent ( string & input, bool & done);
    /**
     * @brief Sets text content ( which we get from other cells )  to the given cell
     * @param[in] string & input - String with cells addreses
     * @param[in] bool & done - Done = true if the installation was successful , else done = false
     */
    void SetTextCell ( string & input, bool & done);
    /**
     * @brief Determines how the user wants to set the  text content
     * @param[in] string & input - String with cell address
     * @param[in] bool & done - Done = true if the installation was successful , else done = false
     */
    void SetText ( string & input, bool & done );
    /**
     * @brief Sets digit content to the given cell
     * @param[in] string & input - String with cell address and with sign of operations
     * @param[in] bool & done - Done = true if the installation was successful , else done = false
     */
    void SetDigitsContnent ( string & input, bool & done );
    /**
     * @brief Writes the sum of two cells in the desired cell
     * @param[in] const char Cplace1 - row index for a target cell
     * @param[in] const int Iplace1 -  column index for a target cell
     * @param[in] const char Cplace2 - row index for a first cell component
     * @param[in] const int Iplace2 -  column index for a first cell component
     * @param[in] const char Cplace3 - row index for a second cell component
     * @param[in] const int Iplace3 - column index for a second cell component
     * @param[in] bool & done - Done = true if the installation was successful , else done = false
     *
     */
    void AddCellDigits ( const char Cplace1, const int Iplace1, const char Cplace2, const int Iplace2, const char Cplace3, const int Iplace3, bool & done);
    /**
     * @brief Writes the subtraction of two cells in the desired cell
     * @param[in] const char Cplace1 - row index for a target cell
     * @param[in] const int Iplace1 -  column index for a target cell
     * @param[in] const char Cplace2 - row index for a first cell component
     * @param[in] const int Iplace2 -  column index for a first cell component
     * @param[in] const char Cplace3 - row index for a second cell component
     * @param[in] const int Iplace3 - column index for a second cell component
     * @param[in] bool & done - Done = true if the installation was successful , else done = false
     *
     */
    void SubCellDigits ( const char Cplace1, const int Iplace1, const char Cplace2, const int Iplace2, const char Cplace3, const int Iplace3, bool & done);
    /**
     * @brief Writes the multiplication of two cells in the desired cell
     * @param[in] const char Cplace1 - row index for a target cell
     * @param[in] const int Iplace1 -  column index for a target cell
     * @param[in] const char Cplace2 - row index for a first cell component
     * @param[in] const int Iplace2 -  column index for a first cell component
     * @param[in] const char Cplace3 - row index for a second cell component
     * @param[in] const int Iplace3 - column index for a second cell component
     * @param[in] bool & done - Done = true if the installation was successful , else done = false
     */

    void MulCellDigits ( const char Cplace1, const int Iplace1, const char Cplace2, const int Iplace2, const char Cplace3, const int Iplace3, bool & done);
    /**
     * @brief Writes the division of two cells in the desired cell
     * @param[in] const char Cplace1 - row index for a target cell
     * @param[in] const int Iplace1 -  column index for a target cell
     * @param[in] const char Cplace2 - row index for a first cell component
     * @param[in] const int Iplace2 -  column index for a first cell component
     * @param[in] const char Cplace3 - row index for a second cell component
     * @param[in] const int Iplace3 - column index for a second cell component
     * @param[in] bool & done - Done = true if the installation was successful , else done = false
     *
     */
    void DivCellDigits ( const char Cplace1, const int Iplace1, const char Cplace2, const int Iplace2, const char Cplace3, const int Iplace3, bool & done);
    /**
     * @brief sets digit content ( which we get from other cells )  to the given cell
     * @param[in] string & input - string with cells addreses
     * @param[in] bool & done - done = true if the installation was successful , else done = false
     */
    void SetDigitsCell ( string & input, bool & done);
    /**
     * @brief Determines how the user wants to set the digit content
     * @param[in] string & input - String with cell address
     * @param[in] bool & done - Done = true if the installation was successful , else done = false
     */
    void SetDigits ( string & input, bool & done  );
    /**
     * @brief Searches for the maximum text and numeric value in a given range
     * @param[in] bool & done - done - true if the search was successful , else done = false
     * @param[in] bool & back - back - true if user set "back" , else done = false
     * @param[in] double & MaxDigit - variable where the maximum numerical value will be set
     * @param[in] string & MaxText - variable where the maximum text value will be set
     * @param[in] bool & DoneText - DoneText = true if in range was text, else false
     * @param[in] bool & DoneDigit - DoneDigit = true if in range was digit, else false
     */
    void FoundMax ( bool & done, bool & back , double & MaxDigit , string & MaxText, bool & DoneText, bool & DoneDigit);
    /**
     * @brief Searches for the minimum text and numeric value in a given range
     * @param[in] bool & done - done - true if the search was successful , else done = false
     * @param[in] bool & back - back - true if user set "back" , else done = false
     * @param[in] double & MinDigit - variable where the minimum numerical value will be set
     * @param[in] string & MinText - variable where the minimum text value will be set
     * @param[in] bool & DoneText - DoneText = true if in range was text, else false
     * @param[in] bool & DoneDigit - DoneDigit = true if in range was digit, else false
     */
    void FoundMin ( bool & done, bool & back, double & MinDigit , string & MinText , bool & DoneText, bool & DoneDigit);
    /**
     * @brief Searches for the average numeric value in a given range
     * @param[in] bool & done - done - true if the search was successful , else done = false
     * @param[in] bool & back - back - true if user set "back" , else done = false
     * @param[in] double & AvgDigit - variable where the average numerical value will be set
     * @param[in] bool & DoneDigit - DoneDigit = true if in range was digit, else false
    */
    void FoundAvg ( bool & done, bool & back , double & AvgDigit, bool & DoneDigit);
    /**
     * @brief Function to  geometric functions
     * @param[in] bool & done - done - true if the computation was successful , else done = false
     * @param[in] string & input - String with cells address
     * @param[in] double & AvgDigit - variable where the average numerical value will be set
     * @param[in] bool & DoneDigit - DoneDigit = true if in range was digit, else false
    */
    double GeometricFunctions ( string & input, bool & done, bool & DoneDigit);
    /**
     * @brief to do tolower on  a given cell
     * @param[in] string & input - String with cells address
     * @param[in] bool & done - done - true if the computation was successful , else done = false
     * @return value of calculation
    */
    void ToLower ( string & input, bool & done );
    /**
     * @brief to do toupper on  a given cell
     * @param[in] string & input - String with cells address
     * @param[in] bool & done - done - true if the computation was successful , else done = false
    */
    void ToUpper ( string & input, bool & done );
    /**
     * @brief cleans the cell
     * @param[in] string & input - String with cells address
     * @param[in] bool & done - done - true if the computation was successful , else done = false
    */
    void Clear ( string & input, bool & done );
    /**
     * @brief changes cell align
     * @param[in] string & input - String with cells address
     * @param[in] bool & done - done - true if the computation was successful , else done = false
    */
    void AlignChange ( string & input, bool & done );
    /**
     * @brief Print table to file
     * @param[in] string & input - String with a file address
     * @param[in] bool & done - done - true if the print was successful , else done = false
     */
    void PrintToFile ( string & input, bool & done );
    /**
     * @brief Save table to file
     * @param[in] string & input - String with a file address
     * @param[in] bool & done - done - true if the print was successful , else done = false
     */
    void SaveToFile ( string & input, bool & done );
    /**
     * @brief Open table from file
     * @param[in] string & input - String with a file address
     * @return true if open and reading was successful , else done = false
     */
    bool OpenFromFile ( string & input );

};

//=================================================================================================
#endif
