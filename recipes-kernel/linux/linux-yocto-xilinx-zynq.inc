COMPATIBLE_MACHINE_xilinx-zynq = "xilinx-zynq"

KERNEL_DEVICETREE_xilinx-zynq = "zynq-zc706.dtb \
                                 zynq-zc702.dtb "

FILESEXTRAPATHS_prepend_xilinx-zynq := "${THISDIR}/files:"

SRC_URI_append_xilinx-zynq = " \
    file://0001-gcc-plugins-use-HOSTCXX-to-detect-the-designated-ini.patch \
"

KERNEL_VERSION_SANITY_SKIP = "1"
SRCREV_machine_xilinx-zynq ?= "${AUTOREV}"
SRCREV_meta_xilinx-zynq ?= "${AUTOREV}"
