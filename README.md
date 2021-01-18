<a href="#">
    <img width="192px" height="192px" src="doc/icon.svg" align="right" />
</a>

# Qt App Template

[![Build Status](https://github.com/alex-spataru/QtApp-Template/workflows/Build/badge.svg)](https://github.com/alex-spataru/QtApp-Template/actions)

A simple template for Qt apps with the following features:

- Code for displaying a QtQuick [`ApplicationWindow`](https://doc.qt.io/qt-5/qml-qtquick-controls2-applicationwindow.html).
- Automated [builds & artifact upload](https://github.com/alex-spataru/QtApp-Template/actions) for Windows, macOS & GNU/Linux.
- Comes with [issue templates](https://github.com/alex-spataru/QtApp-Template/issues/new/choose).
- [Code of conduct](CODE_OF_CONDUCT.md) file.
- Translation [template](assets/translations) files & [code](src/Translator.h).
- Deploy configuration for [Windows](deploy/windows), [macOS](deploy/macOS) & [GNU/Linux](deploy/linux).
- [NSIS installer](deploy/windows/nsis/setup.nsi) for Windows.
- Save window size, position & maximize status automatically.
- Load [`UI.qml`](assets/qml/UI.qml) asynchronously (to keep [`main.qml`](assets/qml/main.qml) small).
- Integration with [QSimpleUpdater](https://github.com/alex-spataru/QSimpleUpdater) & [CuteLogger](https://github.com/dept2/CuteLogger).
- `clang-format` integration.
- `.gitignore` file for Qt projects

**Note:** this repo does not make use of sub-modules because I modified CuteLogger to be able to compile directly with the application.

I made this repo to stop loosing time when I need to create a new project, it may or may not be updated frequently. If this project helped you, star this repository to make it more visible to other Qt developers. Contributions welcome :)

## Modifying the project to suit your needs

1. Change to your preferred license.
2. Rename the [`QtApp.pro`](QtApp.pro) file & change `TARGET` value.
3. Modify contents of [`AppInfo.h`](https://github.com/alex-spataru/QtApp-Template/blob/master/src/AppInfo.h).
4. Change [`info.plist`](deploy/macOS/info.plist).
5. Rename & change [`qt-app.desktop`](deploy/linux/qt-app.desktop).
6. Change [`setup.nsi`](deploy/windows/nsis/setup.nsi).
7. Modify env. variables of [`Build.yml`](.github/workflows/Build.yml).
8. Hack on...

## Default licence

This repository is comes by default with the [MIT License](LICENSE.md). You can change it for your own needs, I won't hold a grunge against you if you need a propietary license.
