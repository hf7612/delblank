#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
  int sim_fd;
  int x, y;
  char buffer[10];
  /* Open the sysfs coordinate node */
  sim_fd = open("/sys/devices/platform/vms/coordinates", O_RDWR);
  if (sim_fd < 0) {
    perror("Couldn't open vms coordinate file\n");
    // exit(-1);
    return -1;
  }
  while (1) {
    /* Generate random relative coordinates */
    x = random()%20;
    y = random()%20;
    if (x%2) x = -x; if (y%2) y = -y;
    /* Convey simulated coordinates to the virtual mouse driver */
    sprintf(buffer, "%d %d %d", x, y, 0);
    write(sim_fd, buffer, strlen(buffer));
    fsync(sim_fd);
    sleep(1);
  }
  close(sim_fd);
}
// #include
// #include
// #include
// #include
// #include /home/user/y/ker.aosp/include/linux/platform_device.h
// #include <linux/input.h>
// #include <linux/platform_device.h>
// #include <linux/module.h> 
// struct input_dev *vms_input_dev;        /* Representation of an input device */
// static struct platform_device *vms_dev; /* Device structure */ /* Sysfs method to input simulated coordinates to the virtual mouse driver */
// static ssize_t write_vms(struct device *dev, struct device_attribute *attr, const char *buffer, size_t count) { int x,y;
//   sscanf(buffer, "%d%d", &x, &y); /* Report relative coordinates via the event interface */
//   input_report_rel(vms_input_dev, REL_X, x);
//   input_report_rel(vms_input_dev, REL_Y, y);
//   input_sync(vms_input_dev);
//   return count; } /* Attach the sysfs write method */
// DEVICE_ATTR(coordinates, 0644, NULL, write_vms); /* Attribute Descriptor */
// static struct attribute *vms_attrs[] = { &dev_attr_coordinates.attr, NULL }; /* Attribute group */
// static struct attribute_group vms_attr_group = { .attrs = vms_attrs, }; /* Driver Initialization */
// int __init vms_init(void) { /* Register a platform device */
//   vms_dev = platform_device_register_simple("vms", -1, NULL, 0); if (IS_ERR(vms_dev)) { PTR_ERR(vms_dev); printk("vms_init: error\n"); } /* Create a sysfs node to read simulated coordinates */
//   sysfs_create_group(&vms_dev->dev.kobj, &vms_attr_group); /* Allocate an input device data structure */
//   vms_input_dev = input_allocate_device(); if (!vms_input_dev) { printk("Bad input_alloc_device()\n"); } /* Announce that the virtual mouse will generate relative coordinates */
//   set_bit(EV_REL, vms_input_dev->evbit); set_bit(REL_X, vms_input_dev->relbit); set_bit(REL_Y, vms_input_dev->relbit); /* Register with the input subsystem */
//   input_register_device(vms_input_dev); printk("Virtual Mouse Driver Initialized.\n"); return 0; } /* Driver Exit */
// void vms_cleanup(void) { /* Unregister from the input subsystem */
//   input_unregister_device(vms_input_dev); /* Cleanup sysfs node */
//   sysfs_remove_group(&vms_dev->dev.kobj, &vms_attr_group); /* Unregister driver */
//   platform_device_unregister(vms_dev); return; } module_init(vms_init); module_exit(vms_cleanup);
//   MODULE_AUTHOR("FocalTech Driver Team"); MODULE_DESCRIPTION("FocalTech Touchscreen Driver"); MODULE_LICENSE("GPL v2");