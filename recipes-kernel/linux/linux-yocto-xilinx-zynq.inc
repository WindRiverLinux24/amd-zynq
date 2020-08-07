COMPATIBLE_MACHINE_xilinx-zynq = "xilinx-zynq"

KERNEL_DEVICETREE_xilinx-zynq = "zynq-zc706.dtb \
                                 zynq-zc702.dtb "

KERNEL_VERSION_SANITY_SKIP = "1"
SRCREV_machine_xilinx-zynq ?= "${AUTOREV}"
SRCREV_meta_xilinx-zynq ?= "${AUTOREV}"
