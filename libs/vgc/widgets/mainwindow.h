// Copyright 2017 The VGC Developers
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

#ifndef VGC_WIDGETS_MAINWINDOW_H
#define VGC_WIDGETS_MAINWINDOW_H

#include <vgc/widgets/api.h>
#include <QMainWindow>

namespace vgc {

namespace core { class PythonInterpreter; }
namespace scene { class Scene; }

namespace widgets {

class VGC_WIDGETS_API MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(scene::Scene* scene,
               core::PythonInterpreter* interpreter,
               QWidget* parent = nullptr);

    ~MainWindow();

    scene::Scene* scene() const {
        return scene_;
    }

private:
    scene::Scene* scene_;

    // XXX move what's below out of MainWindow to keep it generic.
    // Specific content within the MainWindow should be in a
    // class such as "VgcIllustrationMainWindow".

    void createActions_();
    QAction* actionQuit_;

    void createMenus_();
    QMenu* menuFile_;
};

} // namespace widgets
} // namespace vgc

#endif // VGC_WIDGETS_MAINWINDOW_H