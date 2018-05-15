SUMMARY = "u-boot wic image"
LICENSE = "GPLv2+"
LIC_FILES_CHKSUM ?= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

FILES_${PN} += "/bootloader/zc702 /bootloader/zc706"
ALLOW_EMPTY_${PN} = "1"
FILESEXTRAPATHS_prepend := "${THISDIR}/:"
SRC_URI = "file://bootloader/zc702/boot_zc702.bin \
		file://bootloader/zc702/boot_zc702_adv7511.bin \
		file://bootloader/zc706/boot_zc706.bin \
		file://bootloader/zc706/boot_zc706_adv7511.bin \
"

inherit deploy

do_populate_lic[depends] = "${PN}:do_configure"

do_deploy () {
	install -d ${DEPLOYDIR}
	cp ${WORKDIR}/bootloader/zc706/boot_zc706.bin ${DEPLOYDIR}/boot.bin
	cp ${WORKDIR}/bootloader/zc706/boot_zc706.bin ${DEPLOYDIR}/boot_zc706.bin
	cp ${WORKDIR}/bootloader/zc706/boot_zc706_adv7511.bin ${DEPLOYDIR}/boot_zc706_adv7511.bin
	cp ${WORKDIR}/bootloader/zc702/boot_zc702.bin ${DEPLOYDIR}/boot_zc702.bin
	cp ${WORKDIR}/bootloader/zc702/boot_zc702_adv7511.bin ${DEPLOYDIR}/boot_zc702_adv7511.bin
}

addtask deploy before do_build after do_compile
