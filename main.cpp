#include <iostream>

#include "replicant.hpp"
#include <vector>


template<class T>
void test(size_t size , T reset, T init )
{
     T tab[size+1];

     for(size_t i=0;i<(size+1);++i) tab[i]=reset;

     replicant<T>(&tab[0], &tab[size], init);

     if(tab[size]!=reset) 
     {
         dmesg("---- Error: last item ovverride !");
         for(size_t i=0;i<(size+1);++i) dmesg(  "item "<< i << " value=" <<  tab[i] );
         exit(1);
     } 

     for(size_t i=0;i<size;++i)
     if(tab[i]!=init)
     {
          dmesg("Error: index !" << i << " value=" <<  tab[i]);
          for(size_t i=0;i<(size+1);++i) dmesg(  "item "<< i << " value=" <<  tab[i] );
          exit(1);
     }

      
}


int main(int argc, char **argv) {

  typedef char TestType;

  std::vector<TestType> v(35);
  
  TestType* b = &v[0];
  TestType* e = b + 15;
  dmesg( "End address = " << (void*)e);

  while(b!=&v[v.size()]) { *b='X'; ++b; }
  b = &v[0];   
   
  replicant<TestType>(b,e,'A');

  for(size_t i=0;i<v.size();i++)
  {
      dmesg(i << " [" << v[i] << "] " << (void*)&v[i] );
  }

 for(size_t i=1;i<4000;i++)
 {  //  test<double>(i,1.0,3.0);
  test<char>(i,'X','A');
  test<int>(i,5,3);
  test<float>(i,5.0,3.2);
 }

    return 0;
}