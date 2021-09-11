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

#define C_TEXTFILETOMEMORY_VERSION 0.0


struct cTextFileToMemory
{
  unsigned char * buffer;
  unsigned long   bufferSize; 
};

static int loadTextFileToMemory(struct cTextFileToMemory * ctftm, const char * filename)
{
    
}

#ifdef __cplusplus
}
#endif

#endif
