#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "../headers/main.h"

//-------------------------------------------------------------------------------

/*!
начальная функция main\n
вызовает функцию re_entry () в том случае если пользователь выбрал ручной режим\n
вызовает функцию test_from_program () если пользователь выбрал режим проверки внутри программы\n
вызовает функцию test_from_file () если пользователь решил ввести параметры уравнения из файла
*/

int main ()
{
    int mode_selection = 0;

    printf ("What kind of check do you want to perform?\n"
            red "1 " white "- independent decision, " red "Any number " white "- automatic program check\n");

    input_program (&mode_selection);

    if (mode_selection == MAIN_PROGRAM)
    {
        re_entry ();
    }
    else
    {
        printf ("From where the parameters of the equation will be inserted?\n"
                red "1 " white "- from program, " red "Any number " white "- from file\n");

        input_program (&mode_selection);

        if (mode_selection == FROM_PROGRAM)
        {
            test_from_program ();
        }
        else
        {
            test_from_file ();
        }
    }
    return 0;
}

//--------------------------------------------------------------------------------------

void re_entry (void)  ///<вызов основной программы
{
    while (1)
    {
        equation_parameters_t data = {NAN, NAN, NAN, NAN, NAN, 0};

        input_params (&data);

        solve (&data);

        output (&data);

        printf ("If you want to solve a different equation, enter no or yes\n");

        char buff[100] = "";

        fgets (buff, 100, stdin);
        fflush(stdin);

        if ((strcmp (buff, "no\n")) == 0 || (strcmp (buff, "No\n")) == 0 || (strcmp (buff, "NO\n")) == 0)
        {
            break;
        }
    }
}
