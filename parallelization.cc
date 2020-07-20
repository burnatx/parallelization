#include <iostream>
#include <omp.h>

#define n 1000

// Parallel function
void Parallelization(unsigned th)
{
    unsigned i;
    float a[th], b[th], c[th];
    #pragma omp parallel for shared(a, b, c) private(i)
    for(i=0;i<th;++i)
    {
        c[i] = a[i] + b[i];
    }
}

int main()
{
    cout<<"OpenMP Parallelization\n";
    Parallelization(n);

    return 0;
}
