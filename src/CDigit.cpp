#include "CDigit.hpp"
//=================================================================================================
CDigit::CDigit ( const string & content ) : CCell ( content )
{
    Type = "digit";
    c_Width = content.length();
    c_Height = 1;
    d_Content = stod ( content );
}
//--------------------------------------------------------------------------------------------------
CDigit::CDigit ( const CDigit & x) : CCell()
{
    Type = "digit";
    c_Height = x.c_Height; c_Width = x.c_Width; c_Content = x.c_Content; d_Content = x.d_Content;
    c_Right = x.c_Right;
    c_Top = x.c_Top;
    c_HorMid = x.c_HorMid;
    c_VertMid = x.c_VertMid;
    PersonalConfig = x.PersonalConfig;
}
//--------------------------------------------------------------------------------------------------
CDigit::CDigit ( const double & content ) : CCell ()
{
    Type = "digit";
    d_Content = content;
    c_Height = 1;
    c_Content = to_string(d_Content);
    int tmp  = c_Content.length();
    for ( int i = tmp - 1 ; i > 0 ; i-- )
    {
        if ( c_Content[i] == '0' )  c_Content.pop_back();
        else break;
    }
    c_Width = c_Content.length ( );
    if ( c_Content[ c_Width - 1 ] == '.' )
    {
        c_Content.pop_back ( );
        c_Width--;
    }
}
//--------------------------------------------------------------------------------------------------
ostream & CDigit::Print_Cell_Line ( ostream & out,const int & height,const int & width,const int & height_max,  bool right, bool top, bool HorMid, bool VertMid )
{
    int count = 0;
      string tmp = "";
      
      if ( PersonalConfig )
      {
          right = c_Right;
          top = c_Top;
          HorMid = c_HorMid;
          VertMid = c_VertMid;
      }
      
      if ( top )
      {
          if( height > c_Height )
          {
              out << setw(width) << ' ';
              return out;
          }
          
          for ( ; CharInd < (int)c_Content.length() ; CharInd++ )
          {
              if ( c_Content[CharInd] == '\n' ) LineInd++;
              if( LineInd == height ) break;
          }
          if ( c_Content[CharInd] == '\n' ) CharInd++;
          
          while ( CharInd < (int)c_Content.length() )
          {
              if ( c_Content[CharInd] == '\n' ) break;
              if ( c_Content[CharInd] != 0 ) tmp += c_Content[CharInd];
              CharInd++;
          }
          
          if ( right )
          {
              for ( int i = 0 ; i < (int)(width - tmp.length()) ; i++)
                  out << ' ';
              out << tmp;
              return out;
          }
          if ( HorMid )
          {
              count = ( width - tmp.length() ) / 2;
              
              for ( int z = 0 ; z < count ; z++ )
                  out << ' ';
              out << tmp;
              
              for ( int z = 0 ; z < (int)( width - count - tmp.length() ) ; z++ )
                  out << ' ';
              
              return out;
          }
          
          //if ( left)
          out << setw(width) << left << tmp;
          return out;
      }
      
      if ( VertMid )
      {
          if ( height >= ( c_Height + c_Empty ) )
          {
              out << setw(width) << ' ';
              return out;
          }
          
          if ( height < ( (height_max - c_Height) / 2 ) )
          {
              c_Empty++;
              out << setw(width) << ' ';
              return out;
          }
          
          for ( ; CharInd < (int)c_Content.length() ; CharInd++ )
          {
              if ( LineInd == (height - c_Empty) ) break;
              if ( c_Content[CharInd] == '\n' ) LineInd++;
          }
          
          while ( CharInd < (int)c_Content.length() )
          {
             // count++;
              if ( c_Content[CharInd] == '\n' ) break;
              if ( c_Content[CharInd] != 0 ) tmp += c_Content[CharInd];
              CharInd++;
          }
          
          if ( right )
          {
              for ( int i = 0 ; i < (int)(width - tmp.length()) ; i++)
                  out << ' ';
              out << tmp;
              return out;
          }
          if ( HorMid )
          {
              count = ( width - tmp.length() ) / 2;
              
              for ( int z = 0 ; z < count ; z++ )
                  out << ' ';
              out << tmp;
              
              for ( int z = 0 ; z < (int)( width - count - tmp.length() ) ; z++ )
                  out << ' ';
              
              return out;
          }
                 
          //if ( left )
          out << setw(width) << left << tmp;
          return out;
      }
      
      //if ( down )
      if ( c_Empty < (height_max - c_Height) )
      {
          out << setw(width) << ' ';
          c_Empty++;
          return out;
      }
      for ( ; CharInd < (int)c_Content.length() ; CharInd++ )
      {
          if ( c_Content[CharInd] == '\n' ) LineInd++;
          if( LineInd == (height - c_Empty) ) break;
      }
      if ( c_Content[CharInd] == '\n' ) CharInd++;

      while ( CharInd < (int)c_Content.length() )
      {
          if ( c_Content[CharInd] == '\n' ) break;
          if ( c_Content[CharInd] != 0 ) tmp += c_Content[CharInd];
          CharInd++;
      }
      if ( right )
      {
          for ( int i = 0 ; i < (int)(width - tmp.length()) ; i++)
              out << ' ';
          out << tmp;
          return out;
      }
      if ( HorMid )
      {
          count = ( width - tmp.length() ) / 2;
          
          for ( int z = 0 ; z < count ; z++ )
              out << ' ';
          out << tmp;
          
          for ( int z = 0 ; z < (int)( width - count - tmp.length() ) ; z++ )
              out << ' ';
          
          return out;
      }
             
      //if ( left)
      out << setw(width) << left << tmp;
      return out;
}

//--------------------------------------------------------------------------------------------------
