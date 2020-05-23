#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x7b535e5, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x94c22b06, __VMLINUX_SYMBOL_STR(platform_device_unregister) },
	{ 0xe5c2420c, __VMLINUX_SYMBOL_STR(sysfs_remove_group) },
	{ 0x682d3945, __VMLINUX_SYMBOL_STR(input_unregister_device) },
	{ 0xab9825bb, __VMLINUX_SYMBOL_STR(input_register_device) },
	{ 0xabd092b8, __VMLINUX_SYMBOL_STR(input_set_abs_params) },
	{ 0x942c9f7d, __VMLINUX_SYMBOL_STR(input_allocate_device) },
	{ 0x435e19e1, __VMLINUX_SYMBOL_STR(sysfs_create_group) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x97376a78, __VMLINUX_SYMBOL_STR(platform_device_register_full) },
	{ 0x2fa1a0ce, __VMLINUX_SYMBOL_STR(input_event) },
	{ 0x20c55ae0, __VMLINUX_SYMBOL_STR(sscanf) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

