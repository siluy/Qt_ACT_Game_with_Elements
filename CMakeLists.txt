cmake_minimum_required(VERSION 3.28)
project(qt_programming_2024)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(qt_programming_2024 src/main.cpp
        src/MyGame.cpp
        src/MyGame.h
        src/Items/Item.cpp
        src/Items/Item.h
        src/Items/Characters/Character.cpp
        src/Items/Characters/Character.h
        src/Items/Characters/Link.cpp
        src/Items/Characters/Link.h
        src/Items/Armors/Armor.cpp
        src/Items/Armors/Armor.h
        src/Items/HeadEquipments/HeadEquipment.cpp
        src/Items/HeadEquipments/HeadEquipment.h
        src/Items/LegEquipments/LegEquipment.cpp
        src/Items/LegEquipments/LegEquipment.h
        src/Items/HeadEquipments/CapOfTheHero.cpp
        src/Items/HeadEquipments/CapOfTheHero.h
        src/Items/Armors/OldShirt.cpp
        src/Items/Armors/OldShirt.h
        src/Items/LegEquipments/WellWornTrousers.cpp
        src/Items/LegEquipments/WellWornTrousers.h
        src/Scenes/Scene.cpp
        src/Scenes/Scene.h
        src/Scenes/BattleScene.cpp
        src/Scenes/BattleScene.h
        assets/assets.qrc
        src/Items/Maps/Map.cpp
        src/Items/Maps/Map.h
        src/Items/Maps/Battlefield.cpp
        src/Items/Maps/Battlefield.h
        src/Items/Mountable.cpp
        src/Items/Mountable.h
        src/Items/Armors/FlamebreakerArmor.cpp
        src/Items/Armors/FlamebreakerArmor.h
        src/Items/Gravity.h src/Items/Gravity.cpp

        src/Items/Blocks/Blocks.cpp src/Items/Blocks/Blocks.h
        src/Items/Blocks/Grassblock.h src/Items/Blocks/Grassblock.cpp
        src/Items/Maps/battlebackground.h src/Items/Maps/battlebackground.cpp
        src/Items/Blocks/Soilblock.h src/Items/Blocks/Soilblock.cpp
        src/Items/Blocks/Stoneblock.h src/Items/Blocks/Stoneblock.cpp
        src/Items/Blocks/Ironblock.h src/Items/Blocks/Ironblock.cpp
        src/Items/MeleeWeapons/MeleeWeapon.h src/Items/MeleeWeapons/MeleeWeapon.cpp
        src/Items/MeleeWeapons/IronShortSword.h src/Items/MeleeWeapons/IronShortSword.cpp
        src/Items/Characters/Rival.h src/Items/Characters/Rival.cpp
        src/Items/HeadEquipments/HairOfTheHero.h src/Items/HeadEquipments/HairOfTheHero.cpp
        src/Items/HealthBar.h src/Items/HealthBar.cpp
        src/Items/MeleeWeapons/WoodShortSword.h src/Items/MeleeWeapons/WoodShortSword.cpp
        src/Items/Throwable.h src/Items/Throwable.cpp
        src/Items/Bows/Bow.h src/Items/Bows/Bow.cpp
        src/Items/Bows/IronBow.h src/Items/Bows/IronBow.cpp
        src/Items/Arrows/Arrow.h src/Items/Arrows/Arrow.cpp
        src/Items/Arrows/NormalArrow.h src/Items/Arrows/NormalArrow.cpp
        src/Items/Arrows/FireArrow.h src/Items/Arrows/FireArrow.cpp
        src/Items/Conditions/Frozen.h src/Items/Conditions/Frozen.cpp
        src/Items/Conditions/Fire.h src/Items/Conditions/Fire.cpp
        src/Items/Conditions/Electrocuted.h src/Items/Conditions/Electrocuted.cpp
        src/Items/Conditions/Condition.h src/Items/Conditions/Condition.cpp
        src/Items/MeleeWeapons/FireSword.h src/Items/MeleeWeapons/FireSword.cpp
        src/Items/MeleeWeapons/IceSword.h src/Items/MeleeWeapons/IceSword.cpp
        src/Items/MeleeWeapons/ThunderSword.h src/Items/MeleeWeapons/ThunderSword.cpp
        src/Items/Arrows/IceArrow.h src/Items/Arrows/IceArrow.cpp
        src/Items/Arrows/ThunderArrow.h src/Items/Arrows/ThunderArrow.cpp
        src/Scenes/CommandDialog.h src/Scenes/CommandDialog.cpp)
target_link_libraries(qt_programming_2024
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

