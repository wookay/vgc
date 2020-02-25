// Copyright 2020 The VGC Developers
// See the COPYRIGHT file at the top-level directory of this distribution
// and at https://github.com/vgc/vgc/blob/master/COPYRIGHT
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

#ifndef VGC_UI_MOUSEEVENT_H
#define VGC_UI_MOUSEEVENT_H

#include <vgc/core/vec2f.h>
#include <vgc/ui/event.h>

namespace vgc {
namespace ui {

VGC_CORE_DECLARE_PTRS(MouseEvent);

/// \class vgc::ui::MouseEvent
/// \brief Class to handle mouse move, clicks, etc.
///
class VGC_UI_API MouseEvent : public Event
{  
    VGC_CORE_OBJECT(MouseEvent)

public:
    /// This is an implementation details. Please use
    /// MouseEvent::create() instead.
    ///
    MouseEvent(const ConstructorKey&, const core::Vec2f& pos);

public:
    /// Creates a MouseEvent.
    ///
    static MouseEventSharedPtr create(const core::Vec2f& pos);

    /// Returns the position of the mouse cursor, in local coordinates, when
    /// the event occurs.
    ///
    const core::Vec2f& pos() const
    {
        return pos_;
    }

    /// Returns the X-coordinate of the position of the mouse cursor, in local
    /// coordinates, when the event occurs. This is equivalent to `pos()[0]`.
    ///
    float x() const
    {
        return pos_[0];
    }

    /// Returns the Y-coordinate of the position of the mouse cursor, in local
    /// coordinates, when the event occurs. This is equivalent to `pos()[1]`.
    ///
    float y() const
    {
        return pos_[1];
    }

private:
    core::Vec2f pos_;
};

} // namespace ui
} // namespace vgc

#endif // VGC_UI_MOUSEEVENT_H
