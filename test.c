#include <stdio.h>
#include "cTextFileToMemory.h"

int main(int argc,const char **argv)
{
    struct cTextFileToMemory ctftm;
    
    char filename[512]={0};
    snprintf(filename,512,"testList.txt");
    
    
     //Parse command-line arguments
     for (int i=0; i<argc; i++)
        { 
            if (strcmp(argv[i],"--from")==0)
                {
                    if(argc>i+1)
                    { 
                      snprintf(filename,512,"%s",argv[i+1]);
                    }
                }
        }
    
    
    
    
    
    fprintf(stderr,"Attempting to open file : %s\n",filename);
    if ( ctftm_loadTextFileToMemory(&ctftm,filename) )
    { 
      fprintf(stderr,"Found %u records in it\n",ctftm_getNumberOfRecords(&ctftm));
      for (int i=0; i<ctftm_getNumberOfRecords(&ctftm); i++)
      {
          fprintf(stderr,"Record %u = Value `%s`",i,ctftm_getRecords(&ctftm,i));
      }
    } else
    {
      fprintf(stderr,"Could not open file %s\n",filename);
    }
  
     
}
