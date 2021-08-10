COMPATIBLE_MACHINE:xilinx-zynq = "xilinx-zynq"

KERNEL_DEVICETREE:xilinx-zynq = "zynq-zc706.dtb \
                                 zynq-zc702.dtb "

KERNEL_VERSION_SANITY_SKIP = "1"
SRCREV_machine:xilinx-zynq ?= "${AUTOREV}"
SRCREV_meta:xilinx-zynq ?= "${AUTOREV}"
