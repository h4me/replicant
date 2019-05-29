#include <string.h>

#define dmesg(x) std::cout << x << std::endl;

template<class T>
size_t replicant(T* begin, T* end, T value)
{
          
          size_t i=1; 
 
          if(begin>=end) 
                     return 0;  
           
          *begin = value;
          
          for(i=1;(begin+i*2)<end;i<<=1)
          {
            //   dmesg("memcpy i="<< i << " bytes="<< i*sizeof(T)); 
               memcpy(begin+i, begin,i*sizeof(T));
          }
        
          
          if(begin+i<end)
          {
             memcpy(begin+i,begin,(end-(begin+i))*sizeof(T) );
          //   dmesg("rest copy bytes " << (end - (begin+i))*sizeof(T) );
         
          }

          return 0;

}