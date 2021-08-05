// Nigel Little
// Chap 10 Challenge
// This program will use a menu and struct
// to store information about the number of medals that
// have been earned in the Olympics. The struct will track
// the name of the country, the number of gold, silver, and bronze
// medals earned, and the total medals earned.
// There will be 2 functions, 1. will pass an array of structures
// to allow the user to enter data. 2. will pass an array of structures
// and display the current formatted results.

#include <stdio.h>
#include <ctype.h>

const size_t MAX_COUNTRIES = 5; //for the maximum size of the array

//enum definition
typedef enum __state {Input = 1, Display = 2, Exit = 3} State; //the ; is important

//struct definition
typedef struct __country_awards {
    int bronze;
    int silver;
    int gold;
    int totalMedals;
    char countryName[56];
} CountryAwards;//the ; is important


//prototypes
void printCountryAwards(CountryAwards *awardsPtr, int numCountries);
int inputCountryAwards(CountryAwards *awardsPtr);


int main(void){
    CountryAwards awards[MAX_COUNTRIES]; //define array of CountryAwards
    State state; //define State

    int numCountries = 0;//the number of countries entered by user

    //menu loop
    while(state != Exit){
        printf("\n=================================================================\n");
        printf("1. Enter country stats\n2. Show stats for all countries\n3. Exit\n");
        printf("=================================================================\n");
        scanf("%d",&state);

        switch(state){
            case Input:
                //inputCountryAwards will return how many entries of type CountryAwards
                numCountries = inputCountryAwards(awards);
                break;

            case Display:
                printCountryAwards(awards, numCountries);
                break;

            case Exit:
                break;
        }//end switch
    }//end while

    return 0; //indicates successful termination
}//end main

void printCountryAwards(CountryAwards *awardsPtr, int numCountries){
    //output header
    printf("\n%-14s\t%-14s\t%-14s\t%-14s\t%-14s\n","Country", "Gold",
           "Silver", "Bronze", "Total");

    //formatted output of awards data
    for(int i = 0; i < numCountries; i++){
        printf("%-14s\t%-14d\t%-14d\t%-14d\t%-14d\n", awardsPtr->countryName, awardsPtr->gold,
            awardsPtr->silver, awardsPtr->bronze, awardsPtr->totalMedals);
        awardsPtr++;
    }//end for
}//end printCountryAwards

int inputCountryAwards(CountryAwards *awardsPtr){
    int numCountries = 0; //counter for number of countries entered by user
    char choice = 'Y'; //init to 'Y' to kickstart while loop

    //prompt the user to input data for the country awards
    //until they choose to stop and the maximum number has not been reached
    while((numCountries<MAX_COUNTRIES) && (choice == 'Y')){
        //fill struct CountryAwards with data from user
        printf("\nPlease input the name of the country:");
        scanf("%s",&awardsPtr->countryName);
        printf("\nPlease input the number of Gold medals earned by %s:",awardsPtr->countryName);
        scanf("%d",&awardsPtr->gold);
        printf("\nPlease input the number of Silver medals earned by %s:",awardsPtr->countryName);
        scanf("%d",&awardsPtr->silver);
        printf("\nPlease input the number of Bronze medals earned by %s:",awardsPtr->countryName);
        scanf("%d",&awardsPtr->bronze);
        awardsPtr->totalMedals = (awardsPtr->gold)+(awardsPtr->silver)+(awardsPtr->bronze);

        printf("\nWant to enter another country's data? 'Y' to continue 'N' to exit.");
        scanf(" %c", &choice);
        choice = toupper(choice);

        numCountries++;
        awardsPtr++;
    }//end while

    if(numCountries == MAX_COUNTRIES){
        printf("\nThe maximum number of countries has been reached. The maximum number supported is %d", MAX_COUNTRIES);
    }

    return numCountries;
}//end inputCountryAwards
