#include <hw04.h>

std::size_t hw04(const int* input_array, std::size_t elem_count)
{
    std::size_t sum = 0;
    std::size_t output_count=0;
    std::size_t output_size=1;
    std::size_t *output_data=new std::size_t[1];

    for(int i=0;i<elem_count;i++)
    {
        int elem=*(input_array+i);
        if(elem>0)
        {
            output_count++;
            if(output_count>output_size)
            {
                output_size++;
                std::size_t *new_output_data=new std::size_t[output_size];
                for(int j=0; j<output_size-1;j++)
                {
                    *(new_output_data+j)=*(output_data+j);
                }
                *(new_output_data+output_size-1)=elem;
                delete [] output_data;
                output_data=new_output_data;
                new_output_data=nullptr;
            }
            else
            {
                *(output_data+output_count-1)=elem;
            }
        }
        else if (elem<0)
        {
            break;
        }
    }
    for(int j=0; j<output_count;j++)
    {
        sum+=*(output_data+j);
    }
    delete [] output_data;
    return sum;
}
