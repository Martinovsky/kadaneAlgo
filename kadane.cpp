#include "kadane.hpp"

std::tuple<std::vector<int>::iterator, std::vector<int>::iterator, int> maxSubArray(std::vector<int> &data)
{
    std::vector<int>::iterator left = data.begin();
    std::vector<int>::iterator right = left;
    int max = *left;
    if (data.empty())
    {
        return std::make_tuple(left, right, max);
    }

    int current = *left;
    std::vector<int>::iterator cLeft = left;
    for (std::vector<int>::iterator i = ++(data.begin()); i != data.end(); ++i)
    {
        if (*i > (current + *i))
        {
            current = *i;
            cLeft = i;
        }
        else
        {
            current += *i;
        }
        if (current > max)
        {
            max = current;
            left = cLeft;
            right = i;
        }
    }

    return std::make_tuple(left, right, max);
}