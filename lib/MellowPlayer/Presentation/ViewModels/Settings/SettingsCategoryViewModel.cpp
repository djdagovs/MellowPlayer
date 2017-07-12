#include "SettingsCategoryViewModel.hpp"

using namespace MellowPlayer::Application;
using namespace MellowPlayer::Presentation;


SettingsCategoryViewModel::SettingsCategoryViewModel(SettingsCategory* settingsCategory, QObject* parent) :
        QObject(parent), settingsCategory(settingsCategory),
        settingsListModel(new SettingListModel(this, "name")) {
    if (settingsCategory != nullptr)
        for(Setting* setting: settingsCategory->getSettings())
            settingsListModel->append(settingModelFactory.create(*setting, this));
}

QString SettingsCategoryViewModel::getName() const {
    return settingsCategory != nullptr ? settingsCategory->getName() : "";
}

QString SettingsCategoryViewModel::getIcon() const {
    return settingsCategory != nullptr ? settingsCategory->getIcon() : "";
}

QString SettingsCategoryViewModel::getQmlComponent() const {
    return "qrc:/MellowPlayer/Presentation/Views/MellowPlayer/SettingsPages/AutomaticSettingsPage.qml";
}

SettingListModel* SettingsCategoryViewModel::getSettingsModel() {
    return settingsListModel;
}

void SettingsCategoryViewModel::restoreDefaults() {
    settingsCategory->restoreDefaults();
}

CustomSettingsCategoryViewModel::CustomSettingsCategoryViewModel(const QString& name, const QString& icon,
                                                         const QString& qmlComponent, QObject* parent):
    SettingsCategoryViewModel(nullptr, parent), name(name), icon(icon), qmlComponent(qmlComponent) {

}

QString CustomSettingsCategoryViewModel::getName() const {
    return name;
}

QString CustomSettingsCategoryViewModel::getIcon() const {
    return icon;
}

QString CustomSettingsCategoryViewModel::getQmlComponent() const {
    return qmlComponent;
}