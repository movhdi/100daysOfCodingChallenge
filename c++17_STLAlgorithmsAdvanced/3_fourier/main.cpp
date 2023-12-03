#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <iterator>
#include <numeric>
#include <valarray>
#include <vector>

using cmplx = std::complex<double>;
using csignal = std::vector<cmplx>;

class numIterator
{
private:
    size_t i;
public:
    numIterator(size_t position) : i(position) {}
    // operator *()
    size_t operator*() const
    {
        return this->i;
    }
    // operator ++
    numIterator operator++()
    {
        this->i++;
        return *this;
    }
    // operator !=
    bool operator!=(numIterator const &it) const
    {
        return it.i != this->i;
    }

};
/*
a possible implementation of std::transform is

template <typename InputIt, typename OutputIt, typename UnaryOperation>

OutputIt my_transform(InputIt first, InputIt last, OutputIt result, UnaryOperation op) {
    while (first != last) {
        *result++ = op(*first++);
    }
    return result;
}

here in our example we have implemented numIterator which returns a size_t once dereferenced!
to_ft() also takes a size_t as argument, this argument is passed to to_ft() inside the implementation of std::transform
here every to_ft() is itself a std::accumulate.
here is where a nested for loop takes place using algorithms!

*/
csignal fourier_transform(csignal const &s, bool back = false)
{
    csignal t(s.size());
    const double pol {2.0 * M_PI * (back ? -1.0 : 1.0)};
    const double div {back ? 1.0 : double(s.size())};
    auto sum_up([=, &s](size_t j){
        return [=, &s](cmplx c, size_t k){return c + s[k] * std::polar(1.0, pol * k * j / double(s.size()));};
    });
    auto to_ft([=, &s](size_t j){return std::accumulate(numIterator{0},numIterator{s.size()},cmplx{}, sum_up(j))/div;});
    std::transform(numIterator{0}, numIterator{s.size()},begin(t), to_ft);
    return t;
}

static auto gen_cosine(size_t period_length)
{
    return [period_length, n{0}]() mutable {return std::cos(double(n++) * 2 * M_PI / period_length);};
}

static auto gen_square_wave(size_t period_length)
{
    return [period_length, n{period_length*7/4}]() mutable {return ((n++ * 2 / period_length) % 2 ) * 2 - 1.0; };
}

template<typename F>
static csignal signal_from_generator(size_t length, F gen)
{
    csignal result(length);
    std::generate(std::begin(result), std::end(result), gen);
    return result;
}

static void print_signal(const csignal &input)
{
    auto real_part([](cmplx c){return c.real();});
    std::transform(std::begin(input), std::end(input), std::ostream_iterator<double>{std::cout, " "}, real_part);
    std::cout << '\n';
}



int main()
{
    const size_t signal_leng {100};
    auto cosine (signal_from_generator(signal_leng, gen_cosine(signal_leng/2)));
    auto square_wave (signal_from_generator(signal_leng, gen_square_wave(signal_leng)));
    auto trans_sqw(fourier_transform(square_wave));
    std::fill(std::next(std::begin(trans_sqw),10), std::prev(std::end(trans_sqw), 10), 0);
    auto mid(fourier_transform(trans_sqw, true));
    print_signal(cosine);
    print_signal(fourier_transform(cosine));
    print_signal(mid);
    print_signal(trans_sqw);
    print_signal(square_wave);
    print_signal(fourier_transform(square_wave));
    std::cout << M_PI << '\n';
}
