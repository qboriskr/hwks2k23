# CPP homeworks 2023

1. helloworld - Github actions

2. homework02 - IP filters.
   
Переехал на новое оборудование и сломались все настройки для сборки.
Пришлось ставить заново clion, cmake, boost.
Чтобы всё заработало, нужно подбирать согласованные версии.
Например: cmake-3.25.3 и boost_1_81_0-msvc-14.3-64.exe.

Нужно указать все эти специфические настройки в окружении Windows:
BOOST_LIBRARYDIR=C:\WindowsKits\boost_1_81_0\lib64-msvc-14.3
BOOST_INCLUDEDIR=C:\WindowsKits\boost_1_81_0
BOOST_ROOT=C:\WindowsKits\boost_1_81_0
(да, выглядит странно что include совпадает с root).

И еще нужно в Clion добавить settings - Build Execution Deployment:
  Toolchains - добавить visual studio 2022.
  Cmake - прописать что используем вышеупомянутый visual studio и выбрать опцию Generator = Let cmake decide.
                                                                   
