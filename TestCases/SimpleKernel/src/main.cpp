#include <iostream>
#include "cuda_profiler_api.h"
#include "GL/freeglut.h"
using namespace std;  
  
extern "C" 
  int func();

int main()  
{  
  //cudaProfilerStart();
  func();  
  cudaProfilerStop();
  return 0;  
}  