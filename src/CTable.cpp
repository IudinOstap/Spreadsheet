#include "CTable.hpp"
//=================================================================================================
CTable::CTable ( void )
{
    t_Right = false; t_Top = false; t_HorMid = false; t_VertMid = false;
    t_Width = t_Height = 0;
}
//--------------------------------------------------------------------------------------------------
CCell & CTable::GetCell ( const int & Height, const int & Width )
{
    int h,w;
    if ( Height > t_Height || Height < 0 || Width > t_Width || Width < 0 )
    {
        h = w = 0;
    } else { h = Height; w = Width; }

    
    if ( !t_Table [ make_pair(h, w)] ) SetCell( Height, Width, CEmpty ( ) );
    return * t_Table [ make_pair(h, w)];
}
//--------------------------------------------------------------------------------------------------
CTable::CTable ( const int & Height, const int & Width )
{
    t_Width = Width; t_Height = Height;
}
//--------------------------------------------------------------------------------------------------
bool CTable::SetCell ( const int & Height, const int & Width ,const CCell & content )
{
    if ( Height > t_Height || Height < 0 || Width > t_Width || Width < 0 )
        return false;
    
    t_Table [ make_pair (Height,Width) ] = shared_ptr<CCell>(content.Clone());
    
    return true;
}
//--------------------------------------------------------------------------------------------------
ostream & CTable::PrintTable ( ostream & out )
{
    int w = 0, h = 0;
    
    vector<int> width;   // array whith width for evry coloumn
    vector<int> height;  // array whith height for evry row
    
    CEmpty tmp;
    string ind = "";
    t_Table [ make_pair (-1,-1) ] = shared_ptr<CCell>(tmp.Clone());
    
    for ( int i = 0 ; i < t_Height ; i++ )
    {
        ind += ('A' + i);
        CText index ( ind );
        index.PersonalConfig = true;
        index.c_VertMid = true;
        index.c_HorMid = true;
        t_Table [ make_pair (i, -1) ] = shared_ptr<CCell>(index.Clone());
        ind = "";
    }
    
    for ( int i = 0 ; i < t_Width ; i++ )
    {
        CDigit index ( i );
        index.PersonalConfig = true;
        index.c_VertMid = true;
        index.c_HorMid = true;
        t_Table [ make_pair (-1,i) ] = shared_ptr<CCell>(index.Clone());
    }
    
    bool done = false;
    
    for( int z = -1; z < t_Height; z++ ) //iterates over the whole table and considers the necessary sizes for cells
    {
        for( int i = -1; i < t_Width; i++ )
        {
            if( t_Table [ make_pair(z,i) ] )
            {
                h = t_Table [ make_pair(z,i) ] -> c_Height > h ? t_Table [ make_pair(z,i) ] -> c_Height : h;
                t_Table [ make_pair(z,i) ] -> CharInd = 0;
                t_Table [ make_pair(z,i) ] -> LineInd = 0;
                t_Table [ make_pair(z,i) ] -> c_Empty = 0;
            }
            
            if( !done )
            {
                for ( int t = -1 ; t < t_Height; t++ )
                    if ( t_Table [ make_pair (t,i) ] )
                        w = t_Table [ make_pair (t,i) ] -> c_Width > w ? t_Table [ make_pair ( t,i ) ] -> c_Width : w;
                width.push_back( w );
                w = 0;
            }
        }
        done = true;
        height.push_back( h );
        h = 0;
    }
    
    for ( int i = -1 ; i < ((int)height.size() - 1) ; i++ )
    {
        out << '+';
        for ( int z = 0 ; z < (int)width.size() ; z++ )
        {
            for ( int t = 0 ; t < width[z] ; t++ )
                out << '-';
            out << '+';
        }
        out << endl;
        
        for ( int o = 0 ; o < (int)height[i + 1] ; o++ )
        {
            for ( int z = -1 ; z < ((int)width.size() - 1) ; z++ )
            {
                out << '|';
                if ( !t_Table [ make_pair (i,z) ] ) SetCell ( i , z, CEmpty() );
                    t_Table [ make_pair (i,z) ] -> Print_Cell_Line ( out, o, width[z + 1], height[i + 1], t_Right, t_Top , t_HorMid, t_VertMid ) ;
            }
            out << '|';
            out << endl;
        }
    }
    
    out << '+';
    for( int z = 0 ; z < (int) width.size() ; z++ )
    {
        for ( int p = 0 ; p < width[z] ; p++ )
            out << '-';
        out << '+';
    }
    
    out << endl;
    
    return out;
    
}
//--------------------------------------------------------------------------------------------------
void CTable::SetTextContnent ( string & input , bool & done)
{
    string content = "" ;
    char Cplace1;
    int Iplace1;
    Iplace1 = input[1] - '0'; Cplace1 = input[0];
    while(1)
    {
        input.clear();
        getline ( cin, input );
        if ( input.length() == 0 )
        {
            if( !content.empty() )
                content.pop_back();
            break;
        }
        else
        {
            content += input;
            content += '\n';
        }
    }
    if( content.length() != 0 )
    {
        CText tmp ( content );
        if (t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)] &&
            t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->PersonalConfig) {
            tmp.PersonalConfig = true;
            tmp.c_Right = t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_Right;
            tmp.c_Top = t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_Top;
            tmp.c_HorMid = t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_HorMid;
            tmp.c_VertMid = t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_VertMid;
        }

        t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)] = shared_ptr<CCell>(tmp.Clone());
    } else
    {
        CEmpty tmp;
        if (t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)] &&
            t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->PersonalConfig) {
            tmp.PersonalConfig = true;
            tmp.c_Right = t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_Right;
            tmp.c_Top = t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_Top;
            tmp.c_HorMid = t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_HorMid;
            tmp.c_VertMid = t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_VertMid;
        }

        t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)] = shared_ptr<CCell>(tmp.Clone());

    }
    done = true;
}
//--------------------------------------------------------------------------------------------------
void CTable::SetTextCell ( string & input , bool & done)
{
    string content = "" ;
    char Cplace1;
    int Iplace1;
    char Cplace2;
    int Iplace2;
    char Cplace3;
    int Iplace3;
    char sign;

    Iplace1 = input[1] - '0'; Cplace1 = input[0];

    getline ( cin , input );
    for_each(input.begin(), input.end(), [](char & c)   {c = ::toupper(c);});
    const char * tmp = input.c_str ( );
    if ( sscanf( tmp , " %c%d %c %c%d", &Cplace2, &Iplace2, &sign, &Cplace3, &Iplace3 ) == 5
         && ( sign == '+' )
         && (Iplace2 < t_Width || (int)(Cplace2 - 'A') < t_Height || Iplace2 >= 0 || (int)(Cplace2 - 'A') >= 0)
         && (Iplace3 < t_Width || (int)(Cplace1 - 'A') < t_Height || Iplace3 >= 0 || (int)(Cplace3 - 'A') >= 0) )
    {
        if ( t_Table[ make_pair ((int)(Cplace2 - 'A'), Iplace2)] )
            content += t_Table[ make_pair ((int)(Cplace2 - 'A'), Iplace2)] -> c_Content;
        if( t_Table[ make_pair ((int)(Cplace3 - 'A'), Iplace3)] )
            content += t_Table[ make_pair ((int)(Cplace3 - 'A'), Iplace3)] -> c_Content;
        CText tmp ( content );

        if ( t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] && t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] -> PersonalConfig )
        {
            tmp.PersonalConfig = true;
            tmp.c_Right = t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] -> c_Right;
            tmp.c_Top = t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] -> c_Top;
            tmp.c_HorMid = t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] -> c_HorMid;
            tmp.c_VertMid = t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] -> c_VertMid;
        }

        t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] = shared_ptr<CCell>(tmp.Clone());
        done = true;
        return;
    }
    if ( ( sscanf( tmp , " %c%d", &Cplace2, &Iplace2 ) == 2
           && (Iplace2 < t_Width || (int)(Cplace2 - 'A') < t_Height || Iplace2 >= 0 || (int)(Cplace2 - 'A') >= 0) ) )
    {
        if ( t_Table[ make_pair ((int)(Cplace2 - 'A'), Iplace2)] )
            content += t_Table[ make_pair ((int)(Cplace2 - 'A'), Iplace2)] -> c_Content;
        CText tmp ( content );

        if ( t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] && t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] -> PersonalConfig )
        {
            tmp.PersonalConfig = true;
            tmp.c_Right = t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] -> c_Right;
            tmp.c_Top = t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] -> c_Top;
            tmp.c_HorMid = t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] -> c_HorMid;
            tmp.c_VertMid = t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] -> c_VertMid;
        }

        t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] = shared_ptr<CCell>(tmp.Clone());
        done = true;
    }


}
//--------------------------------------------------------------------------------------------------
void CTable::SetText ( string & input, bool & done )
{
    string content = "" ;
    char Cplace1;
    int Iplace1;
    if ( input.length() == 3 && (isupper (input[0]) && isdigit (input[1])) )
    {
        Iplace1 = input[1] - '0'; Cplace1 = input[0];
        if (!( Iplace1 >= t_Width || (int)(Cplace1 - 'A') >= t_Height || Iplace1 < 0 || (int)(Cplace1 - 'A') < 0 ) )
        {
            if ( input[2] == ':' )
                SetTextContnent ( input, done );

            if ( input[2] == '=' )
                SetTextCell ( input, done);
        }
    }
}
//--------------------------------------------------------------------------------------------------
void CTable::SetDigitsContnent ( string & input , bool & done )
{
    char Cplace1;
    int Iplace1;
    Iplace1 = input[1] - '0'; Cplace1 = input[0];
    double content;
    if( cin >> content )
    {
        CDigit tmp ( content );
        if ( t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] && t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] -> PersonalConfig )
        {
            tmp.PersonalConfig = true;
            tmp.c_Right = t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] -> c_Right;
            tmp.c_Top = t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] -> c_Top;
            tmp.c_HorMid = t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] -> c_HorMid;
            tmp.c_VertMid = t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] -> c_VertMid;
        }
        t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] = shared_ptr<CCell>(tmp.Clone());
        done = true;
    }
}
//--------------------------------------------------------------------------------------------------
void CTable::AddCellDigits ( const char Cplace1, const int Iplace1, const char Cplace2, const int Iplace2, const char Cplace3, const int Iplace3, bool & done)
{
    double content1 = 0;
    double content2 = 0;

    if ( t_Table[ make_pair ((int)(Cplace2 - 'A'), Iplace2)] )
        content1 = t_Table[ make_pair ((int)(Cplace2 - 'A'), Iplace2)] -> d_Content;
    if( t_Table[ make_pair ((int)(Cplace3 - 'A'), Iplace3)] )
        content2 = t_Table[ make_pair ((int)(Cplace3 - 'A'), Iplace3)] -> d_Content;

    if( t_Table[ make_pair ((int)(Cplace2 - 'A'), Iplace2)] -> Type != "digit"
        ||  t_Table[ make_pair ((int)(Cplace2 - 'A'), Iplace2)] -> Type != "digit")
    {
        done = false;
        return;
    }


    content1 += content2;
    CDigit tmp ( content1 );

    t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] = shared_ptr<CCell>(tmp.Clone());
    done = true;
}
//--------------------------------------------------------------------------------------------------
void CTable::SubCellDigits ( const char Cplace1, const int Iplace1, const char Cplace2, const int Iplace2, const char Cplace3, const int Iplace3, bool & done)
{
    double content1 = 0;
    double content2 = 0;
    if ( t_Table[ make_pair ((int)(Cplace2 - 'A'), Iplace2)] )
        content1 = t_Table[ make_pair ((int)(Cplace2 - 'A'), Iplace2)] -> d_Content;
    if( t_Table[ make_pair ((int)(Cplace3 - 'A'), Iplace3)] )
        content2 = t_Table[ make_pair ((int)(Cplace3 - 'A'), Iplace3)] -> d_Content;

    if( t_Table[ make_pair ((int)(Cplace2 - 'A'), Iplace2)] -> Type != "digit"
        ||  t_Table[ make_pair ((int)(Cplace2 - 'A'), Iplace2)] -> Type != "digit")
    {
        done = false;
        return;
    }

    content1 -= content2;
    CDigit tmp ( content1 );

    t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] = shared_ptr<CCell>(tmp.Clone());
    done = true;
}
//--------------------------------------------------------------------------------------------------
void CTable::MulCellDigits ( const char Cplace1, const int Iplace1, const char Cplace2, const int Iplace2, const char Cplace3, const int Iplace3, bool & done)
{
    double content1 = 0;
    double content2 = 0;
    if ( t_Table[ make_pair ((int)(Cplace2 - 'A'), Iplace2)] )
        content1 = t_Table[ make_pair ((int)(Cplace2 - 'A'), Iplace2)] -> d_Content;
    if( t_Table[ make_pair ((int)(Cplace3 - 'A'), Iplace3)] )
        content2 = t_Table[ make_pair ((int)(Cplace3 - 'A'), Iplace3)] -> d_Content;

    if( t_Table[ make_pair ((int)(Cplace2 - 'A'), Iplace2)] -> Type != "digit"
        ||  t_Table[ make_pair ((int)(Cplace2 - 'A'), Iplace2)] -> Type != "digit")
    {
        done = false;
        return;
    }

    content1 *= content2;
    CDigit tmp ( content1 );

    t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] = shared_ptr<CCell>(tmp.Clone());
    done = true;
}
//--------------------------------------------------------------------------------------------------
void CTable::DivCellDigits ( const char Cplace1, const int Iplace1, const char Cplace2, const int Iplace2, const char Cplace3, const int Iplace3, bool & done)
{
    double content1 = 0;
    double content2 = 0;
    if ( t_Table[ make_pair ((int)(Cplace2 - 'A'), Iplace2)] )
        content1 = t_Table[ make_pair ((int)(Cplace2 - 'A'), Iplace2)] -> d_Content;
    if( t_Table[ make_pair ((int)(Cplace3 - 'A'), Iplace3)] )
        content2 = t_Table[ make_pair ((int)(Cplace3 - 'A'), Iplace3)] -> d_Content;

    if( t_Table[ make_pair ((int)(Cplace2 - 'A'), Iplace2)] -> Type != "digit"
        ||  t_Table[ make_pair ((int)(Cplace2 - 'A'), Iplace2)] -> Type != "digit")
    {
        done = false;
        return;
    }

    content1 /= content2;
    CDigit tmp ( content1 );

    t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] = shared_ptr<CCell>(tmp.Clone());

    done = true;
}
//--------------------------------------------------------------------------------------------------
void CTable::SetDigitsCell ( string & input , bool & done)
{
    double content1 = 0;
    char Cplace1;
    int Iplace1;
    char Cplace2;
    int Iplace2;
    char Cplace3;
    int Iplace3;
    char sign;
    Iplace1 = input[1] - '0'; Cplace1 = input[0];
    

    getline ( cin , input );
    for_each(input.begin(), input.end(), [](char & c)   {c = ::toupper(c);});
    const char * tmp = input.c_str ( );
    if ( sscanf( tmp , " %c%d %c %c%d", &Cplace2, &Iplace2, &sign, &Cplace3, &Iplace3 ) == 5
         && (Iplace2 < t_Width || (int)(Cplace2 - 'A') < t_Height || Iplace2 >= 0 || (int)(Cplace2 - 'A') >= 0)
         && (Iplace3 < t_Width || (int)(Cplace1 - 'A') < t_Height || Iplace3 >= 0 || (int)(Cplace3 - 'A') >= 0) )
    {
        if ( sign == '+' )
            AddCellDigits ( Cplace1, Iplace1, Cplace2, Iplace2, Cplace3, Iplace3, done );
        if ( sign == '-' )
            SubCellDigits ( Cplace1, Iplace1, Cplace2, Iplace2, Cplace3, Iplace3, done );
        if ( sign == '*' )
            MulCellDigits ( Cplace1, Iplace1, Cplace2, Iplace2, Cplace3, Iplace3, done );
        if ( sign == '/' )
            DivCellDigits (  Cplace1, Iplace1, Cplace2, Iplace2, Cplace3, Iplace3, done);

        return;
    }

    if ( ( sscanf( tmp , " %c%d", &Cplace2, &Iplace2 ) == 2
           && (Iplace2 < t_Width || (int)(Cplace2 - 'A') < t_Height || Iplace2 >= 0 || (int)(Cplace2 - 'A') >= 0) ) )
    {

        if ( t_Table[ make_pair ((int)(Cplace2 - 'A'), Iplace2)] )
            content1 = t_Table[ make_pair ((int)(Cplace2 - 'A'), Iplace2)] -> d_Content;

        if( t_Table[ make_pair ((int)(Cplace2 - 'A'), Iplace2)] -> Type != "digit")
        {
            done = false;
            return;
        }


        CDigit tmp ( content1 );

        if ( t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] && t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] -> PersonalConfig )
        {
            tmp.PersonalConfig = true;
            tmp.c_Right = t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] -> c_Right;
            tmp.c_Top = t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] -> c_Top;
            tmp.c_HorMid = t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] -> c_HorMid;
            tmp.c_VertMid = t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] -> c_VertMid;
        }

        t_Table[ make_pair ((int)(Cplace1 - 'A'), Iplace1) ] = shared_ptr<CCell>(tmp.Clone());
        done = true;
    }
}
//--------------------------------------------------------------------------------------------------
void CTable::SetDigits ( string & input, bool & done  )
{
    string content = "" ;
    char Cplace1;
    int Iplace1;
    if ( input.length() == 3 && (isupper (input[0]) && isdigit (input[1])) )
    {
        Iplace1 = input[1] - '0'; Cplace1 = input[0];
        if (!( Iplace1 >= t_Width || (int)(Cplace1 - 'A') >= t_Height || Iplace1 < 0 || (int)(Cplace1 - 'A') < 0 ) )
        {
            if ( input[2] == ':' )
            {
                SetDigitsContnent(input, done);
                return;
            }

            if ( input[2] == '=' )
                SetDigitsCell ( input , done);
        }
    }
}
//--------------------------------------------------------------------------------------------------
void CTable::FoundMax ( bool & done, bool & back , double & MaxDigit , string & MaxText, bool & DoneText, bool & DoneDigit)
{
    char Cplace1;
    int Iplace1;
    char Cplace2;
    int Iplace2;

    int MinHeight, MaxHeight;
    int MinWidth, MaxWidth;

    DoneText = false;
    DoneDigit = false;

    char sign;
    string input;


    cin.clear();
    fflush(stdin);
    getline ( cin, input);
    for_each(input.begin(), input.end(), [](char & c)   {c = ::toupper(c);});

    if ( input == "BACK" ) { done = true; back = true; return; }
    const char * tmp = input.c_str ( );

    if ( sscanf( tmp , " %c%d %c %c%d", &Cplace1, &Iplace1, &sign, &Cplace2, &Iplace2 ) == 5
         && ( sign == '-' )
         && (Iplace1 < t_Width || (int)(Cplace1 - 'A') < t_Height || Iplace1 >= 0 || (int)(Cplace1 - 'A') >= 0)
         && (Iplace2 < t_Width || (int)(Cplace2 - 'A') < t_Height || Iplace2 >= 0 || (int)(Cplace2 - 'A') >= 0) )
    {
        MinHeight = (int)(Cplace1 - 'A') > (int)(Cplace2 - 'A') ? (int)(Cplace2 - 'A') : (int)(Cplace1 - 'A');
        MaxHeight = (int)(Cplace1 - 'A') > (int)(Cplace2 - 'A') ? (int)(Cplace1 - 'A') : (int)(Cplace2 - 'A');
        MinWidth = Iplace1 > Iplace2 ? Iplace2 : Iplace1;
        MaxWidth = Iplace1 > Iplace2 ? Iplace1 : Iplace2;

        for( int z = MinHeight ; z <= MaxHeight ; z++ )
        {
            for( int i = MinWidth ; i <= MaxWidth ; i++ )
            {
                if( t_Table [ make_pair(z,i) ] )
                {
                    if (t_Table[make_pair(z, i)] -> Type == "text" )
                    {
                        if(!DoneText)
                        {
                            MaxText = t_Table[make_pair(z, i)] -> c_Content;
                            DoneText = true;
                        } else
                        {
                            MaxText = t_Table[make_pair(z, i)] -> c_Content > MaxText ? t_Table[make_pair(z, i)] -> c_Content : MaxText;
                        }

                    }
                    if (t_Table[make_pair(z, i)] -> Type == "digit" )
                    {
                        if(!DoneDigit)
                        {
                            MaxDigit = t_Table[make_pair(z, i)] -> d_Content;
                            DoneDigit = true;
                        } else
                        {
                            MaxDigit = t_Table[make_pair(z, i)] -> d_Content > MaxDigit ? t_Table[make_pair(z, i)] -> d_Content : MaxDigit;
                        }

                    }
                }

            }

        }
        done = true;
    }

}
//--------------------------------------------------------------------------------------------------
void CTable::FoundMin ( bool & done, bool & back, double & MinDigit , string & MinText , bool & DoneText, bool & DoneDigit)
{
    char Cplace1;
    int Iplace1;
    char Cplace2;
    int Iplace2;

    int MinHeight, MaxHeight;
    int MinWidth, MaxWidth;

    DoneText = false;
    DoneDigit = false;

    char sign;
    string input;


    cin.clear();
    fflush(stdin);
    getline ( cin, input);
    for_each(input.begin(), input.end(), [](char & c)   {c = ::toupper(c);});

    if ( input == "BACK" ) { done = true; back = true; return; }
    const char * tmp = input.c_str ( );

    if ( sscanf( tmp , " %c%d %c %c%d", &Cplace1, &Iplace1, &sign, &Cplace2, &Iplace2 ) == 5
         && ( sign == '-' )
         && (Iplace1 < t_Width || (int)(Cplace1 - 'A') < t_Height || Iplace1 >= 0 || (int)(Cplace1 - 'A') >= 0)
         && (Iplace2 < t_Width || (int)(Cplace2 - 'A') < t_Height || Iplace2 >= 0 || (int)(Cplace2 - 'A') >= 0) )
    {
        MinHeight = (int)(Cplace1 - 'A') > (int)(Cplace2 - 'A') ? (int)(Cplace2 - 'A') : (int)(Cplace1 - 'A');
        MaxHeight = (int)(Cplace1 - 'A') > (int)(Cplace2 - 'A') ? (int)(Cplace1 - 'A') : (int)(Cplace2 - 'A');
        MinWidth = Iplace1 > Iplace2 ? Iplace2 : Iplace1;
        MaxWidth = Iplace1 > Iplace2 ? Iplace1 : Iplace2;

        for( int z = MinHeight ; z <= MaxHeight ; z++ )
        {
            for( int i = MinWidth ; i <= MaxWidth ; i++ )
            {
                if( t_Table [ make_pair(z,i) ] )
                {
                    if (t_Table[make_pair(z, i)] -> Type == "text" )
                    {
                        if(!DoneText)
                        {
                            MinText = t_Table[make_pair(z, i)] -> c_Content;
                            DoneText = true;
                        } else
                        {
                            MinText = t_Table[make_pair(z, i)] -> c_Content < MinText ? t_Table[make_pair(z, i)] -> c_Content : MinText;
                        }

                    }
                    if (t_Table[make_pair(z, i)] -> Type == "digit" )
                    {
                        if(!DoneDigit)
                        {
                            MinDigit = t_Table[make_pair(z, i)] -> d_Content;
                            DoneDigit = true;
                        } else
                        {
                            MinDigit = t_Table[make_pair(z, i)] -> d_Content < MinDigit ? t_Table[make_pair(z, i)] -> d_Content : MinDigit;
                        }

                    }
                }

            }

        }
        done = true;
    }

}
//--------------------------------------------------------------------------------------------------
void CTable::FoundAvg ( bool & done, bool & back , double & AvgDigit, bool & DoneDigit)
{
    char Cplace1;
    int Iplace1;
    char Cplace2;
    int Iplace2;

    int MinHeight, MaxHeight;
    int MinWidth, MaxWidth;

    DoneDigit = false;

    int count = 0;
    double sum = 0;
    char sign;
    string input;


    cin.clear();
    fflush(stdin);
    getline ( cin, input);
    for_each(input.begin(), input.end(), [](char & c)   {c = ::toupper(c);});

    if ( input == "BACK" ) { done = true; back = true; return; }
    const char * tmp = input.c_str ( );

    if ( sscanf( tmp , " %c%d %c %c%d", &Cplace1, &Iplace1, &sign, &Cplace2, &Iplace2 ) == 5
         && ( sign == '-' )
         && (Iplace1 < t_Width || (int)(Cplace1 - 'A') < t_Height || Iplace1 >= 0 || (int)(Cplace1 - 'A') >= 0)
         && (Iplace2 < t_Width || (int)(Cplace2 - 'A') < t_Height || Iplace2 >= 0 || (int)(Cplace2 - 'A') >= 0) )
    {
        MinHeight = (int)(Cplace1 - 'A') > (int)(Cplace2 - 'A') ? (int)(Cplace2 - 'A') : (int)(Cplace1 - 'A');
        MaxHeight = (int)(Cplace1 - 'A') > (int)(Cplace2 - 'A') ? (int)(Cplace1 - 'A') : (int)(Cplace2 - 'A');
        MinWidth = Iplace1 > Iplace2 ? Iplace2 : Iplace1;
        MaxWidth = Iplace1 > Iplace2 ? Iplace1 : Iplace2;

        for( int z = MinHeight ; z <= MaxHeight ; z++ )
        {
            for( int i = MinWidth ; i <= MaxWidth ; i++ )
            {
                if( t_Table [ make_pair(z,i) ] )
                {

                    if (t_Table[make_pair(z, i)] -> Type == "digit" )
                    {
                        DoneDigit = true;
                        sum += t_Table[make_pair(z, i)] -> d_Content;
                        count ++;

                    }
                }

            }

        }
        done = true;
    }

    AvgDigit = sum / count ;

}
//--------------------------------------------------------------------------------------------------
double CTable::GeometricFunctions ( string & input, bool & done, bool & DoneDigit)
{
    char Cplace1;
    int Iplace1;

    char f1,f2,f3;
    string function = "";
    char del1,del2;

    const char * tmp = input.c_str ( );
    if ( sscanf( tmp , " %c%c%c%c%c%d%c ", &f1, &f2, &f3, &del1, &Cplace1, &Iplace1, &del2 ) == 7
         && del1 == '(' && del2 == ')'
         && !( Iplace1 >= t_Width || (int)(Cplace1 - 'A') >= t_Height || Iplace1 < 0 || (int)(Cplace1 - 'A') < 0 ) )
    {
        if ( !(t_Table [ make_pair ((int)(Cplace1 - 'A'),Iplace1 ) ] -> Type == "digit")  )
        {
            DoneDigit = false;
            done = true;
            return 0;
        }

        DoneDigit = true;
        function += toupper(f1);
        function += toupper(f2);
        function += toupper(f3);
        if ( function == "SIN" ) { done = true; return sin ( t_Table [ make_pair ((int)(Cplace1 - 'A'),Iplace1 ) ] -> d_Content); }
        if ( function == "COS" ) { done = true; return cos ( t_Table [ make_pair ((int)(Cplace1 - 'A'),Iplace1 ) ] -> d_Content); }
        if ( function == "TAN" ) { done = true; return tan ( t_Table [ make_pair ((int)(Cplace1 - 'A'),Iplace1 ) ] -> d_Content); }
        if ( function == "ACS" )
        {
            done = true;
            if ( (t_Table [ make_pair ((int)(Cplace1 - 'A'),Iplace1 ) ] -> d_Content) > 1 ||  (t_Table [ make_pair ((int)(Cplace1 - 'A'),Iplace1 ) ] -> d_Content) < -1)
            {
                DoneDigit = false;
                return 0;
            }
            return acos ( t_Table [ make_pair ((int)(Cplace1 - 'A'),Iplace1 ) ] -> d_Content);
        }
        if ( function == "ASN" )
        {
            done = true;
            if ( (t_Table [ make_pair ((int)(Cplace1 - 'A'),Iplace1 ) ] -> d_Content) > 1 ||  (t_Table [ make_pair ((int)(Cplace1 - 'A'),Iplace1 ) ] -> d_Content) < -1)
            {
                DoneDigit = false;
                return 0;
            }
            return asin( t_Table [ make_pair ((int)(Cplace1 - 'A'),Iplace1 ) ] -> d_Content);
        }
        if ( function == "ATN" ) { done = true; return atan ( t_Table [ make_pair ((int)(Cplace1 - 'A'),Iplace1 ) ] -> d_Content); }
    }
    return 0;
}
//--------------------------------------------------------------------------------------------------
void CTable::ToLower ( string & input, bool & done )
{
    char Cplace1;
    int Iplace1;
    if ( input.length() == 2 && (isupper (input[0]) && isdigit (input[1])) )
    {
        Iplace1 = input[1] - '0'; Cplace1 = input[0];
        if (!( Iplace1 >= t_Width || (int)(Cplace1 - 'A') >= t_Height || Iplace1 < 0 || (int)(Cplace1 - 'A') < 0 ))
        {
            if( !t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)] )
            { SetCell ( (int) (Cplace1 - 'A'), Iplace1 , CEmpty() ); }
            done = true;
            if ( ( t_Table [ make_pair ( (int)(Cplace1 - 'A') , Iplace1 ) ]) && t_Table [ make_pair ( (int)(Cplace1 - 'A') , Iplace1 ) ] -> Type == "text" )
            {
                for_each(t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_Content.begin(),
                         t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_Content.end(),
                         [](char &c) { c = ::tolower(c); });
                return;
            }
        }
    }
    done = false;

}
//--------------------------------------------------------------------------------------------------
void CTable::ToUpper ( string & input, bool & done )
{
    char Cplace1;
    int Iplace1;
    if ( input.length() == 2 && (isupper (input[0]) && isdigit (input[1])) )
    {
        Iplace1 = input[1] - '0'; Cplace1 = input[0];
        if (!( Iplace1 >= t_Width || (int)(Cplace1 - 'A') >= t_Height || Iplace1 < 0 || (int)(Cplace1 - 'A') < 0 ))
        {
            if( !t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)] )
            { SetCell ( (int) (Cplace1 - 'A'), Iplace1 , CEmpty() ); }
            done = true;
            if ( ( t_Table [ make_pair ( (int)(Cplace1 - 'A') , Iplace1 ) ]) && t_Table [ make_pair ( (int)(Cplace1 - 'A') , Iplace1 ) ] -> Type == "text" )
            {
                for_each(t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_Content.begin(),
                         t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_Content.end(),
                         [](char &c) { c = ::toupper(c); });
                return;

            }
        }
    }
    done = false;

}
//--------------------------------------------------------------------------------------------------
void CTable::Clear ( string & input, bool & done )
{
    char Cplace1;
    int Iplace1;
    if ( input.length() == 2 && (isupper (input[0]) && isdigit (input[1])) )
    {
        Iplace1 = input[1] - '0'; Cplace1 = input[0];
        if (!( Iplace1 >= t_Width || (int)(Cplace1 - 'A') >= t_Height || Iplace1 < 0 || (int)(Cplace1 - 'A') < 0 ))
        {
            done = true;
            SetCell ( (int)(Cplace1 - 'A'), Iplace1 , CEmpty() );
            return;
        }
    }
    done = false;
}
//--------------------------------------------------------------------------------------------------
void CTable::AlignChange ( string & input, bool & done )
{
    char Cplace1;
    int Iplace1;
    if ( input.length() == 3 && ( isupper (input[0]) && isdigit (input[1]) && input[2] == ':') )
    {
        Iplace1 = input[1] - '0'; Cplace1 = input[0];
        if (!( Iplace1 >= t_Width || (int)(Cplace1 - 'A') >= t_Height || Iplace1 < 0 || (int)(Cplace1 - 'A') < 0 ))
        {
            if( !t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)] )
            { SetCell ( (int) (Cplace1 - 'A'), Iplace1 , CEmpty() ); }

            getline(cin, input);
            for_each(input.begin(), input.end(), [](char &c) { c = ::toupper(c); });



            if (input == "RIGHT")
            {
                done = true;
                t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_Right = true;
                t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_HorMid = false;

                if ( !t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->PersonalConfig )
                {
                    t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_Top = t_Top;
                    t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_VertMid = t_VertMid;
                    t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->PersonalConfig = true;
                }

            }
            if (input == "LEFT")
            {
                done = true;
                t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_Right = false;
                t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_HorMid = false;

                if ( !t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->PersonalConfig )
                {
                    t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_Top = t_Top;
                    t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_VertMid = t_VertMid;
                    t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->PersonalConfig = true;
                }
            }
            if (input == "TOP")
            {
                done = true;
                t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_Top = true;
                t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_VertMid = false;

                if ( !t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->PersonalConfig )
                {
                    t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_Right = t_Right;
                    t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_HorMid = t_HorMid;
                    t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->PersonalConfig = true;
                }
            }
            if (input == "DOWN")
            {
                done = true;
                t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_Top = false;
                t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_VertMid = false;
                if ( !t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->PersonalConfig )
                {
                    t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_Right = t_Right;
                    t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_HorMid = t_HorMid;
                    t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->PersonalConfig = true;
                }
            }
            if (input == "HORIZONTAL CENTER")
            {
                done = true;
                t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_HorMid = true;
                t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_Right = false;
                if ( !t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->PersonalConfig )
                {
                    t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_Top = t_Top;
                    t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_VertMid = t_VertMid;
                    t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->PersonalConfig = true;
                }
            }
            if (input == "VERTICAL CENTER")
            {
                done = true;
                t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_VertMid = true;
                t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_Top = false;
                if (!t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->PersonalConfig)
                {
                    t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_Right = t_Right;
                    t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->c_HorMid = t_HorMid;
                    t_Table[make_pair((int) (Cplace1 - 'A'), Iplace1)]->PersonalConfig = true;
                }
            }

            return;
        }
    }
    done = false;

}
//--------------------------------------------------------------------------------------------------
void CTable::PrintToFile ( string & input, bool & done )
{
    int len = input.length ( );

    if ( input[len - 1] == 't' && input[len - 2] == 'x' && input[len - 1] == 't' )
    {
        ofstream FileOut;
        FileOut.open (input);
        if ( FileOut )
        {
            done = true;
            PrintTable( FileOut );
            return;
        }
    }
    done = false;
}
//--------------------------------------------------------------------------------------------------
void CTable::SaveToFile ( string & input, bool & done )
{
    int len = input.length ( );
    string tmp = "";

    if ( input[len - 1] == 't' && input[len - 2] == 'x' && input[len - 1] == 't' )
    {
        ofstream FileOut;
        FileOut.open (input);
        if ( !FileOut )
        {
            done = false;
            return;
        }
        FileOut << TabelName << endl;
        FileOut << t_Height << ':' << t_Width << endl;

        if ( t_Top ) FileOut << "top" << endl;
        if ( t_VertMid ) FileOut << "vertmid" << endl;
        if ( !t_Top && !t_VertMid ) FileOut << "down" << endl;

        if ( t_Right ) FileOut << "right" << endl;
        if ( t_HorMid ) FileOut << "hormid" << endl;
        if ( !t_Right && !t_HorMid ) FileOut << "left" << endl;


        for (int z = 0; z < t_Height; z++)
        {
            for (int i = 0; i < t_Width; i++)
            {

                if ( t_Table [ make_pair (z,i) ] )
                {
                    tmp = t_Table[make_pair(z, i)] -> Type;
                    if( tmp != "empty" ||  t_Table[make_pair(z, i)] -> PersonalConfig )
                    {
                        FileOut << z << ':' << i << endl;
                        FileOut << tmp << endl;
                        if ( tmp == "text" )
                            FileOut << t_Table[make_pair(z, i)]->c_Content << '\n' << '\n' << endl;
                        if ( tmp == "digit")
                            FileOut << t_Table[make_pair(z, i)]-> c_Content << endl;

                    }
                    if ( t_Table[make_pair(z, i)] -> PersonalConfig )
                    {
                        FileOut << t_Table[make_pair(z, i)] -> PersonalConfig << endl;
                        if ( t_Table[make_pair(z, i)] -> c_Top ) FileOut << "top" << endl;
                        if ( t_Table[make_pair(z, i)] -> c_VertMid ) FileOut << "vertmid" << endl;
                        if ( !t_Table[make_pair(z, i)] -> c_Top && !t_Table[make_pair(z, i)] -> c_VertMid ) FileOut << "down" << endl;

                        if ( t_Table[make_pair(z, i)] -> c_Right ) FileOut << "right" << endl;
                        if ( t_Table[make_pair(z, i)] -> c_HorMid ) FileOut << "hormid" << endl;
                        if ( !t_Table[make_pair(z, i)] -> c_Right && !t_Table[make_pair(z, i)] -> c_HorMid ) FileOut << "left" << endl;
                    }
                }
            }
        }
        FileOut.close ( );
        done = true;
        return;
    }

    done = false;

}
//--------------------------------------------------------------------------------------------------
bool CTable::OpenFromFile ( string & input )
{
    int len = input.length ( );
    char del;
    bool PersonalConfig = true;
    string tmp, input_two;
    string c_Content = "";
    int w = 0;
    int h = 0;
    size_t indx;
    ifstream FileIn;

    if ( (input.length ( ) > 4 ) && input[len - 1] == 't' && input[len - 2] == 'x' && input[len - 3] == 't' && input[len - 4] == '.' )
    {
        FileIn.open ( input.c_str(), ifstream::in );
        if ( ! (FileIn.is_open ( ) ) )
            return false;

        if ( !(FileIn >> TabelName) ) { FileIn.close(); return false; }
        if ( !(FileIn >> t_Height) || t_Height > 26 || t_Height <= 0 ){ FileIn.close(); return false; }
        if ( !(FileIn >> del) || del != ':' ) { FileIn.close(); return false; }
        if ( !(FileIn >> t_Width) || t_Width <= 0 ) { FileIn.close(); return false; }
        if ( FileIn >> tmp )
        {

            if( tmp != "top" && tmp != "down" && tmp != "vertmid")
                 { FileIn.close(); return false; }
            if ( tmp == "top" )
            {
                t_Top = true;
                t_VertMid = false;
            }
            if ( tmp == "down" )
            {
                t_Top = false;
                t_VertMid = false;
            }
            if ( tmp == "vertmid" )
            {
                t_Top = false;
                t_VertMid = true;
            }

        }else { FileIn.close(); return false; }

        if ( FileIn >> tmp )
        {

            if( tmp != "right" && tmp != "left" && tmp != "hormid")
                 { FileIn.close(); return false; }
            if ( tmp == "right" )
            {
                t_Right = true;
                t_HorMid = false;
            }
            if ( tmp == "left" )
            {
                t_Right = false;
                t_HorMid = false;
            }
            if ( tmp == "hormid" )
            {
                t_Right = false;
                t_HorMid = true;
            }

        }else { FileIn.close(); return false; }

        while ( !FileIn.eof ( ) )
        {
            if ( PersonalConfig )
            {
                getline(FileIn, input);
                if (input == "\0")
                    getline(FileIn, input);
            }


            if (isdigit(input[0]))
            {
                h = stoi(input, &indx);
                if (indx < input.length())
                {
                    if ( input[indx] != ':' ) { FileIn.close(); return false; }
                    input_two = input.substr( indx + 1 );
                    if (isdigit(input_two[0]))
                        w = stoi(input_two, nullptr);
                }
            }

            if ( h >= t_Height || h < 0 || w >= t_Width || w < 0 )
            {
                FileIn.close();
                return false;
            }


            if ( FileIn >> tmp )
            {
                if( tmp != "text" && tmp != "empty" && tmp != "digit")
                    { FileIn.close(); return false; }
                if ( tmp == "text" )
                {
                    c_Content = "";
                    while ( !FileIn.eof() )
                    {
                        getline(FileIn, input);
                        if ( input == "\0" )
                            getline( FileIn ,input );
                        if (input.length() == 0)
                        {
                            if( !c_Content.empty() )
                                    c_Content.pop_back();
                            break;
                        } else
                        {
                            c_Content += input;
                            c_Content += '\n';
                        }
                    }
                    CText cell ( c_Content );
                    c_Content = "";
                    t_Table[ make_pair (h,w)] = shared_ptr<CCell>(cell.Clone());

                }
                if ( tmp == "digit" )
                {
                    c_Content = "";
                    FileIn >> c_Content;
                    CDigit cell ( c_Content );
                    c_Content = "";
                    t_Table[ make_pair (h,w)] = shared_ptr<CCell>(cell.Clone());
                }
                if ( tmp == "empty" )
                {
                    CEmpty  cell;
                    t_Table[ make_pair (h,w)] = shared_ptr<CCell>(cell.Clone());
                }
            }

            getline(FileIn, input);
            if (input == "\0")
                getline(FileIn, input);

            if ( input[0] == '1' && input.length ( ) == 1 )
            {
                PersonalConfig = true;
                FileIn >> tmp;
                if (tmp == "top")
                {
                    t_Table[make_pair(h, w)]->c_Top = true;
                    t_Table[make_pair(h, w)]->c_VertMid = false;
                    t_Table[make_pair(h, w)]->PersonalConfig = true;
                }
                if (tmp == "down")
                {
                    t_Table[make_pair(h, w)]->c_Top = false;
                    t_Table[make_pair(h, w)]->c_VertMid = false;
                    t_Table[make_pair(h, w)]->PersonalConfig = true;
                }
                if (tmp == "vertmid")
                {
                    t_Table[make_pair(h, w)]->c_VertMid = true;
                    t_Table[make_pair(h, w)]->c_Top = false;
                    t_Table[make_pair(h, w)]->PersonalConfig = true;
                }
                FileIn >> tmp;
                if (tmp == "right")
                {
                    t_Table[make_pair(h, w)]->c_Right = true;
                    t_Table[make_pair(h, w)]->c_HorMid = false;
                    t_Table[make_pair(h, w)]->PersonalConfig = true;
                }
                if (tmp == "left")
                {
                    t_Table[make_pair(h, w)]->c_Right = false;
                    t_Table[make_pair(h, w)]->c_HorMid = false;
                    t_Table[make_pair(h, w)]->PersonalConfig = true;
                }
                if (tmp == "hormid")
                {
                    t_Table[make_pair(h, w)]->c_HorMid = true;
                    t_Table[make_pair(h, w)]->c_Right = false;
                    t_Table[make_pair(h, w)]->PersonalConfig = true;
                }

            }
            else PersonalConfig = false;
        }
    }else
    {
        FileIn.close();
        return false;
    }


    FileIn.close();
    return true;

}
//=================================================================================================

