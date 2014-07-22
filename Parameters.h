#ifndef PARAMETERS_H
#define PARAMETERS
#include "wx/string.h"

class Parameters
{
    public:
        Parameters();
        virtual ~Parameters();
        static void LoadValues();
        static void LoadValuesFromFile();
        static void LoadValuesFromFile(wxString& xmlFileName);
        static  int TIME_TO_BREED_PREDATOR;
        static  int TIME_TO_BREED_PREY;
        static  int TIME_TO_EAT;
        static  int PERCENT_PREDATOR;
        static  int PERCENT_PREY;
        static  int PERCENT_OBSTACLES;
        static  int PERCENT_BLACKHOLES;
        static  int PERCENT_TRANSPORTHOLES;
        static  int PERCENT_EMPTYCELLS;
        static  int PREDATOR_AGGRESSIVENESS;

        static  int NUMBER_OF_ROWS;
        static  int NUMBER_OF_COLS;
    protected:
    private:
};

#endif // PARAMETERS_H
