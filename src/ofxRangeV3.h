#ifdef PI
#define PI_TMP
#undef PI
#endif

#if defined(__cpp_lib_ranges) && __cpp_lib_ranges >= 201911L
    #include <ranges>
    namespace ranges = std::ranges;
#else
    #include <range/v3/all.hpp>
    //namespace ranges = ::ranges;
#endif

#pragma mark oF compatible

#ifndef PI
#   define PI       3.14159265358979323846
#endif
