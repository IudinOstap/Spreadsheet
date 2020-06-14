#include "CProgram.hpp"
//=================================================================================================
void CProgram::Start ( void )
{
    bool end = false;
    char choice;
    while( !end )
    {
	p_Table.t_Table.clear();
	p_Table.t_Right = false; p_Table.t_Top = false; p_Table.t_HorMid = false; p_Table.t_VertMid = false;
    	p_Table.t_Width = p_Table.t_Height = 0;

        choice = p_Menu.ShowMenu ( );
        switch ( choice )
        {
            case '1': // CREATE A NEW TABLE
            {
                p_Table.t_Table.clear();
                p_Table.TabelName = p_Menu.SetTableName ( );
                
                char AligChoise = p_Menu.HorizontalAliginSet ( );
                switch ( AligChoise )
                {
                    case '1': p_Table.t_Right = true; break;
                    
                    case '3':p_Table.t_HorMid = true; break;
                }
            
                AligChoise = p_Menu.VerticalAliginSet ( );
                switch ( AligChoise )
                {
                    case '1': p_Table.t_Top = true; break;
                    
                    case '3':p_Table.t_VertMid = true; break;
                }
                
                p_Menu.SetTableSize ( p_Table.t_Height , p_Table.t_Width );
                
                Run ( );
                break;
            }
                   
            case '2': // OPEN FROM FILE
                if ( p_Menu.OpenFromFileInterface ( p_Table ) )
                     Run ( );
                break;
                    
            case '3': //SETTING
            {
                char set = p_Menu.ShowSet( );
                while ( set != '2' )
                {
                    p_Menu.ShowLenguageSet( );
                    set = p_Menu.ShowSet( );
                }
                break;
            }
            case '4': //EXIT
                end = true;
                break;
        }
       
        
    }
}
//--------------------------------------------------------------------------------------------------
void CProgram::Run ( void )
{
    system("clear");
    bool end = false;
    char choise = 'a';
    string input;
    while ( !end )
    {
        cin.clear();
        input = p_Menu.ProgramRunInterface ( p_Table );
        if ( input == "EXIT" )
        {
            choise = p_Menu.ExitInterface( p_Table );
            switch ( choise )
            {
                case '1' :
                {
                    p_Menu.SaveToFileInterface ( p_Table );
                    end = true;
                    break;
                }
                case '2' :
                {
                    end = true;
                    break;
                }
                case '3' :
                    system ("clear");
                    break;
            }
        }
        if ( input == "INFO" ) p_Menu.ShwoInfo ( );
        if ( input == "SET TEXT" ) p_Menu.SetTextInterface ( p_Table );
        if ( input == "SET DIGITS" ) p_Menu.SetDigitsInterface ( p_Table );
        if ( input == "MIN" ) p_Menu.FoundMinMaxInterface ( p_Table, input );
        if ( input == "MAX" ) p_Menu.FoundMinMaxInterface ( p_Table, input );
        if ( input == "AVG" ) p_Menu.FoundAvgInterface ( p_Table );
        if ( input == "GEM" ) p_Menu.GeometricFunctionsInterface ( p_Table );
        if ( input == "TOLOWER" ) p_Menu.ToLowUpInterface ( p_Table, input );
        if ( input == "TOUPPER" ) p_Menu.ToLowUpInterface ( p_Table, input );
        if ( input == "CLEAR" ) p_Menu.ClearInterface ( p_Table );
        if ( input == "ALIGN" ) p_Menu.AliginChangeInterface ( p_Table );
        if ( input == "PRINT TO FILE" ) p_Menu.PrintToFileInterface ( p_Table );
        if ( input == "SAVE" ) p_Menu.SaveToFileInterface ( p_Table );

    }
    
}
//=================================================================================================

