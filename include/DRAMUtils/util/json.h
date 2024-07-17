/*
 * Copyright (c) 2021, RPTU Kaiserslautern-Landau
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
 *    Thomas Psota
 *    Derek Christ
 *    Marco Mörz
 */

#ifndef DRAMUTILS_UTIL_JSON_H
#define DRAMUTILS_UTIL_JSON_H

#include "nlohmann/json.hpp"

#include <optional>
#include <variant>
#include <string>

using json_t = nlohmann::json;

namespace DRAMUtils::util
{
// See https://www.kdab.com/jsonify-with-nlohmann-json/
// Try to set the value of type T into the variant data if it fails, do nothing
template<typename T, typename... Ts>
void variant_from_json(const nlohmann::json& j, std::variant<Ts...>& data)
{
    try
    {
        data = j.get<T>();
    }
    catch (...)
    {
    }
}

template <typename... Ts>
void variant_to_json(nlohmann::json& j, const std::variant<Ts...> &data)
{
    std::visit([&j](const auto& v) { j = v; }, data);
}


template <typename T>
void optional_to_json(nlohmann::json& j, const std::optional<T>& data, std::optional<std::string_view> key)
{
    if(key && data)
        j[*key] = *data;
    else if(data)
        j = *data;
}

template <class T>
void optional_from_json(const nlohmann::json& j, std::optional<T>& data, std::optional<std::string_view> key)
{
    if(key)
    {
        const auto it = j.find(*key);
        if (it != j.end())
            data = it->get<T>();
        else
            data = std::nullopt;
    }
    else
    {
        data = j.get<T>();
    }

}

template <typename>
constexpr bool is_optional = false;
template <typename T>
constexpr bool is_optional<std::optional<T>> = true;

template <typename>
constexpr bool is_variant = false;
template <typename... Ts>
constexpr bool is_variant<std::variant<Ts...>> = true;

} // namespace DRAMUtils::util

NLOHMANN_JSON_NAMESPACE_BEGIN

template <typename T> struct adl_serializer<std::optional<T>>
{
    static void to_json(json_t& j, const std::optional<T>& opt)
    {
        if (opt == std::nullopt)
        {
            j = nullptr;
        }
        else
        {
            j = *opt;
        }
    }

    static void from_json(const json_t& j, std::optional<T>& opt)
    {
        if (j.is_null())
        {
            opt = std::nullopt;
        }
        else
        {
            opt = j.get<T>();
        }
    }
};


#define NLOHMANN_JSONIFY_ALL_THINGS(Type, ...)                                                     \
    inline void to_json(nlohmann::json& nlohmann_json_j, const Type& nlohmann_json_t)              \
    {                                                                                              \
        NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(EXTEND_JSON_TO, __VA_ARGS__))                     \
    }                                                                                              \
    inline void from_json(const nlohmann::json& nlohmann_json_j, Type& nlohmann_json_t)            \
    {                                                                                              \
        NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(EXTEND_JSON_FROM, __VA_ARGS__))                   \
    }


NLOHMANN_JSON_NAMESPACE_END

#endif /* DRAMUTILS_UTIL_JSON_H */
