// Copyright (c) 2024 by Mathias Kraus <elboberido@m-hias.de>. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#include "iox/posh/experimental/runtime.hpp"

namespace iox::posh::experimental
{
RuntimeBuilder::RuntimeBuilder(const RuntimeName_t& name) noexcept
    : m_name(name)
{
}

expected<void, RuntimeBuilder::Error> RuntimeBuilder::create(optional<Runtime>& runtimeContainer) noexcept
{
    auto location = m_shares_process_with_roudi ? runtime::RuntimeLocation::SAME_PROCESS_LIKE_ROUDI
                                                : runtime::RuntimeLocation::SEPARATE_PROCESS_FROM_ROUDI;
    runtimeContainer.emplace(m_name, location);
    return ok();
}

Runtime::Runtime(const RuntimeName_t& name, runtime::RuntimeLocation location) noexcept
    : m_runtime(make_optional<const RuntimeName_t*>(&name), location)
{
}
} // namespace iox::posh::experimental
