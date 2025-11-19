#include"patient_record.h"

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