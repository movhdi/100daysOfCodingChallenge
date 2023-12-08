#include <numeric>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <iterator>
#include <complex>

using cmplx = std::complex<double>;
using serie = std::vector<cmplx>;

static auto scaler(int min_from, int max_from,
                   double min_to, double max_to)
{
    const int w_from {max_from - min_from};
    const double w_to {max_to - min_to};
    const int mid_from {w_from / 2.0 + min_from};
    const double mid_to {w_to / 2.0 + min_to};
    return [=](int from){return double(from - mid_from) / w_from * w_to + mid_to;};
}

template<typename A, typename B>
static auto scaled_cmplx(A scaler_x, B scaler_y)
{
    return [=](int x, int y){
        return std::complex<double>{scaler_x(x), scaler_y(y)};
    };
}

static auto mandlebrot_iterations(cmplx c)
{
    cmplx z;
    int max_iterations{1000};
    size_t iterations{};
    while (std::abs(z) < 2 && iterations < max_iterations)
    {
        ++iterations;
        z = std::pow(z , 2 ) + c;
    }
    return iterations;
}

int main()
{
    const size_t w{100};
    const size_t h{40};
    auto scale (scaled_cmplx(scaler(0,w,-2.0,1.0),scaler(0,h,-1.0, 1.0)));
    auto i_to_xy ([=](int i){return scale(i % w , i / w);});
    auto to_iteration_count ([=](int i){
        return mandlebrot_iterations(i_to_xy(i));
    });
    std::vector<int> v (w*h);
    std::iota(std::begin(v), std::end(v),0);
    std::transform(std::begin(v), std::end(v),std::begin(v), to_iteration_count);
    auto bin_func([w, n{0}](auto output_it, int x) mutable{
        ++output_it =(x > 50 ? '*' : ' ');
        if (++n %  w == 0)
        {
            ++output_it ='\n';
        }
        return output_it;
    });
    std::accumulate(std::begin(v), std::end(v), std::ostream_iterator<char>{std::cout}, bin_func);
}
