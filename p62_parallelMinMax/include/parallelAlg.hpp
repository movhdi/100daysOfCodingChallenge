#include <utility>
#include <iterator>

template <typename FwdIt>
std::pair<typename std::iterator_traits<FwdIt>::value_type, typename std::iterator_traits<FwdIt>::value_type> parallelMinMax(FwdIt first, FwdIt last);
