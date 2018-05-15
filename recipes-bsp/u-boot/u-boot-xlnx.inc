require recipes-bsp/u-boot/u-boot.inc

DEPENDS += "dtc-native"

UBOOTURI ?= "git://github.com/Xilinx/u-boot-xlnx.git;protocol=https"
UBRANCH ?= "master"

UBRANCHARG = "${@['nobranch=1', 'branch=${UBRANCH}'][d.getVar('UBRANCH', True) != '']}"
SRC_URI = "${UBOOTURI};${UBRANCHARG}"
SRC_URI += "file://0001-net-Use-packed-structures-for-networking.patch"

S = "${WORKDIR}/git"
