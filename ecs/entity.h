//
// Created by Gleb Obitotsky on 16.10.2026.
//
// Copyright 2026 Gleb Obitotsky,
//           2026 lighnd
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef LIGND_ENTITY_H
#define LIGND_ENTITY_H

#include <cstdint>
#include <array>

namespace ecs {
namespace entity {

enum class EntityError: uint8_t {
    InvalidIndex,
    VersionMismatch,
    PoolExhausted,
    DoubleDestroy
};

class [[nodiscard]] EntityID {
public:
    using Storage = uint32_t;

    static constexpr inline std::size_t kIndexBits = 20;
    static constexpr inline std::size_t kVersionBits = 12;

    static constexpr inline Storage IndexMask = (1 << kIndexBits) - 1;
    static constexpr inline Storage VersionMask = ((1 << kVersionBits) - 1) << kIndexBits;
    static constexpr inline Storage MaxVersion = (1 << kVersionBits) - 1;

private:
    std::array<uint16_t, MaxVersion> version_;
};

} // namespace entity
} // namespace ecs

#endif //LIGND_ENTITY_H
