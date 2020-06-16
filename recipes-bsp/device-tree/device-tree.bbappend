WR_YAML_DT_xilinx-zynq = "${@bb.utils.contains('HDF_MACHINE','zc706-zynq7','BOARD zc706','BOARD zc702',d)}"
YAML_DT_BOARD_FLAGS_xilinx-zynq = "{${WR_YAML_DT}}"
YAML_KERNEL_VERSION_xilinx-zynq = "${@bb.utils.contains('HDF_MACHINE','zc706-zynq7','wrlinux-cicd-zc706','wrlinux-cicd-zc702',d)}"
XSCTH_PROC_xilinx-zynq ?= "ps7_cortexa9_0"

DEPENDS += "virtual/kernel"

do_configure_prepend_xilinx-zynq() {
    if [ -e ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION} ]; then
        rm -rf ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}
    fi
    mkdir -p ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/BOARD
    if [ "${HDF_MACHINE}" = "zc706-zynq7" ]; then
        cp ${STAGING_KERNEL_DIR}/arch/${ARCH}/boot/dts/zynq-zc706.dts ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/BOARD/zc706.dtsi
    sed -i '/dts-v1/d' ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/BOARD/zc706.dtsi
    fi
    if [ "${HDF_MACHINE}" = "zc702-zynq7" ]; then
        cp ${STAGING_KERNEL_DIR}/arch/${ARCH}/boot/dts/zynq-zc702.dts ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/BOARD/zc702.dtsi
    sed -i '/dts-v1/d' ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/BOARD/zc702.dtsi
    fi
    mkdir -p ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/zynq
    cp ${STAGING_KERNEL_DIR}/arch/${ARCH}/boot/dts/zynq-7000.dtsi ${S}/device_tree/data/kernel_dtsi/${YAML_KERNEL_VERSION}/zynq/
}

COMPATIBLE_MACHINE_xilinx-zynq = "xilinx-zynq"
