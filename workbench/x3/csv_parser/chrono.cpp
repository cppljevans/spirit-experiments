//Purpose:
//  Alternative to nonius.cpp to benchmark code.
//WHY:
//  gcc compiler trips over, IIRC, the concept class.
//  I guess gcc thinks it's a keyword.
//OriginalSource:
//  Attachments to post:
/*
http://boost.2283326.n4.nabble.com/Design-structure-X3-parser-more-like-Qi-parser-tp4690205p4690362.html
 */
//==========================
#include "bench_repeat.hpp"
#include <iostream>
#include <iomanip>
#include <locale>
#include <chrono>

int main()
{
    std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
    bool result=bench_repeat();
    std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();
    auto total_time=std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    double mean_time=double(total_time)/ITERATIONS;
    std::cout << "mean: " << mean_time << "ms" << std::endl;
  #ifdef BOOST_SPIRIT_PARSE_INTO_CONTAINER_BASE_IMPL_COUNT_PASS_FAIL
    unsigned constexpr setw=15;
    std::cout.imbue(std::locale(""));
    std::cout << "r_fail="<<std::setw(setw)<<boost::spirit::x3::traits::r_fail<<"\n";
    std::cout << "r_pass="<<std::setw(setw)<<boost::spirit::x3::traits::r_pass<<"\n";
  #endif//BOOST_SPIRIT_PARSE_INTO_CONTAINER_BASE_IMPL_COUNT_PASS_FAIL
    return int(!result);
}
