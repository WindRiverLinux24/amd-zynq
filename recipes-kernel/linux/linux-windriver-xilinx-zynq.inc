COMPATIBLE_MACHINE_xilinx-zynq = "xilinx-zynq"

KERNEL_DEVICETREE_xilinx-zynq = "zynq-zc706.dtb \
                                 zynq-zc702.dtb \
                                 zynq-zc702-adv7511.dtb \
                                 zynq-zc706-adv7511.dtb"

KERNEL_EXTRA_ARGS_append_xilinx-zynq = " LOADADDR=0x0008000"
KERNEL_CC_append_xilinx-zynq = " ${TOOLCHAIN_OPTIONS}"
