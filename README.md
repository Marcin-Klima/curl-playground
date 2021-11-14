Prerequisites
=
1. conan installed (pip install --upgrade conan)

Linux install dependencies
=

conan install -s build_type=*Debug/Release* -if conanfiles/*buildtype* --build=missing --profile ./linux_conanprofile .
