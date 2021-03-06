//
//  VROARTransparentShadow.h
//  ViroKit
//
//  Created by Raj Advani on 8/23/17.
//  Copyright © 2017 Viro Media. All rights reserved.
//

#ifndef VROARTShadow_h
#define VROARTShadow_h

#include <memory>

class VROMaterial;
class VROShaderModifier;

/*
 Apply this to any material to turn it into a "transparent shadow"
 material. These materials are transparent but able to receive shadows
 from the shadow-mapping system.
 
 They achieve this through a combination of shader modifiers that:
 
 1. Make the color of the surface black, with alpha 0,
 2. Increase the alpha if the surface is in shadow.
 
 This is used to cast virtual shadows on real-world scenes.
 */
class VROARShadow {
public:
    
    static void apply(std::shared_ptr<VROMaterial> material);
    static void remove(std::shared_ptr<VROMaterial> material);
    
private:
    
    static std::shared_ptr<VROShaderModifier> createSurfaceModifier();
    static std::shared_ptr<VROShaderModifier> createFragmentModifier();
    static std::shared_ptr<VROShaderModifier> createLightingModifier();
    
};

#endif /* VROARShadow_h */
