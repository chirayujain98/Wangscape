#pragma once

#include <spotify/json.hpp>

#include "noise/EncodedModuleGroup.h"
#include "noise/ModuleGroup.h"

namespace spotify
{
namespace json
{

template<>
struct default_codec_t<noise::EncodedModuleGroup>
{
    static codec::object_t<noise::EncodedModuleGroup> codec()
    {
        auto codec = codec::object<noise::EncodedModuleGroup>();
        codec.required("modules", &noise::EncodedModuleGroup::encodedModules);
        codec.optional("inputmodules",
                       [](const noise::EncodedModuleGroup& emg) { return emg.moduleGroup->mInputModules; },
                       [](noise::EncodedModuleGroup& emg,std::vector<noise::ModuleID> input_modules){ emg.moduleGroup->mInputModules = input_modules; });
        codec.optional("defaultoutputmodule",
                       [](const noise::EncodedModuleGroup& emg) { return emg.moduleGroup->mOutputModule; },
                       [](noise::EncodedModuleGroup& emg, noise::ModuleID output_module) { emg.moduleGroup->mOutputModule = output_module; });

        return codec;
    }
};

}
}
