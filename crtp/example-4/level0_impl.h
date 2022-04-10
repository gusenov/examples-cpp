#ifndef LEVEL0_IMPL_H
#define LEVEL0_IMPL_H

template<typename derived_t>
struct level0_impl
{
    auto const& derived() const
    {
        return static_cast<derived_t const&>(*this);
    }
};

#endif
