#!/usr/bin/env bash

touch ../include/oe/$1.hpp
mkdir ../include/oe/$1
touch ../include/oe/$1/$1.hpp

cat <<EOF > ../include/oe/$1.hpp
#pragma once

#include <oe/$1/$1.hpp>
EOF

cat <<EOF > ../include/oe/$1/$1.hpp
/**
 * @file $1.hpp
 * @brief
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
#pragma once

namespace oe {
} // namespace oe

EOF

cat <<EOF >> ../include/oe/oe/configs.h.in
\${define OE_${1^^}_ENABLED}
EOF

cat <<EOF >> ../xmake/libs.lua
    .. "$1;"
EOF

cat <<EOF >> ../include/oe/oe.hpp
#include <oe/$1.hpp>
EOF

cat <<EOF >> ../source/oe/$1.d
module oe.$1;

public:

EOF
