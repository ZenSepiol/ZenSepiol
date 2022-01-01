template<typename T>
constexpr std::remove_reference_t<T>&& my_move(T&& t) noexcept
{
    return static_cast<std::remove_reference_t<T>&&>(t);
}