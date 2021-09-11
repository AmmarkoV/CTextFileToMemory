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

#define C_TEXTFILETOMEMORY_VERSION 0.0


struct cTextFileToMemory
{
  unsigned char * buffer;
  unsigned long   bufferSize; 
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
    if (buffer == 0 ) { fclose(pFile); return 0; }

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

static int loadTextFileToMemory(struct cTextFileToMemory * ctftm, const char * filename)
{
    if (ctftm==0)    { return 0; }
    if (filename==0) { return 0; }
    //----------------------------
    
    ctftm->buffer = ctftm_readFileToMemory(filename,&ctftm->bufferSize);
    
    if (ctftm->buffer!=0)
    {
        
    }
    
    return 0;
}

#ifdef __cplusplus
}
#endif

#endif
