// template<typename T>
// constexpr T&& my_forward(std::remove_reference_t<T>& t) noexcept
// {
//     return static_cast<T&&>(t);
// }

// template<typename T>
// constexpr T&& my_forward(std::remove_reference_t<T>&& t) noexcept
// {
//     static_assert(!std::is_lvalue_reference_v<T>);
//     return static_cast<T&&>(t);
// }