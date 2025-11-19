#include"patient_record.h"
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
