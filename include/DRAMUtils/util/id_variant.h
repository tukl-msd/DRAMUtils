/*
 * Copyright (c) 2024, RPTU Kaiserslautern-Landau
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors:
 *    Marco Mörz
 */

#ifndef DRAMUTILS_UTIL_ID_VARIANT_H
#define DRAMUTILS_UTIL_ID_VARIANT_H

#include <variant>
#include <string_view>
#include <utility>
#include "types.h"
#include "nlohmann/json.hpp"

#define DRAMUTILS_DECLARE_IDVARIANT(VariantName, IDFieldName, VariantTypeSequence) \
    using VariantName = DRAMUtils::util::IdVariant<DRAMUtils::util::IDFieldName::name, VariantTypeSequence>;

namespace DRAMUtils::util
{

// uses select_tag and has_member defined by macro DRAMUTILS_DEFINE_IDFIELDNAME
template <char const * name, typename... Ts>
struct has_no_member_with_name {
    using tag = typename select_tag<name, void>::type;
    static constexpr bool value = !(has_member<Ts, tag>::value || ...);
};

template <char const * id_field_name, typename Seq, typename Enable = void>
class IdVariant
{
    static_assert(util::always_false<Seq>::value,
"Variant Types cannot have a member named id_field_name or 
DRAMUTILS_DEFINE_IDFIELDNAME macro is missing for the id_field_name"
    );
};

/**
 * @brief A variant that can be serialized to and from JSON with a field that determines the type.
 *          The macro call DRAMUTILS_DEFINE_IDFIELDNAME(id_field_name) in the global namespace is required for
 *          each different id_field_name used in the IdVariant. For an easier declaration use the macro
 *          DRAMUTILS_DECLARE_IDVARIANT(VariantName, IDFieldName, VariantTypeSequence)
 */
template<char const * id_field_name, typename... Ts>
class IdVariant<id_field_name, util::type_sequence<Ts...>, std::void_t<
    std::enable_if_t<has_no_member_with_name<id_field_name, Ts...>::value>
>>
{
private:
    using VariantTypes = util::type_sequence<Ts...>;
    using Variant = util::type_sequence_id_variant_t<VariantTypes>;
    using Json = nlohmann::json;
    Variant variant;

private:
    template <typename Seq>
    bool variant_from_json(const Json& j, util::type_sequence_id_variant_t<Seq>& data) {
        return variant_from_json_impl(j, data, Seq{}); // Seq{} needed for type deduction
    }

    template <typename... Types>
    bool variant_from_json_impl(const Json& j, util::type_sequence_id_variant_t<util::type_sequence<Types...>>& data, util::type_sequence<Types...>) {
        return ((j.at(id_field_name).get<std::string_view>() == Types::id && (data = j.get<Types>(), true)) || ...);
    }

public:
    // Compile time check for MemSpec type
    template<typename T>
    void setVariant(T&& variant) {
        static_assert(util::is_one_of<std::decay_t<T>, VariantTypes>::value, "Invalid Variant type!");
        this->variant = std::forward<T>(variant);
    }

    const Variant& getVariant() const {
        return variant;
    }

    Variant& getVariant() {
        return variant;
    }

public:
    void to_json(Json& j) const {
        std::visit(
            [&j](const auto& v) {
                // TODO Variant Types cannot have a member named id_field
                j = v;
                j[id_field_name] = v.id;
            },
        variant);
    }
    bool from_json(const Json& j) {
        return variant_from_json<VariantTypes>(j, variant);
    }
};

} // namespace DRAMUtils::util

#endif /* DRAMUTILS_UTIL_ID_VARIANT_H */
