#include "CCell.hpp"
CCell::CCell ( void )
{
    c_Width = c_Height = LineInd = CharInd = d_Content = 0;
    c_Right = false; c_Top = false; c_HorMid = false; c_VertMid = false; PersonalConfig = false;
    c_Content = "";
}
//--------------------------------------------------------------------------------------------------
CCell::CCell ( const string & content ) : c_Content ( content )
{
    c_Width = c_Height = LineInd = CharInd = 0;
    c_Right = false; c_Top = false; c_HorMid = false; c_VertMid = false; PersonalConfig = false;
}
