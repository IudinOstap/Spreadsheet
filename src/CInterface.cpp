#include "CInterface.hpp"
//=================================================================================================
CInterface::CInterface ( void )
{
    m_Language = 0;
    m_Commands["INFO"] = 1;
    m_Commands["PRINT TO FILE"] = 3;
    m_Commands["MIN"] = 6;
    m_Commands["MAX"] = 7;
    m_Commands["AVG"] = 8;
    m_Commands["GEM"] = 9;
    m_Commands["TOLOWER"] = 10;
    m_Commands["TOUPPER"] = 11;
    m_Commands["CLEAR"] = 12;
    m_Commands["SET TEXT"] = 13;
    m_Commands["SET DIGITS"] = 14;
    m_Commands["SAVE"] = 15;
    m_Commands["EXIT"] = 16;
    m_Commands["ALIGN"] = 17;
}
//--------------------------------------------------------------------------------------------------
void CInterface::NotCorrectChoise ( void )
{

    switch ( m_Language )
    {
        case 0:
            cout << "!The choice is not correct. Please choose again!\n";
            break;
                
        case 1:
            cout << "!Volba není správná. Vyberte prosím znovu!\n";
            break;
    
        case 2:
            cout << "!Ошибка. Попробуйте ещё раз!\n";
            break;
    }
}
//--------------------------------------------------------------------------------------------------
char CInterface::ShowMenu ( void )
{
    char choice = 'a';
    string input;
    system("clear");
    while ( choice <= '0' || choice > '4' )
    {
        switch ( m_Language )
        {
            case 0:
                cout << "+-------------------------+\n"
                        "| 1. Create a new table   |\n"
                        "| 2. Open table           |\n"
                        "| 3. Setting              |\n"
                        "| 4. Exit                 |\n"
                        "+-------------------------+\n";
                break;
                
            case 1:
                cout << "+-----------------------------+\n"
                        "| 1. Vytvořit novou tabulku   |\n"
                        "| 2. Otevřit tabulku          |\n"
                        "| 3. Nastavení                |\n"
                        "| 4. Ukončit                  |\n"
                        "+-----------------------------+\n";
                break;
        
            case 2:
                cout << "+----------------------------+\n"
                        "| 1. Создать новую таблицу   |\n"
                        "| 2. Открыть таблицу         |\n"
                        "| 3. Настройки               |\n"
                        "| 4. Выход                   |\n"
                        "+----------------------------+\n";
                break;
        }

        getline(cin,input);
        
        if( input.length() == 1 )
            choice = input[0];
        
        if ( choice <= '0' || choice > '4' )
        {
            system("clear");
            NotCorrectChoise ( );
        }
    }
    return choice;
}
//--------------------------------------------------------------------------------------------------
char CInterface::ShowSet  ( void )
{
    char choice = 'a';
    string input;
    system("clear");
    while ( choice <= '0' || choice > '2' )
    {
        switch ( m_Language )
        {
            case 0:
                cout << "+----------------+\n"
                        "| 1. Language    |\n"
                        "| 2. Back        |\n"
                        "+----------------+\n";
                break;
            
            case 1:
                cout << "+----------------+\n"
                        "| 1. Jazyk       |\n"
                        "| 2. Zpátky      |\n"
                        "+----------------+\n";
                break;
                
            case 2:
                cout << "+----------------+\n"
                        "| 1. Язык        |\n"
                        "| 2. Назад       |\n"
                        "+----------------+\n";
                break;
        }
        getline(cin,input);
        if( input.length() == 1 )
            choice = input[0];
        if ( choice <= '0' || choice > '2' )
        {
            system("clear");
            NotCorrectChoise ( );
        }
    }
    return choice;
}
//--------------------------------------------------------------------------------------------------
char CInterface::ShowLenguageSet ( void )
{
    char choice = 'a';
    string input;
    system("clear");
    while ( choice <= '0' || choice > '4' )
    {
        
        cout << "+-------------+\n"
                "| 1. English  |\n"
                "| 2. Čeština  |\n"
                "| 3. Русский  |\n";
                
        switch ( m_Language )
        {
            case 0:
                cout << "| 4. Back     |\n"
                        "+-------------+\n";
                break;
            
            case 1:
                cout << "| 4. Zpátky   |\n"
                        "+-------------+\n";
                break;
                
            case 2:
                cout << "| 4. Назад    |\n"
                        "+-------------+\n";
                break;
        }
        getline(cin,input);
        if( input.length() == 1 )
            choice = input[0];
        if ( choice <= '0' || choice > '4' )
        {
            system("clear");
            NotCorrectChoise ( );
        }
    }
    if ( choice < '4' ) m_Language = choice - '1';
    return choice;
}
//--------------------------------------------------------------------------------------------------
string CInterface::SetTableName ( void )
{
    system("clear");
    string name;
    switch ( m_Language )
    {
        case 0:
            cout << "+----------------------+\n"
                    "| * Name of the table: |\n"
                    "+----------------------+\n";
            break;
        
        case 1:
            cout << "+----------------------+\n"
                    "| * Nazev tabulky:     |\n"
                    "+----------------------+\n";
            break;
            
        case 2:
            cout << "+----------------------+\n"
                    "| * Название таблицы:  |\n"
                    "+----------------------+\n";
            break;
    }
    getline(cin,name);

    return name;
}
//--------------------------------------------------------------------------------------------------
char CInterface::HorizontalAliginSet ( void )
{
    char choice = 'a';
    string input;
    while ( choice <= '0' || choice > '3' )
    {
        cin.clear();
        fflush(stdin);
        switch ( m_Language )
        {
            case 0:
                cout << "+----------------------------------+\n"
                        "| * Align content to:              |\n"
                        "| 1. Right                         |\n"
                        "| 2. Left                          |\n"
                        "| 3. Horizontal center             |\n"
                        "+----------------------------------+\n";
                break;
            
            case 1:
                cout << "+-------------------------------+\n"
                        "| * Zarovnat obsah:             |\n"
                        "| 1. Doprava                    |\n"
                        "| 2. Doleva                     |\n"
                        "| 3. Horizontální středu        |\n"
                        "+-------------------------------+\n";
                break;
            
            case 2:
                cout << "+----------------------------------+\n"
                        "| * Выравнивание содержимого по:   |\n"
                        "| 1. Правому краю                  |\n"
                        "| 2. Левому краю                   |\n"
                        "| 3. Горизонтальному центру        |\n"
                        "+----------------------------------+\n";
                break;
        }
    
        getline(cin,input);
        if( input.length() == 1 )
            choice = input[0];
        if ( choice <= '0' || choice > '3' )
        {
            NotCorrectChoise ( );
        }
    }
    return choice;
}
//--------------------------------------------------------------------------------------------------
char CInterface::VerticalAliginSet ( void )
{
    char choice = 'a';
    string input;
    while ( choice <= '0' || choice > '3' )
    {
        cin.clear();
        fflush(stdin);
        switch ( m_Language )
        {
            case 0:
                cout << "+----------------------------------+\n"
                        "| * Align content to:              |\n"
                        "| 1. Top                           |\n"
                        "| 2. Down                          |\n"
                        "| 3. Vertical center               |\n"
                        "+----------------------------------+\n";
                break;
            
            case 1:
                cout << "+-----------------------------+\n"
                        "| * zarovnat obsah podle:     |\n"
                        "| 1. horního okraje           |\n"
                        "| 2. Dolního okraje           |\n"
                        "| 3. Vertikálního středu      |\n"
                        "+-----------------------------+\n";
                break;
        
            case 2:
                cout << "+----------------------------------+\n"
                        "| * Выравнивание содержимого по:   |\n"
                        "| 1. Верхнему краю                 |\n"
                        "| 2. Нижниму краю                  |\n"
                        "| 3. Вертикальному центру          |\n"
                        "+----------------------------------+\n";
                break;
        }
    
        getline(cin,input);
        if( input.length() == 1 )
            choice = input[0];
        if ( choice <= '0' || choice > '3' )
        {
            NotCorrectChoise ( );
        }
    }
    
    return choice;
}
//--------------------------------------------------------------------------------------------------
void CInterface::SetTableSize ( int & height, int & width )
{
    size_t tmp;
    height = 0;
    width = 0;
    string input;
    string input_two;
    while ( 1 )
    {
        cin.clear();
        fflush(stdin);
        switch ( m_Language )
        {
            case 0:
                cout << "+-----------------------------------------------+\n"
                        "| * Table size:  (height:width , max = 26:1000) |\n"
                        "+-----------------------------------------------+\n";
                break;
        
            case 1:
                cout << "+----------------------------------------------------+\n"
                        "| * Velikost tabulky: (výška:šířka , max = 26:1000)  |\n"
                        "+----------------------------------------------------+\n";
                break;
            
            case 2:
                cout << "+---------------------------------------------------+\n"
                        "| * Размер таблицы: (высота:ширина, макс = 26:1000) |\n"
                        "+---------------------------------------------------+\n";
                break;
        }
    
        getline(cin,input);
        if( isdigit( input[0] ) )
        {
            height = stoi (input, &tmp);
            if( tmp < input.length() )
            {
                input_two = input.substr (tmp + 1);
                if ( isdigit( input_two[0] ) )
                    width = stoi ( input_two, nullptr );
            }
        }
  
        if ( height <= 0 || height > 26 || width <= 0 || width > 1000 || input[tmp] != ':' )
        {
            height = 0;
            width = 0;
            NotCorrectChoise ( );
        } else return;
    }
    
}
//--------------------------------------------------------------------------------------------------
string CInterface::ProgramRunInterface ( CTable p_Table )
{
    bool end = false;
    cin.clear ();
    string input;
    while ( !end )
    {
        cin.clear();
        fflush(stdin);

        p_Table.PrintTable ( cout );
        switch ( m_Language )
        {
            case 0:
                cout << "+---------------------------------------------------------------+\n"
                        "| * Enter the command to work with the table ( more: \"INFO\" )   |\n"
                        "+---------------------------------------------------------------+\n";
                break;
        
            case 1:
                cout << "+---------------------------------------------------------+\n"
                        "| * Zadejte příkaz pro práci s tabulkou (více: \"INFO\" )   |\n"
                        "+---------------------------------------------------------+\n";
                break;
            
            case 2:
                cout << "+--------------------------------------------------------------+\n"
                        "| * Введите команду для работы с таблицей ( больше: \"INFO\" )   |\n"
                        "+--------------------------------------------------------------+\n";
                break;
        }
        
        getline(cin, input);

        for_each(input.begin(), input.end(), [](char & c)   {c = ::toupper(c);});



        if( m_Commands.find(input) != m_Commands.end() )
                end = true;
        else
        {
            system ("clear"); NotCorrectChoise(); input.clear();
        }
    }
    
    return input;
}
//--------------------------------------------------------------------------------------------------
void CInterface::ShwoInfo ( void )
{
    system ("clear");
        switch ( m_Language )
               {
                   case 0:
                       cout << "+-------------------------------------------------------------------------+\n"
                               "| * To manipulate a table, use the commands:                              |\n"
                               //"| \"PRINT\" : use to print tables in the terminal.                          |\n"
                               "| \"PRINT TO FILE\" : use to print tables to txt fail.                      |\n"
                               "| \"MIN / AVG /MAX\" : use to find the minimum / average /maximum value.    |\n"
                               "| \"GEM\" : use for geometric functions.                                    |\n"
                               "| \"TOLOWER/TOUPPER\" : use to change text cell.                            |\n"
                               "| \"ALIGN\" : use to change cell align.                                     |\n"
                               "| \"CLEAR\" : use to clear cell contents.                                   |\n"
                               "| \"SET TEXT/SET DIGITS\" : use to set cell content.                        |\n"
                               "| \"SAVE\" : use to save tables to txt fail.                                |\n"
                               "| \"EXIT\" : use to exit to the main menu.                                  |\n"
                               "+-------------------------------------------------------------------------+\n";
                       break;
               
                   case 1:
                       cout << "+-------------------------------------------------------------------+\n"
                               "| * Chcete-li manipulovat s tabulkou, použijte následující příkazy: |\n"
                              // "| \"PRINT\" : slouží k tisku tabulek v terminálu.                     |\n"
                               "| \"PRINT TO FILE\" : slouží k tisku tabulek do souboru.              |\n"
                               "| \"MIN / AVG /MAX\" : použijte k nalezení minimální / maximální      |\n"
                               "| průměrnou hodnoty.                                                |\n"
                               "| \"GEM\" : použijte pro geometrické funkce                           |\n"
                               "| \"TOLOWER/TOUPPER\" : slouží ke změně textové buňky.                |\n"
                               "| \"ALIGN\" : použíti k změní zarovnání.                              |\n"
                               "| \"CLEAR\" : použít k vyčištění obsahu buněk.                        |\n"
                               "| \"SET TEXT/SET DIGITS\" : slouží k nastavení obsahu buněk.          |\n"
                               "| \"SAVE\" : slouží k uložení tabulek do souboru.                     |\n"
                               "| \"EXIT\" : slouží k odchodu do hlavního menu.                       |\n"
                               "+-------------------------------------------------------------------+\n";
                       break;
                   
                   case 2:
                       cout << "+----------------------------------------------------------------------------+\n"
                               "| * Для манипуляция с таблицей используйте следующие команды:                |\n"
                              // "| \"PRINT\" : использовать для печати таблицы в терминале.                     |\n"
                               "| \"PRINT TO FILE\" : использовать для печати таблицы в фаил.                  |\n"
                               "| \"MIN / MAX / AVG\" : использования для поиска миниального/максимального/    |\n"
                               "| среднего значения.                                                         |\n"
                               "| \"GEM\" : использования для вычисления геометрических функций.               |\n"
                               "| \"TOLOWER/TOUPPER\" : использования для изменения текстовой ячейки.          |\n"
                               "| \"CLEAR\" : использования для очищения содержания ячейки.                    |\n"
                               "| \"SET TEXT/SET DIGITS\" : использования для задания содержания ячейки.       |\n"
                               "| \"SAVE\" : использовать для cохранения таблицы в фаил.                       |\n"
                               "| \"EXIT\" : использовать для выхода в главное меню.                           |\n"
                               "+----------------------------------------------------------------------------+\n";
                       break;
        
        
               }
}
//--------------------------------------------------------------------------------------------------
void CInterface::SetTextInterface ( CTable & p_Table )
{
    system ("clear");
    bool end = false;
    bool done = true;
    string input;
    while( !end )
    {
        if ( !done ) { system ("clear");  NotCorrectChoise(); input.clear(); }
        else system("clear");
        done = false;
        cin.clear();
        fflush(stdin);
        p_Table.PrintTable ( cout );
        switch ( m_Language )
        {
            case 0:
                cout << "+-----------------------------------------------------------------+\n"
                        "| * Use the following form :                                      |\n"
                        "| Cell address: cell contents ended with double indentation.      |\n"
                        "| (A2:\\nHELLO WORLD\\n\\n)  or  (A2=\\nA3+B2)  or  (A2=\\nA3)         |\n"
                        "| * \"BACK\" to go back.                                            |\n"
                        "+-----------------------------------------------------------------+\n";
                break;
        
            case 1:
                cout << "+-------------------------------------------------------------------+\n"
                        "| * Použijte následující formulář :                                 |\n"
                        "| Adresa buňky: obsah buňky končí dvojitým odsazením.               |\n"
                        "| (A2:\\nHELLO WORLD\\n\\n)  nebo  (A2=\\nA3+B2)  nebo  (A2=\\nA3)       |\n"
                        "| * \"BACK\" pro navrát zpátky.                                       |\n"
                        "+-------------------------------------------------------------------+\n";
                break;
            
            case 2:
            cout << "+-------------------------------------------------------------------+\n"
                    "| * Используйте следующую форму :                                   |\n"
                    "| Aдрес ячейки: содержимое ячейки заканчивается двойным отступом.   |\n"
                    "| (A2:\\nHELLO WORLD\\n\\n)  или  (A2=\\nA3+B2)  или  (A2=\\nA3)         |\n"
                    "| * \"BACK\" чтобы вернуться назад.                                   |\n"
                    "+-------------------------------------------------------------------+\n";
                break;
        }
        
        
        getline(cin,input);
        for_each(input.begin(), input.end(), [](char & c)   {c = ::toupper(c);});
        if( input == "BACK" ) {  end = true;  system("clear"); return; }
        
        p_Table.SetText ( input, done );
    }
}
//--------------------------------------------------------------------------------------------------
void CInterface::SetDigitsInterface ( CTable & p_Table )
{
    system ("clear");
    bool end = false;
    bool done = true;
    string input;
    while( !end )
    {
        if ( !done ) { system ("clear");  NotCorrectChoise(); input.clear(); }
        else system("clear");
        done = false;
        cin.clear();
        fflush(stdin);

        p_Table.PrintTable ( cout );
        switch ( m_Language )
        {
            case 0:
                cout << "+-----------------------------------------------------------------+\n"
                        "| * Use the following form :                                      |\n"
                        "| Cell address: cell contents ended with double indentation.      |\n"
                        "| (A2:\\n123.45\\n)  or  (A2=\\nA3+-*/B2)  or  (A2=\\nA3)             |\n"
                        "| * \"BACK\" to go back.                                            |\n"
                        "+-----------------------------------------------------------------+\n";
                break;
        
            case 1:
                cout << "+-------------------------------------------------------------------+\n"
                        "| * Použijte následující formulář :                                 |\n"
                        "| Adresa buňky: obsah buňky končí dvojitým odsazením.               |\n"
                        "| (A2:\\n123.45\\n)  nebo  (A2=\\nA3+-*/B2)  nebo  (A2=\\nA3)           |\n"
                        "| * \"BACK\" pro navrát zpátky.                                       |\n"
                        "+-------------------------------------------------------------------+\n";
                break;
            
            case 2:
            cout << "+-------------------------------------------------------------------+\n"
                    "| * Используйте следующую форму :                                   |\n"
                    "| Aдрес ячейки: содержимое ячейки заканчивается двойным отступом.   |\n"
                    "| (A2:\\n1234.5\\n)  или  (A2=\\nA3+-*/B2)  или  (A2=\\nA3)             |\n"
                    "| * \"BACK\" чтобы вернуться назад.                                   |\n"
                    "+-------------------------------------------------------------------+\n";
                break;
        }
        cin.clear();
        getline(cin,input);
        for_each(input.begin(), input.end(), [](char & c)   {c = ::toupper(c);});

        if( input == "BACK" ) { end = true;  system("clear"); return; }
        p_Table.SetDigits ( input, done );
    }
    system("clear");
}
//--------------------------------------------------------------------------------------------------
void CInterface::FoundMinMaxInterface ( CTable & p_Table, string wanted )
{
    bool end = false;
    bool back = false;
    bool done = true;
    bool DoneText = false;
    bool DoneDigit = false;
    double  MinDigit;
    double  MaxDigit;
    string  MinText;
    string  MaxText;

    while ( !end )
    {
        if ( !done ) { system ("clear");  NotCorrectChoise();  }
        else system("clear");
        done = false;
        cin.clear();
        fflush(stdin);
        p_Table.PrintTable ( cout );

        switch (m_Language)
        {
            case 0:
                cout << "+----------------------------------------+\n"
                        "| * Use the following form :             |\n"
                        "| Set start and end cell for search      |\n"
                        "| (A0-B2)\\n                              |\n"
                        "| * \"BACK\" to go back.                   |\n"
                        "+----------------------------------------+\n";
                break;
            case 1:
                cout << "+---------------------------------------------------------------+\n"
                        "| * Použijte následující formulář :                             |\n"
                        "| Nastavte počáteční a koncovou buňku pro vyhledávání           |\n"
                        "| (A0-B2)\\n                                                     |\n"
                        "| * \"BACK\" pro navrát zpátky.                                   |\n"
                        "+---------------------------------------------------------------+\n";
                break;
            case 2:
                cout << "+---------------------------------------------------+\n"
                        "| * Используйте следующую форму :                   |\n"
                        "| Задайте стартовую и конечную клетку для поиска.   |\n"
                        "| (A0-B2)\\n                                         |\n"
                        "| * \"BACK\" чтобы вернуться назад.                   |\n"
                        "+---------------------------------------------------+\n";
                break;
        }

        if ( wanted == "MAX")
            p_Table.FoundMax ( done, back , MaxDigit , MaxText, DoneText, DoneDigit);
        else
            p_Table.FoundMin ( done, back , MinDigit , MinText, DoneText, DoneDigit);


        if( !back && done )
        {
            if (wanted == "MAX")
            switch (m_Language) {
                case 0:
                    cout << "+-------------------------+\n"
                            "| * Maximum text value :  |\n"
                            "+-------------------------+\n";
                             if (!DoneText ) cout << "Not found.\n";
                             else cout << MaxText << endl;
                    cout << "+-------------------------+\n"
                            "| * Maxium digit value :   |\n"
                            "+-------------------------+\n";
                            if (!DoneDigit ) cout << "Not found.\n";
                            else cout << MaxDigit << endl;

                    break;
                case 1:
                    cout << "+-------------------------------+\n"
                            "| * Maximální textová hodnota : |\n"
                            "+-------------------------------+\n";
                            if (!DoneText ) cout << "Nenalezeno.\n";
                            else cout << MaxText << endl;
                    cout << "+-------------------------------+\n"
                            "| * Maximální číslová hodnota : |\n"
                            "+-------------------------------+\n";
                             if (!DoneDigit ) cout << "Nenalezeno.\n";
                             else cout << MaxDigit << endl;

                    break;
                case 2:
                    cout << "+--------------------------------------+\n"
                            "| * Mаксимальное текстовое значение :  |\n"
                            "+--------------------------------------+\n";
                            if (!DoneText ) cout << "Не найдено.\n";
                            else cout << MaxText << endl;
                    cout << "+--------------------------------------+\n"
                            "| * Mаксимальное числовое значение :   |\n"
                            "+--------------------------------------+\n";
                             if (!DoneDigit ) cout << "Не найдено.\n";
                             else cout << MaxDigit << endl;
                    break;
            }
            else
                switch (m_Language) {
                    case 0:
                        cout << "+-------------------------+\n"
                                "| * Minimum text value :  |\n"
                                "+-------------------------+\n";
                                 if (!DoneText ) cout << "Not found.\n";
                                 else cout << MinText << endl;
                        cout << "+-------------------------+\n"
                                "| * Minimum digit value : |\n"
                                "+-------------------------+\n";
                                if (!DoneDigit ) cout << "Not found.\n";
                                else cout << MinDigit << endl;

                        break;
                    case 1:
                        cout << "+-------------------------------+\n"
                                "| * Minmální textová hodnota :  |\n"
                                "+-------------------------------+\n";
                                 if (!DoneText ) cout << "Nenalezeno.\n";
                                 else cout << MinText << endl;
                        cout << "+-------------------------------+\n"
                                "| * Minmální číslová hodnota :  |\n"
                                "+-------------------------------+\n";
                                 if (!DoneDigit ) cout << "Nenalezeno.\n";
                                 else cout << MinDigit << endl;

                        break;
                    case 2:
                        cout << "+--------------------------------------+\n"
                                "| * Mинимальное текстовое значение :   |\n"
                                "+--------------------------------------+\n";
                                 if (!DoneText ) cout << "Не найдено.\n";
                                 else cout << MinText << endl;
                        cout << "+--------------------------------------+\n"
                                "| * Mинимальное числовое значение :    |\n"
                                "+--------------------------------------+\n";
                                if (!DoneDigit ) cout << "Не найдено.\n";
                                else cout << MinDigit << endl;
                        break;
                }

        }
        if ( back ) { end = true;  system("clear"); return; }
        if( done ) switch (m_Language)
        {
            case 0:
                cout << "+-------------------------------+\n"
                        "| * Press ENTER to continue...  |\n"
                        "+-------------------------------+\n";


                break;
            case 1:
                cout << "+---------------------------------------+\n"
                        "| * Stiskněte ENTER pro pokračování...  |\n"
                        "+---------------------------------------+\n";

                break;
            case 2:
                cout << "+---------------------------------------+\n"
                        "| * Hажмите ENTER чтобы продолжить...   |\n"
                        "+---------------------------------------+\n";
                break;
        }

        std::cin.ignore(INT8_MAX,'\n');

    }


}
//--------------------------------------------------------------------------------------------------
void CInterface::FoundAvgInterface ( CTable & p_Table )
{
    bool end = false;
    bool back = false;
    bool done = true;
    bool DoneDigit = false;
    double AvgDigit;

    while ( !end )
    {
        if ( !done ) { system ("clear");  NotCorrectChoise();  }
        else system("clear");
        done = false;
        cin.clear();
        fflush(stdin);
        p_Table.PrintTable ( cout );

        switch (m_Language)
        {
            case 0:
                cout << "+----------------------------------------+\n"
                        "| * Use the following form :             |\n"
                        "| Set start and end cell for search      |\n"
                        "| (A0-B2)\\n                              |\n"
                        "| * \"BACK\" to go back.                   |\n"
                        "+----------------------------------------+\n";
                break;
            case 1:
                cout << "+---------------------------------------------------------------+\n"
                        "| * Použijte následující formulář :                             |\n"
                        "| Nastavte počáteční a koncovou buňku pro vyhledávání           |\n"
                        "| (A0-B2)\\n                                                     |\n"
                        "| * \"BACK\" pro navrát zpátky.                                   |\n"
                        "+---------------------------------------------------------------+\n";
                break;
            case 2:
                cout << "+---------------------------------------------------+\n"
                        "| * Используйте следующую форму :                   |\n"
                        "| Задайте стартовую и конечную клетку для поиска.   |\n"
                        "| (A0-B2)\\n                                         |\n"
                        "| * \"BACK\" чтобы вернуться назад.                   |\n"
                        "+---------------------------------------------------+\n";
                break;
        }

        p_Table.FoundAvg ( done, back, AvgDigit, DoneDigit);
        if( !back && done )
        {

            switch (m_Language) {
                case 0:
                    cout << "+-------------------------+\n"
                            "| * Average digit value : |\n"
                            "+-------------------------+\n";
                    if (!DoneDigit ) cout << "Not found.\n";
                    else cout << AvgDigit << endl;
                    break;
                case 1:
                    cout << "+-------------------------------+\n"
                            "| * Průměrná číslová hodnota  : |\n"
                            "+-------------------------------+\n";
                    if (!DoneDigit ) cout << "Nenalezeno.\n";
                    else cout << AvgDigit << endl;


                    break;
                case 2:
                    cout << "+--------------------------------+\n"
                            "| * Cреднее числовое значение :  |\n"
                            "+--------------------------------+\n";
                    if (!DoneDigit ) cout << "Не найдено.\n";
                    else cout << AvgDigit << endl;
                    break;
                }

        }
        if ( back ) { end = true;  system("clear"); return; }
        if( done )
            switch (m_Language)
            {
                case 0:
                    cout << "+-------------------------------+\n"
                            "| * Press ENTER to continue...  |\n"
                            "+-------------------------------+\n";


                    break;
                case 1:
                    cout << "+---------------------------------------+\n"
                            "| * Stiskněte ENTER pro pokračování...  |\n"
                            "+---------------------------------------+\n";

                    break;
                case 2:
                    cout << "+---------------------------------------+\n"
                            "| * Hажмите ENTER чтобы продолжить...   |\n"
                            "+---------------------------------------+\n";
                    break;
            }

        cin.ignore(INT8_MAX,'\n');

    }

}
//--------------------------------------------------------------------------------------------------
void CInterface::GeometricFunctionsInterface ( CTable & p_Table )
{
    system ("clear");
    bool end = false;
    bool done = true;
    bool DoneDigit = false;
    string input;
    while( !end )
    {
        if ( !done ) { system ("clear");  NotCorrectChoise(); input.clear(); }
        else system("clear");
        done = false;
        cin.clear();
        fflush(stdin);
        p_Table.PrintTable ( cout );
        switch (m_Language)
        {
            case 0:
                cout << "+----------------------------------------+\n"
                        "| * Use the following form :             |\n"
                        "| Set function and cell                  |\n"
                        "| SIN/COS/TAN/ACS/ASN/ATN(A2)\\n          |\n"
                        "| * \"BACK\" to go back.                   |\n"
                        "+----------------------------------------+\n";
                break;
            case 1:
                cout << "+----------------------------------------+\n"
                        "| * Použijte následující formulář :      |\n"
                        "| Nastavte funkci a buňku                |\n"
                        "| SIN/COS/TAN/ACS/ASN/ATN(A2)\\n          |\n"
                        "| * \"BACK\" pro navrát zpátky.            |\n"
                        "+----------------------------------------+\n";
                break;
            case 2:
                cout << "+-------------------------------------+\n"
                        "| * Используйте следующую форму :     |\n"
                        "| Задайте функцию и ячейку            |\n"
                        "| SIN/COS/TAN/ACS/ASN/ATN(A2)\\n       |\n"
                        "| * \"BACK\" чтобы вернуться назад.     |\n"
                        "+-------------------------------------+\n";
                break;
        }


        getline(cin,input);
        for_each(input.begin(), input.end(), [](char & c)   {c = ::toupper(c);});

        if( input == "BACK" ) {  end = true;  system("clear"); return; }
        double res = p_Table.GeometricFunctions( input, done, DoneDigit);
        if( done )
        {

            switch (m_Language)
            {
                case 0:
                    cout << "+------------+\n"
                            "| * Result : |\n"
                            "+------------+\n";
                    if (!DoneDigit ) cout << "Not found.\n";
                    else cout << res << endl;
                    break;
                case 1:
                    cout << "+--------------+\n"
                            "| * Výsledek : |\n"
                            "+--------------+\n";
                    if (!DoneDigit ) cout << "Nenalezeno.\n";
                    else cout << res << endl;


                    break;
                case 2:
                    cout << "+----------------+\n"
                            "| * Pезультат  : |\n"
                            "+----------------+\n";
                    if (!DoneDigit ) cout << "Не найдено.\n";
                    else cout << res << endl;
                    break;
            }
            if( done )
                switch (m_Language)
                {
                    case 0:
                        cout << "+-------------------------------+\n"
                                "| * Press ENTER to continue...  |\n"
                                "+-------------------------------+\n";


                        break;
                    case 1:
                        cout << "+---------------------------------------+\n"
                                "| * Stiskněte ENTER pro pokračování...  |\n"
                                "+---------------------------------------+\n";

                        break;
                    case 2:
                        cout << "+---------------------------------------+\n"
                                "| * Hажмите ENTER чтобы продолжить...   |\n"
                                "+---------------------------------------+\n";
                        break;
                }
            cin.ignore(INT8_MAX,'\n');
        }
    }
}
//--------------------------------------------------------------------------------------------------
void CInterface::ToLowUpInterface ( CTable & p_Table, string wanted )
{
    bool end = false;
    bool done = true;
    string input;
    system("clear");

    while ( !end )
    {

        if ( !done ) { system ("clear");  NotCorrectChoise(); input.clear(); }
        else system("clear");
        done = false;
        cin.clear();
        fflush(stdin);
        p_Table.PrintTable ( cout );
        switch (m_Language)
        {
            case 0:
                cout << "+----------------------------------------+\n"
                        "| * Use the following form :             |\n"
                        "| Set cell                               |\n"
                        "| (A2)\\n                                 |\n"
                        "| * \"BACK\" to go back.                   |\n"
                        "+----------------------------------------+\n";
                break;
            case 1:
                cout << "+----------------------------------------+\n"
                        "| * Použijte následující formulář :      |\n"
                        "| Nastavte buňku                         |\n"
                        "| (A2)\\n                                 |\n"
                        "| * \"BACK\" pro navrát zpátky.            |\n"
                        "+----------------------------------------+\n";
                break;
            case 2:
                cout << "+-------------------------------------+\n"
                        "| * Используйте следующую форму :     |\n"
                        "| Задайте ячейку                      |\n"
                        "| (A2)\\n                              |\n"
                        "| * \"BACK\" чтобы вернуться назад.     |\n"
                        "+-------------------------------------+\n";
                break;
        }

        getline(cin,input);
        for_each ( input.begin(), input.end(), [](char & c)   {c = ::toupper(c);} );

        if( input == "BACK" ) {  end = true;  system("clear"); return; }

        if ( wanted == "TOUPPER")
            p_Table.ToUpper ( input, done );
        else
            p_Table.ToLower ( input, done );

    }
}
//--------------------------------------------------------------------------------------------------
void CInterface::ClearInterface ( CTable & p_Table )
{

    bool end = false;
    bool done = true;
    string input;
    system("clear");

    while ( !end )
    {

        if (!done)
        {
            system("clear");
            NotCorrectChoise();
            input.clear();
        }
        else system("clear");
        done = false;
        cin.clear();
        fflush(stdin);
        p_Table.PrintTable(cout);
        switch (m_Language)
        {
            case 0:
                cout << "+----------------------------------------+\n"
                        "| * Use the following form :             |\n"
                        "| Set cell                               |\n"
                        "| (A2)\\n                                 |\n"
                        "| * \"BACK\" to go back.                   |\n"
                        "+----------------------------------------+\n";
                break;
            case 1:
                cout << "+----------------------------------------+\n"
                        "| * Použijte následující formulář :      |\n"
                        "| Nastavte buňku                         |\n"
                        "| (A2)\\n                                 |\n"
                        "| * \"BACK\" pro navrát zpátky.            |\n"
                        "+----------------------------------------+\n";
                break;
            case 2:
                cout << "+-------------------------------------+\n"
                        "| * Используйте следующую форму :     |\n"
                        "| Задайте ячейку                      |\n"
                        "| (A2)\\n                              |\n"
                        "| * \"BACK\" чтобы вернуться назад.     |\n"
                        "+-------------------------------------+\n";
                break;
        }

        getline(cin, input);
        for_each(input.begin(), input.end(), [](char &c) { c = ::toupper(c); });

        if (input == "BACK")
        {
            end = true;
            system("clear");
            return;
        }

        p_Table.Clear ( input, done );

    }

}
//--------------------------------------------------------------------------------------------------
void CInterface::AliginChangeInterface ( CTable & p_Table )
{
    bool end = false;
    bool done = true;
    string input;
    system("clear");

    while ( !end )
    {

        if (!done)
        {
            system("clear");
            NotCorrectChoise();
            input.clear();
        }
        else system("clear");
        done = false;
        cin.clear();
        fflush(stdin);
        p_Table.PrintTable(cout);
        switch (m_Language)
        {
            case 0:
                cout << "+-----------------------------------------------------------------------------+\n"
                        "| * Use the following form :                                                  |\n"
                        "| Set cell                                                                    |\n"
                        "| (A2:\\n right / left / top / horizontal center / vertical center / down)\\n   |\n"
                        "| * \"BACK\" to go back.                                                        |\n"
                        "+-----------------------------------------------------------------------------+\n";
                break;
            case 1:
                cout << "+-----------------------------------------------------------------------------+\n"
                        "| * Použijte následující formulář :                                           |\n"
                        "| Nastavte buňku                                                              |\n"
                        "| (A2:\\n right / left / top / horizontal center / vertical cenetr / down)\\n   |\n"
                        "| * \"BACK\" pro navrát zpátky.                                                 |\n"
                        "+-----------------------------------------------------------------------------+\n";
                break;
            case 2:
                cout << "+----------------------------------------------------------------------------+\n"
                        "| * Используйте следующую форму :                                            |\n"
                        "| Задайте ячейку                                                             |\n"
                        "| (A2:\\n right / left / top / horizontal center / vertical center / down)\\n  |\n"
                        "| * \"BACK\" чтобы вернуться назад.                                            |\n"
                        "+----------------------------------------------------------------------------+\n";
                break;
        }

        getline(cin, input);
        for_each(input.begin(), input.end(), [](char &c) { c = ::toupper(c); });

        if (input == "BACK")
        {
            end = true;
            system("clear");
            return;
        }
        p_Table.AlignChange ( input, done);

    }


}
//--------------------------------------------------------------------------------------------------
void CInterface::PrintToFileInterface ( CTable & p_Table )
{
    system("clear");
    string input;
    bool end = false;
    bool done = true;
    while (!end)
    {
        if (!done)
        {
            system("clear");
            NotCorrectChoise();
            input.clear();
        }
        else system("clear");


        switch (m_Language)
        {
            case 0:
                cout << "+---------------------------------------+\n"
                        "| * Name of txt file for print :        |\n"
                        "| * \"BACK\" to go back.                  |\n"
                        "+---------------------------------------+\n";
                break;

            case 1:
                cout << "+-------------------------------------------+\n"
                        "| * Nazev txt souboru pro výpis :           |\n"
                        "| * \"BACK\" pro navrát zpátky.               |\n"
                        "+-------------------------------------------+\n";
                break;

            case 2:
                cout << "+-------------------------------------------------+\n"
                        "| * Название txt файла для выписа :               |\n"
                        "| * \"BACK\" чтобы вернуться назад.                 |\n"
                        "+-------------------------------------------------+\n";
                break;
        }

        getline(cin, input);
        if (input == "BACK" || input == "back")
        {
            end = true;
            system("clear");
            return;
        }

        p_Table.PrintToFile ( input, done);
        if( done ) {
            switch (m_Language) {
                case 0:
                    cout << "+-------------------------------+\n"
                            "| * Print was successful.       |\n"
                            "| * Press ENTER to continue...  |\n"
                            "+-------------------------------+\n";


                    break;
                case 1:
                    cout << "+---------------------------------------+\n"
                            "| * Výpis byl úspěšný                   |\n"
                            "| * Stiskněte ENTER pro pokračování...  |\n"
                            "+---------------------------------------+\n";

                    break;
                case 2:
                    cout << "+---------------------------------------+\n"
                            "| * Выписование прошло успешно          |\n"
                            "| * Hажмите ENTER чтобы продолжить...   |\n"
                            "+---------------------------------------+\n";
                    break;
            }
            cin.ignore(INT8_MAX, '\n');
        }
    }
}
//--------------------------------------------------------------------------------------------------
void CInterface::SaveToFileInterface ( CTable & p_Table )
{
    system("clear");
    string input;
    bool end = false;
    bool done = true;
    while (!end)
    {
        if (!done)
        {
            system("clear");
            NotCorrectChoise();
            input.clear();
        }
        else system("clear");


        switch (m_Language)
        {
            case 0:
                cout << "+---------------------------------------+\n"
                        "| * Name of txt file for save :         |\n"
                        "| * \"BACK\" to go back.                  |\n"
                        "+---------------------------------------+\n";
                break;

            case 1:
                cout << "+-------------------------------------------+\n"
                        "| * Nazev txt souboru pro uložení :         |\n"
                        "| * \"BACK\" pro navrát zpátky.               |\n"
                        "+-------------------------------------------+\n";
                break;

            case 2:
                cout << "+-------------------------------------------------+\n"
                        "| * Название txt файла для сoxранения :           |\n"
                        "| * \"BACK\" чтобы вернуться назад.                 |\n"
                        "+-------------------------------------------------+\n";
                break;
        }

        getline(cin, input);
        if (input == "BACK" || input == "back")
        {
            end = true;
            system("clear");
            return;
        }

        p_Table.SaveToFile ( input, done);
        if( done ) {
            switch (m_Language) {
                case 0:
                    cout << "+-------------------------------+\n"
                            "| * Saving was successful.      |\n"
                            "| * Press ENTER to continue...  |\n"
                            "+-------------------------------+\n";

                    break;
                case 1:
                    cout << "+---------------------------------------+\n"
                            "| * Úložení bylo úspěšné                |\n"
                            "| * Stiskněte ENTER pro pokračování...  |\n"
                            "+---------------------------------------+\n";

                    break;
                case 2:
                    cout << "+---------------------------------------+\n"
                            "| * Cохранение прошло успешно           |\n"
                            "| * Hажмите ENTER чтобы продолжить...   |\n"
                            "+---------------------------------------+\n";
                    break;
            }
            cin.ignore(INT8_MAX, '\n');
        }
    }


}
//--------------------------------------------------------------------------------------------------
char CInterface::ExitInterface ( CTable & p_Table )
{
    char choice = 'a';
    string input;
    while ( choice <= '0' || choice > '3' )
    {
        cin.clear();
        fflush(stdin);
        switch ( m_Language )
        {
            case 0:
                cout << "+--------------------------+\n"
                        "| * Save the table ?       |\n"
                        "| 1. Yes                   |\n"
                        "| 2. No                    |\n"
                        "| 3. Cancel                |\n"
                        "+--------------------------+\n";
                break;

            case 1:
                cout << "+------------------------+\n"
                        "| * Úložit tabulku ?     |\n"
                        "| 1. Ano                 |\n"
                        "| 2. Ne                  |\n"
                        "| 3. Zrušit              |\n"
                        "+------------------------+\n";
                break;

            case 2:
                cout << "+------------------------+\n"
                        "| * Сохрaнить таблицу ?  |\n"
                        "| 1. Да                  |\n"
                        "| 2. Нет                 |\n"
                        "| 3. Отмена              |\n"
                        "+------------------------+\n";
                break;
        }

        getline(cin,input);
        if( input.length() == 1 )
            choice = input[0];
        if ( choice <= '0' || choice > '3' )
        {
            NotCorrectChoise ( );
        }
    }
    return choice;

}
//--------------------------------------------------------------------------------------------------
bool CInterface::OpenFromFileInterface ( CTable & p_Table )
{
    system("clear");
    string input;
    bool end = false;
    bool done = true;
    while (!end)
    {
        if (!done)
        {
            system("clear");
            NotCorrectChoise();
            input.clear();
        }
        else system("clear");

        switch (m_Language)
        {
            case 0:
                cout << "+---------------------------------------+\n"
                        "| * Name of txt file for open :         |\n"
                        "| * \"BACK\" to go back.                  |\n"
                        "+---------------------------------------+\n";
                break;

            case 1:
                cout << "+-----------------------------------------+\n"
                        "| * Nazev txt souboru pro otevření :      |\n"
                        "| * \"BACK\" pro navrát zpátky.               |\n"
                        "+-----------------------------------------+\n";
                break;

            case 2:
                cout << "+----------------------------------------------+\n"
                        "| * Название txt файла для открытия :          |\n"
                        "| * \"BACK\" чтобы вернуться назад.              |\n"
                        "+----------------------------------------------+\n";
                break;
        }

        getline(cin, input);
        if (input == "BACK" || input == "back"  )
        {
            end = true;
            system("clear");
            return false;
        }

        if( p_Table.OpenFromFile ( input ) )
            return true;
        else done = false;


    }

    return false;

}
//=================================================================================================
