# include <iostream>
#include <algorithm>
#include <functional>
#include <array>
#include <string_view>
# include <cstdlib>
# include <string>
# include <chrono>
# include <cmath>
# include <vector>
# include <fstream>
# include <mpi.h>


int findmax (std::vector<int> s)
{
    int max=s[0];
    for(int i=0; i<s.size();i++)
    {
        if (s[i]>max) max=s[i];
    }
    return max;
}

int findmin (std::vector<int> s)
{
    int min=s[0];
    for(int i=0; i<s.size();i++)
    {
        if (s[i]<min) min=s[i];
    }
    return min;
}

std::vector<int> BucketSort(int nbp, std::vector<int> s,int rank)
{
    int BucketSize=s.size()/nbp;
    int max =findmax(s);
    int min = findmin(s);
    int pas = (max-min)/nbp;
    std::vector<int> Buckets[nbp];
    if (rank==0)
    {
        for(int i=0;i<s.size();i++)
        {
            for(int j=0; j<nbp;j++)
            {
                if(s[i]<min+j*pas)
                {
                   // &Buckets[j].pushback(s[i])
                }
            }
        }
    }








}
int main(int argc, char *argv[])
{
    int rank, nbp, lenres;
    char name[4096];
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nbp);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Get_processor_name(name, &lenres);
    printf("%d\n",nbp);


    std::vector<int> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
    
    for(int i=0; i<s.size();i++)
    {
        printf("%d,",s[i]);
    }
    printf("\n");
    std::sort(s.begin(),s.end());
    for(int i=0; i<s.size();i++)
    {
        printf("%d,",s[i]);
    }
    printf("\n");
    printf("yousk2\n");
    auto max = std::max_element(s.begin(), s.end());
    auto min = std::min_element(s.begin(), s.end());
    printf("%d",s[0]);
    MPI_Finalize();
    return 0;
}