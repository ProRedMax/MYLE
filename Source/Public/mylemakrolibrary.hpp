#pragma once


///
/// \brief pass values along without losing the fact that they are l-value or r-value references
///
#define FWD(...) ::std::forward<decltype(__VA_ARGS__)>(__VA_ARGS__)

#define noexcept_for(expression) noexcept(noexcept(expression))