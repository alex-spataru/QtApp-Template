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

## Modifying to suit your needs

1. Change to your preferred license.
2. Change the target & name of `*.pro` file.
3. Change [`info.plist`](deploy/macOS/info.plist).
4. Rename & change [`qt-app.desktop`](deploy/linux/qt-app.desktop).
5. Change [`setup.nsi`](deploy/windows/nsis/setup.nsi).
5. Modify env. variables of [`Build.yml`](.github/workflows/Build.yml).
6. Hack on...

## Default licence

This repository is comes by default with the [MIT License](LICENSE.md). You can change it for your own needs. You are welcome to star this repository to make it more visible to other Qt developers. Contributions welcome :)


