#ifndef COPTIONS_HPP
#define COPTIONS_HPP
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
#include "CTable.hpp"
#include "CCell.hpp"
#include "CEmpty.hpp"
#include "CDigit.hpp"
#include "CText.hpp"
//=================================================================================================
using namespace std;
/**
 *@brief The class that represents  program interface - CInterface
 */
class CInterface
{
public:
    CInterface ( void );
    
    static const int ENG = 0;
    static const int CZE = 1;
    static const int RUS = 2;
   /**
    * @brief Show a start menu
    * @return char with user choise
    */
    char ShowMenu ( void );
    /**
     * @brief Show a settings menu
     * @return Char with user choise
     */
    char ShowSet  ( void );
    /**
     * @brief Show a lenguage settings menu
     * @return Char with user choise
     */
    char ShowLenguageSet ( void );
    /**
     * @brief Show a table name settings menu
     * @return String wiht table name
     */
    string SetTableName ( void );
    /**
     * @brief Show a table size settings menu
     * @param[in] int & height - Variable where will be written table height
     * @param[in] int & width - Variable where will be written table width
     */
    void SetTableSize ( int & height,int & width );
    /**
     * @brief Show a table horizontal aligin settings menu
     * @return Char wiht table name
     */
    char HorizontalAliginSet ( void );
    /**
     * @brief Show a table vertical aligin settings menu
     * @return Char wiht table name
     */
    char VerticalAliginSet ( void );
    /**
     * @brief Gives an error informing the user about an incorrect entry
     */
    void NotCorrectChoise ( void );
    /**
     * @brief Shows the work program interface
     * @return String with user command
     */
    string ProgramRunInterface ( CTable p_Table );
    /**
     * @brief Shows all program command
     */
    void ShwoInfo ( void );
    /**
     * @brief Show "SET TEXT" command interface and calls p_Table.SetText
     * @param[in] CTable & p_Table - The table in which the text will be written
     */
    void SetTextInterface ( CTable & p_Table );
    /**
     * @brief Show "SET DIGITS" command interface and calls p_Table.SetDigits, and show text minimum/ maximum value and digit minimum/ maximum value
     * @param[in] CTable & p_Table - The table in which the digits will be written
     */
    void SetDigitsInterface ( CTable & p_Table );
    /**
     * @brief Show "MIN" / "MAX" command interface and calls p_Table.FounMax / p_Table.FounMin
     * @param[in] CTable & p_Table - Table in which it will look for the minimum / maximum
     * @param[in] string wanted - wanted = "MAX"  if user want search maximum,  wanted = "MIN"  if user want search minimum,
     */
    void FoundMinMaxInterface ( CTable & p_Table, string wanted );
    /**
     * @brief Show "AVG" command interface and calls FounAvg, and show digit avarage value
     * @param[in] CTable & p_Table - Table in which it will look for the minimum / maximum
     */
    void FoundAvgInterface ( CTable & p_Table );
    /**
     * @brief Show "GEM" command interface and calls method for producing the desired geometric function, and show result (  "Not found" if  table have no digits in range )
     * @param[in] CTable & p_Table - Table in which it will look for the minimum / maximum
     */
    void GeometricFunctionsInterface ( CTable & p_Table );
    /**
     * @brief Show "TOLOWER" / "TOUPPER" command interface and calls  p_Table.ToLower / p_Table.ToUpper
     * @param[in] CTable & p_Table - Table which will be changed
     * @param[in] string wanted - wanted = "TOUPPER"  if user want use  toupper,  wanted = "TOLOWER"  if user want use tolower,
     */
    void ToLowUpInterface ( CTable & p_Table, string wanted );
    /**
     * @brief Show "CLEAR" command interface and calls p_Table.Clear
     * @param[in] CTable & p_Table - The table in which the cell will be clean
     */
    void ClearInterface ( CTable & p_Table );
    /**
     * @brief Show "ALIGN" command interface and calls p_Table.AlignChange
     * @param[in] CTable & p_Table - The table in which the cell will be change
     */
    void AliginChangeInterface ( CTable & p_Table );
    /**
     * @brief Show "PRINT TO FILE" command interface and calls p_Table.PrintToFile
     * @param[in] CTable & p_Table - The table in which the cell will be printed
     */
    void PrintToFileInterface ( CTable & p_Table );
    /**
     * @brief Show "SAVE" command interface and calls p_Table.SaveToFile
     * @param[in] CTable & p_Table - The table in which the cell will be saved
     */
    void SaveToFileInterface ( CTable & p_Table );
    /**
     * @brief Show "EXIT" command interface and will prompts the user to save the table
     * @param[in] CTable & p_Table - The table in which user can save
     * @return Char with user choise
     */
    char ExitInterface ( CTable & p_Table );
    /**
     * @brief Show "Open from file" choise interface and calls p_Table.OpenFromFile
     * @param[in] CTable & p_Table - The table in which  will be writted table from file
     * @return False if file have a problem or not txt file or not exist, True if open was successful
     */
    bool OpenFromFileInterface ( CTable & p_Table );



private:
    int m_Language; // 0 - ENG | 1 - CZE | 2 - RUS
    map <string, int> m_Commands;
    
};

#endif
