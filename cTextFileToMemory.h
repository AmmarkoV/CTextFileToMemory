/** @file cTextFileToMemory.h
 *  @brief  A header only library that can help parsing text files 
 *  @author Ammar Qammaz (AmmarkoV)
 */
 
#ifndef BVH_INVERSEKINEMATICS_H_INCLUDED
#define BVH_INVERSEKINEMATICS_H_INCLUDED


#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define C_TEXTFILETOMEMORY_VERSION 0.0


struct cTextFileToMemory
{
  char * ptr;
  char * buffer;
  unsigned long   bufferSize;
  
  
  unsigned long   numberOfLines;
};


static unsigned char * ctftm_readFileToMemory(const char * filename,unsigned long *length)
{
    *length = 0;
    FILE * pFile = fopen ( filename , "rb" );

    if (pFile==0) { return 0; }

    // obtain file size:
    fseek (pFile , 0 , SEEK_END);
    unsigned long lSize = ftell (pFile);
    rewind (pFile);

    // allocate memory to contain the whole file:
    unsigned long bufferSize = sizeof(char)*(lSize+1);
    char * buffer = (char*) malloc (bufferSize);
    if (buffer == 0 ) { errno = ENOMEM; fclose(pFile); return 0; }

    // copy the file into the buffer:
    size_t result = fread (buffer,1,lSize,pFile);
    if (result != lSize)
    {
        free(buffer);
        fclose(pFile);
        return 0;
    }

    /* the whole file is now loaded in the memory buffer. */

    // terminate
    fclose (pFile);

    buffer[lSize]=0; //Null Terminate Buffer!
    *length = (unsigned int) lSize;
    return buffer;
}


static unsigned int ctftm_getline(struct cTextFileToMemory * ctftm)
{ 
    if (ctftm == NULL) 
    {
        errno = EINVAL;
        return -1;
    }
     
    char done = 0;
    
    char * ptr = ctftm->buffer;
    while (!done)
    { 
        switch (*ptr)
        {
          case 0   :                            done = 1; break;
          case 10  :  *ctftm->ptr=0;  done = 1; break;
          case 13  :  ctftm->numberOfLines+=1;  done = 1; break;
          case EOF :                            done = 1; break;
          
        };
        
      ++ptr;
    }
    
  return ctftm->numberOfLines;
}


static int ctftm_countNumberOfLines(struct cTextFileToMemory * ctftm)
{
    
    char * ptr = ctftm->buffer;
    char * limit = ptr + ctftm->bufferSize;
    
    
    while (ptr<limit)
    {
        switch (*ptr)
        {
          case 0   :                            break;
          case 10  :  ctftm->numberOfLines+=1;  break;
          case 13  :  ctftm->numberOfLines+=1;  break;  
          case EOF :                            break;
        };
        
        ++ptr; 
    }
  return ctftm->numberOfLines;
}


static int ctftm_loadTextFileToMemory(struct cTextFileToMemory * ctftm, const char * filename)
{
    if (ctftm==0)    { return 0; }
    if (filename==0) { return 0; }
    //----------------------------
    
    ctftm->buffer = ctftm_readFileToMemory(filename,&ctftm->bufferSize);
    ctftm->ptr    = ctftm->buffer;
    
     
    if (ctftm->buffer!=0)
    {
        
        ctftm_countNumberOfLines(ctftm);
        ssize_t read;
    
        int done=0;
        while  ( (!done) && ((read = ctftm_getline(ctftm)) != -1) ) 
        {
            
        }
    }
    
    return 0;
}



static unsigned int ctftm_getNumberOfRecords(struct cTextFileToMemory * ctftm)
{
   return 0; 
}

static char * ctftm_getRecords(struct cTextFileToMemory * ctftm,unsigned int record)
{
   return 0; 
}

#ifdef __cplusplus
}
#endif

#endif
