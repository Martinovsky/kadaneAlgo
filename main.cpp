#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "kadane.hpp"

int main()
{
    // INIT vector with random values
    std::vector<int> randomVector(7);
    auto limitRand = [](int &number) { number = number % 100; };
    std::generate(randomVector.begin(), randomVector.end(), rand);
    std::for_each(randomVector.begin(), randomVector.end(), limitRand);
    const std::vector<int> test = randomVector;

    randomVector[1] *= -1;
    randomVector[3] *= -1;
    randomVector[6] *= -1;
    for (int value : randomVector)
    {
        std::cout << value << std::endl;
    }
    std::cout << "--------------" << std::endl;
    std::tuple<std::vector<int>::iterator, std::vector<int>::iterator, int> result = maxSubArray(randomVector);
    std::cout << "Max Sub Array is : [" << *(std::get<0>(result)) << ", " << *(std::get<1>(result)) << "] with a maximum of " << std::get<2>(result) << std::endl;
    return 0;
}
