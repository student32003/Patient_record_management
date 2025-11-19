#include<stdio.h>
#include<stdint.h>
#include<string.h>

#define MAX_NAME_LENGTH  100
#define MAX_DISEASE_LENGTH 100


typedef struct 
{
   int year;
   int month;
    int day;
} date_t;


//ENUM for options(only one at a time )
typedef enum{

    STATUS_ADMITTED = 0, //Patient is currently in hospital 
    STATUS_DISCHARGED = 1,//Patient has been released 
    // STATUS_TRANSFERRED = 2,//Patient moved to another facility 
    // STATUS_CRITICAL = 3    //Patient in critical condition 
} patient_status_t;


//struct for grouping data (all at same time )
typedef struct {
    int32_t           ID;                          //Unique patient identity
    char              name[MAX_NAME_LENGTH];       //Patient full name
    int8_t            age ;                        //patient age
    char              disease[MAX_DISEASE_LENGTH]; //Patient problem
    date_t            addmission_date;             //Date of Addmission
    patient_status_t  status;                      //Current  patient status(using enum inside struct)

}patient_t;

void display_menu();
void input_patient(patient_t *p );
void print_patient(patient_t *p);