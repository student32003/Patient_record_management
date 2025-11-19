#include<stdio.h>
#include<stdint.h>


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

void input_patient(patient_t *p )
{
    printf("\n ==== ADD NEW PATIEN ===\n");

    printf("enter patient ID:\n");
    scanf("%d",&(*p).ID);
    getchar();

    printf("enter patient name:\n");
    scanf("%[^\n]", (*p).name);
    getchar();
   
    printf("enter patient age:\n");
    scanf("%d",&(*p).age);
    getchar();

    printf("enter patient disease:\n");
    scanf("%[^\n]", (*p).disease);
    getchar();

    printf("enter admission date (year month day):\n");
    scanf("%d %d %d",&(*p).addmission_date.year,
                     &(*p).addmission_date.month,
                          &(*p).addmission_date.day);
                          getchar();
   
    int status_choice;
    scanf("%d", &status_choice);
    getchar();
    
    if(status_choice == 0) 
    {
        (*p).status = STATUS_ADMITTED;
        printf(" status is : admitted\n",(*p).status);
    } 

    else if(status_choice == 1) 
    {
        (*p).status = STATUS_DISCHARGED;
        printf(" status is  : dicharged\n",(*p).status);
    } 
    else 
    {
        printf("\nInvalid choice! Setting to Admitted.\n");
        (*p).status = STATUS_ADMITTED;
        printf("%d",(*p).status);
    }
}

void print_patient(patient_t *p)
{
    printf("Patient record\n");
    printf(" ID is:%hu\n", (*p).ID);
    printf(" name is:%s\n", (*p).name);
    printf(" age is:%hhu\n", (*p).age);
    printf(" disease is:%s\n", (*p).disease);
    printf("admission date is: %hu-%hhu-%hhu\n", 
           (*p).addmission_date.year,
           (*p).addmission_date.month, 
           (*p).addmission_date.day);
    printf("status is : %s\n", ((*p).status == STATUS_ADMITTED) ? "Admitted" : "Discharged");
}


void display_menu()
{
    printf("===== PATIENT RECORD MANAGEMENT SYSTEM =======\n");
    printf("1. Add new patient \n");
    printf("2. Search Patient by ID  \n");
    printf("3. Search Patient by Name  \n");
    printf("4. Update Record  \n");
    printf("5. Discharge Patient \n");
    printf("6. List Patients \n");
    printf("7. Exit \n");


}


int main()
{
    //clrscr();
    patient_t patients;
    print_patient(&patients);
   int choice;
    
    do
    {
      display_menu(); 
      printf("enter the choice (1-7):\n");
      scanf("%d",&choice);
      switch(choice)
      {
        case 1:
               input_patient(&patients);
               break;
        case 2:
               
               break;
        case 3:
               
               break;
        case 4:
               
               break;
        case 5:
               
               break;
        case 6:
               print_patient(&patients);
               break;
        case 7:
               printf("exit\n");
               return 0;
        default:
                printf("enter valid choice\n");

      }

    }while(choice != 7);
    return 0;
}