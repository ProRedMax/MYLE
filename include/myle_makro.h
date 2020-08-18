#pragma once

///
/// \brief pass values along without losing the fact that they are l-value or r-value references
///
#define MYLE_FWD(...) ::std::forward<decltype(__VA_ARGS__)>(__VA_ARGS__)

///
/// \brief You can use this if an exception is not thrown under a certaint condition/expression
///
#define MYLE_NOEXCEPT_FOR(expression) noexcept(noexcept(expression))

///
/// \brief You can you use AGAIN in your fori loop to skip the current iteration and redo it in the same index
///
#define MYLE_AGAIN(index) index--; continue;
