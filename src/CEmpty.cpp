#include "CEmpty.hpp"
//=================================================================================================
ostream & CEmpty::Print_Cell_Line (ostream & os, const int & height, const int & width ,const int & height_max, bool right, bool top, bool HorMid, bool VertMid)
{
    if(width)
    os << setw(width) << ' ';
    return os;
}
//=================================================================================================

